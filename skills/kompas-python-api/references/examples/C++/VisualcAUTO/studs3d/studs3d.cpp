// studs3d.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "studs3d.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//  Note!
//
//  If this DLL is dynamically linked against the MFC
//  DLLs, any functions exported from this DLL which
//  call into MFC must have the AFX_MANAGE_STATE macro
//  added at the very beginning of the function.
//
//  For example:
//
//  extern "C" BOOL PASCAL EXPORT ExportedFunction()
//    {
//      AFX_MANAGE_STATE(AfxGetStaticModuleState());
//      // normal function body here
//    }
//
//    It is very important that this macro appear in each
//    function, prior to any calls into MFC.  This means that
//    it must appear as the first statement within the 
//    function, even before any object variable declarations
//    as their constructors may generate calls into the MFC
//    DLL.
//
//    Please see MFC Technical Notes 33 and 58 for additional
//    details.
//

/////////////////////////////////////////////////////////////////////////////
// CStuds3dApp

BEGIN_MESSAGE_MAP(CStuds3dApp, CWinApp)
  //{{AFX_MSG_MAP(CStuds3dApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuds3dApp construction

CStuds3dApp::CStuds3dApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStuds3dApp object

CStuds3dApp theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

//-------------------------------------------------------------------------------
//
// ---
char * WINAPI LIBRARYNAME(){
  return "Крепежный элемент на Visual C++";
}

KompasObjectPtr kompas;
Shpeel* obj;

#define  MAX_COUNT_SPCOBJ 4     //максимальное число объектов СП за раз 4
static reference spcObj[MAX_COUNT_SPCOBJ];

#define STANDART_SECTION     25
#define SPC_NAME              5           // наименование

#define EPSILON    0.001
#define STUDS_FILE _T("stud.l3d|Шпильки|Шпилька_1")


//-------------------------------------------------------------------------------
//
// ---
void GetKompas() 
{
  if ( !kompas ) 
  {
    CString filename;
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
      filename.ReleaseBuffer( 255 );
      CString libname;

      #ifdef __LIGHT_VERSION__
        libname.LoadString( IDS_STRING5 );  //klAPI5.dll
      #else
        libname.LoadString( IDS_STRING4 );  //kAPI5.dll
      #endif

      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                        libname );

      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI5.dll
      if(  hAppAuto ) 
      {
        typedef LPDISPATCH ( WINAPI *FCreateKompasObject )(); 
        FCreateKompasObject pCreateKompasObject = 
          (FCreateKompasObject)GetProcAddress( hAppAuto, "CreateKompasObject" );  
        if ( pCreateKompasObject ) 
          kompas = IDispatchPtr(pCreateKompasObject(), false);
        FreeLibrary( hAppAuto );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) {
    Shpeel* par = new Shpeel();
    if ( par ) {
      // в конструкторе болта взводится ошибка в функции GetMacroParam
      kompas->ksResultNULL();
      ksDocument3DPtr doc( kompas->ActiveDocument3D() );
      if ( doc && !doc->IsDetail() ) 
        par->Draw3D( doc );
      else {
        CString mess;
        mess.LoadString( IDS_3DDOCERROR ); // Достать строку сообщения из ресурса
        kompas->ksError( (LPCTSTR)mess );            // выдать сообщение о ошибке
      }
      delete par;
    }
    if ( kompas->ksReturnResult() == etError10 )    //  10  "Ошибка! Вырожденный объект"
      kompas->ksResultNULL();
  }
}


////////////////////////////////////////////////////////////////////////////////
//
// Внекласные функции
//
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
// определяет является ли объект поверхностью: planar = true - плоскостью,
// false - конической поверхностью
// ---
bool IsSurface( ksEntityPtr& entity, bool planar = true )
{
  bool res = false;
  if ( entity ) 
  {
    if ( entity->IsIt(o3d_face) ) 
    {
      ksFaceDefinitionPtr faceDef( entity->GetDefinition() );
      if ( faceDef ) 
      {
        if ( planar && faceDef->IsPlanar() )
          res = true;

        if ( !planar && faceDef->IsCylinder() ) 
          res = true;
      }
    }
  }
  return res;
}

//------------------------------------------------------------------------------
// определяет является ли объект осью
// ---
bool IsAxis( ksEntityPtr& entity ) {
  if ( entity ) {
    return entity->IsIt( o3d_axis2Planes )        ||  // ось по двум плоскостям
             entity->IsIt( o3d_axisOperation )    ||  // ось операций
               entity->IsIt( o3d_axis2Points )    ||  // ось по двум точкам
                 entity->IsIt( o3d_axisConeFace ) ||  // ось конической поверхности
                   entity->IsIt( o3d_axisEdge );      // ось по ребру
  }
  return false;
}


//------------------------------------------------------------------------------
// Функция фильтр
// ---
bool WINAPI SELECTFILTERPROC( LPDISPATCH _entity ) 
{
  bool res = false;  
  ksEntityPtr entity( _entity );
  if ( entity ) 
  {
    ksPartPtr entPart( entity->GetParent() ); // Деталь присланного объекта
    if ( entPart != obj->GetPart() )      // Если деталь другая
      res = ::IsSurface( entity ) || 
            ::IsSurface( entity, false ) ||
            ::IsAxis( entity );           // Проверяем объект на принадлежность к
                                          // Плоскости, конической поверхности или оси
  }                                               

  return res;
}


//------------------------------------------------------------------------------
// Функция обратной связи
// 0 - плоскость, 1 - цилиндр, 2 - ось - состав collection
// ---
int WINAPI SELECTCALLBACKPROC( LPDISPATCH _entity, LPDISPATCH _info ) 
{
  int res = 0;
  ksEntityPtr entity( _entity );   
  ksRequestInfo3DPtr info( _info );

  if ( info ) 
  {
    ksEntityCollectionPtr collection( info->GetEntityCollection() );
    if ( entity )
    {
      if ( collection ) 
      {
        if ( ::IsSurface(entity) ) 
        {
          // При повторном указании объекта снимаем с него выбор
          ksEntityPtr oldPlane( collection->GetByIndex(0) );
          if ( oldPlane == entity )
            collection->SetByIndex( NULL, 0 );   // Обнулить плоскость
          else
            collection->SetByIndex( entity, 0 ); // Заменить плоскость
          res = 1;
        }
        else if ( ::IsSurface( entity, false ) ) 
        {
          // При повторном указании объекта снимаем с него выбор
          ksEntityPtr oldPlane( collection->GetByIndex(1) );
          if ( oldPlane == entity )
            collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
          else
          {
            collection->SetByIndex( entity, 1 ); // Заменить коническую плоскость
            collection->SetByIndex( NULL,   2 ); // Обнулить ось
          }
          res = 1;
        }
        else if ( ::IsAxis(entity) ) 
        {
          // При повторном указании объекта снимаем с него выбор
          ksEntityPtr oldAxis( collection->GetByIndex(2) );
          if ( oldAxis == entity )
            collection->SetByIndex( NULL, 2 );   // Обнулить ось
          else
          {
            collection->SetByIndex( entity, 2 ); // Заменить ось
            collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
          }

          res = 1;
        }

        if ( res )
          obj->GetCollectChanged() = true;

        CString mes;
        mes.LoadString( STR_SELECT_PLANE ); // Укажите точку привязки детали
        info->prompt = (LPCTSTR)mes;

      }
    }
    else 
    {
      if ( collection )
        for ( int i = 0; i < 3; i++ )
          collection->SetByIndex( NULL, i ); // Обнулить

        CString mes;
        mes.LoadString( STR_SELECT_PLANE ); // Укажите точку привязки детали
        info->prompt = (LPCTSTR)mes; 
        res = 1;
    }
  }

  return res;
}


//------------------------------------------------------------------------------
// добавить сопряжения
// ---
void AddMates( Shpeel& object, ksDocument3DPtr& doc, ksEntityCollectionPtr& collection ) {
  ksEntityPtr ent( collection->GetByIndex(0) );
  if ( ent && ::IsSurface(ent) ) {                   // поверхность
    ksEntityPtr partObj( NULL );
    object.GetEntityByName( _T("Plane"), partObj );
    if ( !doc->AddMateConstraint(mc_Coincidence, ent, partObj,
          object.GetDirectionElem(), 1, 0) ) {
      collection->SetByIndex( NULL, 0 );
    }
  }

  ent = collection->GetByIndex( 1 ); // использовать только оператор =
//  ent.AttachDispatch( collection->GetByIndex(1) ); использовать нельзя, т.к. стоит ASSERT(m_lpDispatch != NULL)
  if ( ent && ::IsSurface(ent, false/*planar*/) ) {  // коническая поверхность
    ksEntityPtr partObj( NULL );
    object.GetEntityByName(_T("Axis"), partObj );
    if ( !doc->AddMateConstraint(mc_Concentric, ent, partObj,
          0, 1, 0) ) {
      collection->SetByIndex( NULL, 1 );
    }
  }

  ent = collection->GetByIndex( 2 ); // использовать только оператор =
  if ( ent && ::IsAxis(ent) ) {                      // ось
    ksEntityPtr partObj( NULL );
    object.GetEntityByName(_T("Axis"), partObj );
    if ( !doc->AddMateConstraint(mc_Concentric, ent, partObj,
          0, 1, 0) ) {
      collection->SetByIndex( NULL, 2 );
    }
  }
}

//------------------------------------------------------------------------------
// удалить сопряжения
// ---
void DelMates( Shpeel& object, ksDocument3DPtr& doc, ksEntityCollectionPtr& collection ) {
  ksEntityPtr ent( collection->GetByIndex(0) );
  if ( ent && ::IsSurface(ent) ) {                   // поверхность
    ksEntityPtr partObj;
    object.GetEntityByName(_T("Plane"), partObj );
    doc->RemoveMateConstraint( mc_Coincidence, ent, partObj );
  }

  ent = collection->GetByIndex( 1 ); // использовать только оператор =
//  ent.AttachDispatch( collection->GetByIndex(1) ); использовать нельзя, т.к. стоит ASSERT(m_lpDispatch != NULL)
  if ( ent && ::IsSurface(ent, false/*planar*/) ) {  // коническая поверхность
    ksEntityPtr partObj( NULL );
    object.GetEntityByName(_T("Axis"), partObj );
    doc->RemoveMateConstraint( mc_Concentric, ent, partObj );
  }

  ent = collection->GetByIndex( 2 ); // использовать только оператор =
//  ent.AttachDispatch( collection->GetByIndex(2) ); использовать нельзя, т.к. стоит ASSERT(m_lpDispatch != NULL)
  if ( ent && ::IsAxis(ent) ) {                      // ось
    ksEntityPtr partObj( NULL );
    object.GetEntityByName(_T("Axis"), partObj );
    doc->RemoveMateConstraint( mc_Concentric, ent, partObj );
  }
}

//------------------------------------------------------------------------------
// заполняет адреса функций фильтра и обратной связи
// ---
void SetCallBackAndFilterFunction( ksRequestInfo3DPtr& info ) {
  info->SetFilterCallBackEx( _T("SELECTFILTERPROC"),   LONG_PTR(theApp.m_hInstance), 0 );
  info->SetCallBackEx      ( _T("SELECTCALLBACKPROC"), LONG_PTR(theApp.m_hInstance), 0 );
}


////////////////////////////////////////////////////////////////////////////////
//
// Класс шпильки - реализация
//
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
// Конструктор
// ---
Shpeel::Shpeel()  
  : part        ( NULL  ),
  doc           ( NULL  ),
  specification ( NULL  ),
  collect       ( NULL  ),
  param    ( kompas->GetParamStruct(ko_UserParam) ),
  paramTmp ( kompas->GetParamStruct(ko_UserParam) ),
  paramSTmp( kompas->GetParamStruct(ko_UserParam) ),
  data     ( kompas->DataBaseObject()             ),
  collectChanged( false ) {
  par.flagAttr    = 1;
  par.typeSwitch  = 0;
  par.ang         = 0;
  par.drawType    = ID_VID;
  countObj        = 1;

  InitUserParam();

  ::memset( &base.bg, 0, sizeof(ShpeelBase) );
  if( !GetParam() ) 
    Init();
  else {
    if ( !tmp.ver )
      tmp.ver = 1;
  }
}

//------------------------------------------------------------------------------
//
// ---
void Shpeel::Init() {
  tmp.gost       = (short)22032;
  par.drawType   = ID_VID;
  par.ang        = 0;
  tmp.f          = 0;
  tmp.f         |= TAKEISPOLN;
  tmp.d          = 20;
  tmp.p1         = 2.5;
  tmp.p2         = 1.5;
  tmp.c          = 2.5;
  tmp.indexMassa = 0;
  tmp.ver        = 1;
  tmp.b1         = 20;
  tmp.klass      = 2; /*klass=B*/
  tmp.l          = 90;
  tmp.b          = 46;
  tmp.m1         = (float)245.9;
  tmp.m2         = (float)228.9;
}

//------------------------------------------------------------------------------
// конструктор копий
// ---
Shpeel::Shpeel( const Shpeel& other ) 
  : param    ( kompas->GetParamStruct(ko_UserParam) ),
    paramTmp ( kompas->GetParamStruct(ko_UserParam) ),
    paramSTmp( kompas->GetParamStruct(ko_UserParam) ),
    collect  ( NULL                                ),
    data     ( kompas->DataBaseObject()                ) 
{
  openBase = false;
  ::memcpy( &base, &other.base, sizeof(ShpeelBase) );
  Assign( other );
  InitUserParam();
}

//------------------------------------------------------------------------------
// конструктор копии
// ---
Shpeel* Shpeel::Dublicate() {
  return new Shpeel( *this );
}

//------------------------------------------------------------------------------
//
// ---
void Shpeel::Assign( const Shpeel& other ) {
  collectChanged = other.collectChanged; // true - массив изменился
  countObj       = other.countObj;
  flagMode       = other.flagMode;
  par            = other.par;
  fileName       = other.fileName;
  ::memcpy( &tmp, &other.tmp, sizeof(SHPEEL) );
}

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
void Shpeel::_MessageBoxResult() {
  if ( kompas->ksReturnResult() ) {
    if ( kompas->ksReturnResult() == etError10 )    //  10  "Ошибка! Вырожденный объект"
      kompas->ksResultNULL();
    else
      kompas->ksMessageBoxResult();
  }
}

/*
struct ShpeelTmp {
  short t;   // флаг использовать запись или нет
  float d;   // диаметр резьбы
  float p1;  // шаг резьбы
  float p2;  // шаг резьбы
  float b1;  // ввинчиваемый конец
  float c;   // размер фаски
};
    lpShpeel->d  = shpeelTmp.d;    // диаметр резьбы
    lpShpeel->p1 = shpeelTmp.p1;   // шаг резьбы 
    lpShpeel->p2 = shpeelTmp.p2;   // шаг резьбы 
    lpShpeel->b1 = shpeelTmp.b1;   // ввинчиваемый конец
    lpShpeel->c  = shpeelTmp.c;    // размер фаски 
*/
//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( item && arr ) {
      paramTmp->Init();
      paramTmp->SetUserArray( arr );
      item->Init();
      item->shortVal = 0;            // 0 - t
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d;        // 1 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p1;       // 2 - p1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p2;       // 3 - p2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b1;       // 4 - b1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.c;        // 5 - c
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr item ( kompas->GetParamStruct(ko_LtVariant) );
    ksLtVariantPtr item1( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr   ( paramTmp->GetUserArray() );
    if ( item && item1 && arr 
          && arr->ksGetArrayCount() >= 6 ) {
      item->Init();
      arr->ksGetArrayItem( 1, item ); // d
      tmp.d = item->floatVal;
      arr->ksGetArrayItem( 2, item ); // p1
      tmp.p1 = item->floatVal;
      arr->ksGetArrayItem( 3, item ); // p2
      tmp.p2 = item->floatVal;
      arr->ksGetArrayItem( 4, item ); // b1
      tmp.b1 = item->floatVal;
      arr->ksGetArrayItem( 5, item ); // c
      tmp.c = item->floatVal;
    }
  }
}

/*
struct ShpeelSTmp {
  short t;   // флаг использовать запись или нет
  float l;   // длина шпильки
  float d;   // диаметр резьбы
  float b;   // гаечный конец
  float m1;  // масса исполнения 1
  float m2;  // масса исполнения 2
};
lpShpeel->d
  lpShpeel->l  = shpeelSTmp.l;
  lpShpeel->b  = shpeelSTmp.b;
  lpShpeel->m1 = shpeelSTmp.m1;
  lpShpeel->m2 = shpeelSTmp.m2;
*/
//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParamSTmp() {
  if ( paramSTmp ) {
    ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( item && arr ) {
      paramSTmp->Init();
      paramSTmp->SetUserArray( arr );
      item->Init();
      item->shortVal = 0;            // 0 - t
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.l;        // 1 - l
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d;        // 2 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b;        // 3 - b
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m1;       // 4 - m1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m2;       // 5 - m2
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParamSTmp() {
  if ( paramSTmp ) {
    ksLtVariantPtr    item ( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr   ( paramSTmp->GetUserArray() );
    if ( item && arr 
          && arr->ksGetArrayCount() >= 6 ) {
      item->Init();
      arr->ksGetArrayItem( 1, item ); // l
      tmp.l = item->floatVal;
      arr->ksGetArrayItem( 2, item ); // d
      tmp.d = item->floatVal;
      arr->ksGetArrayItem( 3, item ); // s
      tmp.b = item->floatVal;
      arr->ksGetArrayItem( 4, item ); // m1
      tmp.m1 = item->floatVal;
      arr->ksGetArrayItem( 5, item ); // m2
      tmp.m2 = item->floatVal;
    }
    if ( tmp.gost > 22041 ) {
      if ( ::fabs(tmp.b) > 0.001 ) 
        tmp.f &=~ ALLST;
      else 
        tmp.f |= ALLST;
    }
  }
}

//------------------------------------------------------------------------------
//
// ---
static  void NumberGost( int gost, int *gNumb, int *stNumb ) {
  switch ( gost ) {
    case 22032 : *gNumb = STR_200; *stNumb = STR_220; break;
    case 22033 : *gNumb = STR_201; *stNumb = STR_221; break;
    case 22034 : *gNumb = STR_202; *stNumb = STR_222; break;
    case 22035 : *gNumb = STR_203; *stNumb = STR_223; break;
    case 22036 : *gNumb = STR_204; *stNumb = STR_224; break;
    case 22037 : *gNumb = STR_205; *stNumb = STR_225; break;
    case 22038 : *gNumb = STR_206; *stNumb = STR_226; break;
    case 22039 : *gNumb = STR_207; *stNumb = STR_227; break;
    case 22040 : *gNumb = STR_208; *stNumb = STR_228; break;
    case 22041 : *gNumb = STR_209; *stNumb = STR_229; break;
    case 22042 : *gNumb = STR_210; *stNumb = STR_230; break;
    case 22043 : *gNumb = STR_211; *stNumb = STR_231; break;
  }
}

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
static int GetFullName( LPCTSTR name, TCHAR *fName  ) {
  CString bufName( name );    // буфер из которого будем все доставать
  CString path;               // полный путь к файлу
  CString modelName;          // разделы и подразделы в библ-ке моделей
  bool rez = false;           // результат
  if( ::GetModuleFileName(theApp.m_hInstance, fName, 255) ) { // путь к нашему rtw
    int ind   = bufName.Find( '|' ); // ищем позицию с кот. нач-ся разделы          
    if ( ind > 0 )                   // если раздел найден - копируем путь внутри библ-ки в буфер
      modelName = bufName.Right( bufName.GetLength() - ind );

    CString fileName( ind > 0 ? bufName.Left(ind) : bufName ); // имя файла без разделов
    if ( !fileName.IsEmpty() ) {
      TCHAR *c = ::_tcsrchr( fName, _T('\\') ); // путь к rtw     
      if ( c ) {
        *(c + 1) = _T('\0');                 // отсекаем имя файла rtw
        path  = fName;                   // формируем путь в корень
        path += fileName;

        OFSTRUCT ofs;
        if ( ::OpenFile(_bstr_t(path), &ofs, OF_EXIST) != HFILE_ERROR ) // проверка файла
          rez = true;                    // файл найден
        else {                           // файл не найден
          *(c + 1) = _T('\0');               // отсекаем имя файла
          path = fName;                  // формируем путь в поддиректорию LOAD
          path += _T("LOAD\\");
          path += fileName;
          if ( ::OpenFile(_bstr_t(path), &ofs, OF_EXIST) != HFILE_ERROR ) // проверка файла
            rez = true;                  // файл найден
        }
      }
    }
  }
  if ( rez ) {                           // файл найден
    ::_tcscpy_s( fName, 255, path );     // формируем полный путь
    ::_tcscat_s( fName, 255, modelName );
  }
  return rez;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
int Shpeel::_ConnectDB( reference bd, LPCTSTR name ) {
  TCHAR buf[_MAX_PATH];
  return ::GetFullName( name, buf ) ? data->ksConnectDB( bd, buf  ) 
                                    : data->ksConnectDB( bd, name );
}

//------------------------------------------------------------------------------
// Открытие БД и создание отношений к БД
// ---
bool Shpeel::OpenBase( bool initParam ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  if ( initParam ) {
    InitUserParamTmp();
    InitUserParamSTmp();
  }

  if ( data ) {
    CString buf;
    buf.LoadString( BASE_STR1 ); //
    base.bg = data->ksCreateDB( (LPCTSTR)buf );   // TXT_DB
    base.bs = data->ksCreateDB( (LPCTSTR)buf );   // TXT_DB

    int gNumb, stNumb;
    ::NumberGost( tmp.gost, &gNumb, &stNumb );

    buf.LoadString( gNumb ); //
    if( _ConnectDB(base.bg, (LPCTSTR)buf) ) { //"22032.loa"
      buf.LoadString( stNumb ); //
      if( _ConnectDB(base.bs, (LPCTSTR)buf) ) { //"st22032.loa"
        buf.LoadString( STR_241 ); //
        base.rg1 = data->ksRelation( base.bg );
          data->ksRInt ( _T("t") );
          data->ksRChar( _T("d"), 20, 0 );
        data->ksEndRelation();
        if ( data->ksDoStatement(base.bg, base.rg1, (LPCTSTR)buf) ) { //"1"
          base.rg2 = data->ksRelation( base.bg );
            data->ksRInt  ( _T("t") );
            data->ksRFloat( _T("d") );
            data->ksRFloat( _T("") );
            data->ksRFloat( _T("") );
            data->ksRFloat( _T("") );
            data->ksRFloat( _T("") );
          data->ksEndRelation();
          if ( data->ksDoStatement(base.bg, base.rg2, _T("")) ) { //TXT_ALL
            buf.LoadString( STR_243 ); //
            base.rs1 = data->ksRelation( base.bs );
              data->ksRInt  ( _T("t") );
              data->ksRChar ( _T("L"), 20, 0 );
              data->ksRFloat( _T("d") );
            data->ksEndRelation();
            if ( data->ksDoStatement(base.bs, base.rs1, (LPCTSTR)buf) ) { //"1 2"
              base.rs2 = data->ksRelation( base.bs );
                data->ksRInt  ( _T("t") );
                data->ksRFloat( _T("L") );
                data->ksRFloat( _T("d") );
                data->ksRFloat( _T("") );
                data->ksRFloat( _T("") );
                data->ksRFloat( _T("") );
              data->ksEndRelation();
              if ( data->ksDoStatement(base.bs, base.rs2, _T("") ) ) { // TXT_ALL
                openBase = true;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Закрытие БД
// ---
void Shpeel::CloseBase() {
  if ( base.bg ) {
    data->ksDeleteDB( base.bg );
    base.bg = 0;
  }
  if ( base.bs ) {
    data->ksDeleteDB( base.bs );
    base.bs = 0;
  }
  openBase = false;
}

//------------------------------------------------------------------------------
// Чтение БД
// ---
int Shpeel::ReadShpeelBase( float d ) {
  CString  buf;
  TCHAR s[128];
  buf.LoadString( STR_245 ); //
  ::_stprintf_s( s, buf, d );   //"d=%.0f"
  if ( data->ksCondition(base.bg, base.rg2, s) ) { 
    if ( data->ksReadRecord(base.bg, base.rg2, paramTmp) ) {
      GetUserParamTmp();
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
//  Читать параметры стержня
//  возвращает 1 - успех 0 - не найдено записи -1 - ошибка связи с БД
// ---
int Shpeel::ReadShpeelStBase() {
  CString  buf;
  TCHAR buf1[128];
  buf.LoadString( STR_246 ); //
  ::_stprintf_s( buf1, buf, tmp.l, tmp.d );  // "L=%.0f && d=%.0f"

  if ( !data->ksCondition(base.bs,  base.rs2, buf1) ) { return -1; }
  int i = data->ksReadRecord( base.bs, base.rs2, paramSTmp );
  if ( !i )  {
    buf.LoadString( STR_245 ); //
    ::_stprintf_s( buf1, buf, tmp.d);   //" d=%.0f "

    if ( !data->ksCondition(base.bs,  base.rs2, buf1) ) { return -1;}
    data->ksReadRecord( base.bs, base.rs2, paramSTmp );
  }
  GetUserParamSTmp();
  return 1;
}

/*
  float          ang;
  unsigned short flagAttr;
  short          drawType;
  BYTE           typeSwitch;  // тип запроса положения базовой точки элемента 0 Placement 1 Curso

  float d;          // диаметр резьбы
  float p1;         // шаг резьбы
  float p2;         // шаг резьбы
  float b1;         // ввинчиваемый конец  l1
  float c;          // размер фаски
  float l;          // длина шпильки
  float b;          // гаечный конец  l0
  short f;          // битовые маски
  short klass;      // класс точности
  short gost;       // номер госта
  short ver;        // версия макро
  float m1;         // масса 1 исполнение
  float m2;         // масса 2 исполнение
  short indexMassa; // 0-металл 1- алюмин сплав 3-бронза 2-латунь
*/
//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParam() {
  if ( param ) {
    ksLtVariantPtr      item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( item && arr ) {
      param->Init();
      param->SetUserArray( arr );
      item->Init();
      item->floatVal = par.ang;        // 0 - ang
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.flagAttr;   // 1 - flagAttr
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.drawType;   // 2 - drawType
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.typeSwitch; // 3 - typeSwitch
      arr->ksAddArrayItem( -1, item );

      item->floatVal = tmp.d;          // 4 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p1;         // 5 - p1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p2;         // 6 - p2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b1;         // 7 - b1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.c;          // 8 - c
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.l;          // 9 - l
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b;          // 10 - b
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.f;          // 11 - f
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.klass;      // 12 - klass
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.gost;       // 13 - gost
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.ver;        // 14 - ver
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m1;         // 15 - m1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m2;         // 16 - m2
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.indexMassa; // 17 - indexMassa
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::SetUserParam() {
  if ( param ) {
    ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( param->GetUserArray() );
    if ( item && arr && arr->ksGetArrayCount() >= 18 ) {
      item->Init();
      item->floatVal = par.ang;        // 0 - ang
      arr->ksSetArrayItem( 0, item );
      item->shortVal = par.flagAttr;   // 1 - flagAttr
      arr->ksSetArrayItem( 1, item );
      item->shortVal = par.drawType;   // 2 - drawType
      arr->ksSetArrayItem( 2, item );
      item->shortVal = par.typeSwitch; // 3 - typeSwitch
      arr->ksSetArrayItem( 3, item );

      item->floatVal = tmp.d;          // 4 - d
      arr->ksSetArrayItem( 4, item );
      item->floatVal = tmp.p1;         // 5 - p1
      arr->ksSetArrayItem( 5, item );
      item->floatVal = tmp.p2;         // 6 - p2
      arr->ksSetArrayItem( 6, item );
      item->floatVal = tmp.b1;         // 7 - b1
      arr->ksSetArrayItem( 7, item );
      item->floatVal = tmp.c;          // 8 - c
      arr->ksSetArrayItem( 8, item );
      item->floatVal = tmp.l;          // 9 - l
      arr->ksSetArrayItem( 9, item );
      item->floatVal = tmp.b;          // 10 - b
      arr->ksSetArrayItem( 10, item );
      item->shortVal = tmp.f;          // 11 - f
      arr->ksSetArrayItem( 11, item );
      item->shortVal = tmp.klass;      // 12 - klass
      arr->ksSetArrayItem( 12, item );
      item->shortVal = tmp.gost;       // 13 - gost
      arr->ksSetArrayItem( 13, item );
      item->shortVal = tmp.ver;        // 14 - ver
      arr->ksSetArrayItem( 14, item );
      item->floatVal = tmp.m1;         // 15 - m1
      arr->ksSetArrayItem( 15, item );
      item->floatVal = tmp.m2;         // 16 - m2
      arr->ksSetArrayItem( 16, item );
      item->shortVal = tmp.indexMassa; // 17 - indexMassa
      arr->ksSetArrayItem( 17, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParam() {
  if ( param ) {
    ksLtVariantPtr      item ( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr   ( param->GetUserArray() );
    if ( item && arr && arr->ksGetArrayCount() >= 18 ) {
      item->Init();
      arr->ksGetArrayItem( 0, item );
      par.ang = item->floatVal;
      arr->ksGetArrayItem( 1, item );
      par.flagAttr = item->shortVal;
      arr->ksGetArrayItem( 2, item );
      par.drawType = item->shortVal;
      arr->ksGetArrayItem( 3, item );
      par.typeSwitch = (BYTE)item->shortVal;

      arr->ksGetArrayItem( 4, item );
      tmp.d = item->floatVal;
      arr->ksGetArrayItem( 5, item );
      tmp.p1 = item->floatVal;
      arr->ksGetArrayItem( 6, item );
      tmp.p2 = item->floatVal;
      arr->ksGetArrayItem( 7, item );
      tmp.b1 = item->floatVal;
      arr->ksGetArrayItem( 8, item );
      tmp.c = item->floatVal;
      arr->ksGetArrayItem( 9, item );
      tmp.l = item->floatVal;
      arr->ksGetArrayItem( 10, item );
      tmp.b = item->floatVal;
      arr->ksGetArrayItem( 11, item );
      tmp.f = item->shortVal;
      arr->ksGetArrayItem( 12, item );
      tmp.klass = item->shortVal;
      arr->ksGetArrayItem( 13, item );
      tmp.gost = item->shortVal;
      arr->ksGetArrayItem( 14, item );
      tmp.ver = item->shortVal;
      arr->ksGetArrayItem( 15, item );
      tmp.m1 = item->floatVal;
      arr->ksGetArrayItem( 16, item );
      tmp.m2 = item->floatVal;
      arr->ksGetArrayItem( 17, item );
      tmp.indexMassa = item->shortVal;
    }
  }
}

//------------------------------------------------------------------------------
//
// ---
int Shpeel::GetParam() {
  if ( part ) {
    part->GetUserParam( param );
    GetUserParam();
    return 1;
  }
  return 0; 
}

//-------------------------------------------------------------------------------
// находит у детали поверхность с заданным именем
// ---
void Shpeel::GetEntityByName( LPCTSTR name, ksEntityPtr& entity ) {
  entity= NULL;
  if ( part ) {
    if ( !collect )  // массив лежит в классе, и если он ещё не создан - создаём
      collect = part->EntityCollection(o3d_constrElement);

    ksEntityPtr findEntity( collect->GetByName(name, true, true) );
    if ( findEntity ) 
      entity = findEntity;
  }
}


//-------------------------------------------------------------------------------
// Массив пуст - указали placement
// ---
bool Shpeel::IsCollectionEmpty( ksRequestInfo3DPtr& info ) 
{
  bool res = true;
  ksEntityCollectionPtr collection( info->GetEntityCollection() ); // Новый массив
  if ( collection )
    for( int i = 0, count = collection->GetCount(); i < count; i++ ) // Цикл по массиву
    {       
      ksEntityPtr ent( collection->GetByIndex(i) );        // Текущий элемент
      if ( ent )                          // Если он не NULL
      {                        
        res = false;                                   // Массив не пуст
        break;                                         // Завершить цикл
      }
    }
  return res; 
}


//-------------------------------------------------------------------------------
//
// ---
bool Shpeel::IsCollectionChange( ksRequestInfo3DPtr& info ) 
{
  bool res = true;                                     
  if ( !collectChanged ) // Если новые объекты не указывали - сравниваем массивы
  {                             
    // Возможен вариант когда указали точку и массив в info заполнен NULL'ми а старый нет
    res = false; // Не надо перестраивать
    ksEntityCollectionPtr collection1( info->GetEntityCollection() ); // Новый массив
    ksEntityCollectionPtr collection2( part->GetMateConstraintObjects() ); // Старый массив
    if ( collection1 && collection2 && 
         ( collection1->GetCount() > 2 ) && (collection2->GetCount() > 2) ) 
    {
      for( int i = 0; i < 3; i++ ) // Цикл по массивам
      {                        
        ksEntityPtr ent1( collection1->GetByIndex(i) );   // Текущий элемент 1
        ksEntityPtr ent2( collection2->GetByIndex(i) );   // Текущий элемент 2
        if ( ent1 != ent2 ) // Если они не равны 
        {     
          res = true;                                 // Перестраиваем
          break;                                      // Завершить цикл
        }
      }
    }
  }
  return res; 
}


//-------------------------------------------------------------------------------
//
// ---
void Shpeel::SetMates( ksDocument3DPtr& doc, ksRequestInfo3DPtr& info, bool delMates ) 
{
  ksEntityCollectionPtr collection( !delMates ? info->GetEntityCollection()
                                             : part->GetMateConstraintObjects() );
  if ( collection ) 
  {
    if ( doc && collection->GetCount() > 2 )
      if ( !delMates )
        ::AddMates( *this, doc, collection );
      else
        ::DelMates( *this, doc, collection );

    if ( !delMates )
      part->SetMateConstraintObjects( collection );
  }
}


//-------------------------------------------------------------------------------
// Заполняет адреса функций фильтра и обратной связи
// ---
void Shpeel::SetCallBackAndFilterFunction( ksRequestInfo3DPtr& info )
{
  ::SetCallBackAndFilterFunction( info );
}


//------------------------------------------------------------------------------
//
// ---
reference  Shpeel::EditSpcObj( reference *spcObj )
{
  ksUserParamPtr par1( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( !par1 || !item || !arr )
    return 0;

  par1->Init();
  par1->SetUserArray( arr );
  item->Init();

  if ( !flagMode && !par.flagAttr && !specification )
    return 0;

  if ( flagMode ) 
  {
    *spcObj = specification->D3GetSpcObjForGeomWithLimit( _T(""),          // Имя библиотеки типов
                                                         0,                // Номер типа спецификации
                                                         part,
                                                         1,                // 1 - первый объект 0 - следующий объект                                                  
                                                         STANDART_SECTION, // Номер раздела
                                                         81764182256.0 );
    if( !par.flagAttr )
      return *spcObj;


    if ( *spcObj && !specification->ksSpcObjectEdit( *spcObj ) )
      *spcObj  = 0;
  }
  bool flagMode = *spcObj ? true : false;
  if ( flagMode || specification->ksSpcObjectCreate(_T(""),       // Имя библиотеки типов
                                            0,                    // Номер типа спецификации
                                            STANDART_SECTION, 0,  // Номер раздела и подраздела
                                            81764182256.0, 0) )   // Тип атрибута
  {
   // Исполнение
   unsigned int uBuf = !!(tmp.f & ISPOLN );
   specification->ksSpcVisible( SPC_NAME, 2, uBuf );
   if ( uBuf ) {
     arr->ksClearArray();
     item->uIntVal = 2;
     arr->ksAddArrayItem( -1, item );
     specification->ksSpcChangeValue( SPC_NAME, 2, par1, UINT_ATTR_TYPE );
   }

   // Изменим диаметр
   arr->ksClearArray();
   item->floatVal = tmp.d;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME, 4, par1, FLOAT_ATTR_TYPE  );

   // Отследим мелкий шаг
   uBuf = !(tmp.f & PITCHOFF  || !(tmp.f &PITCH));
   specification->ksSpcVisible( SPC_NAME, 5, uBuf );
   specification->ksSpcVisible( SPC_NAME, 6, uBuf ); // Шаг
   if( uBuf ) // Выключить шаг и его разделитель
   {
     arr->ksClearArray();
     item->floatVal = tmp.p2;
     arr->ksAddArrayItem( -1, item );
     specification->ksSpcChangeValue( SPC_NAME, 6, par1, FLOAT_ATTR_TYPE );
   }

   // Изменим длину
   arr->ksClearArray();
   item->uIntVal = (unsigned int)tmp.l;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 9, par1, UINT_ATTR_TYPE  );

   if ( !flagMode ) 
   {
     specification->ksSpcVisible( SPC_NAME, 7,  0 ); // Выключим поле допуска
     specification->ksSpcVisible( SPC_NAME, 10, 0 ); // Выключим класс прочности
     specification->ksSpcVisible( SPC_NAME, 11, 0 ); // Выключим материал
     specification->ksSpcVisible( SPC_NAME, 12, 0 ); // Выключим покрытие
   }

   // Изменим ГОСТ
   arr->ksClearArray();
   item->uIntVal = tmp.gost;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 14, par1, UINT_ATTR_TYPE  );
   float  massa  = tmp.f & ISPOLN ? tmp.m2 : tmp.m1;
   massa = (float)( massa * (!tmp.indexMassa 
                                  ? 1 : tmp.indexMassa==1 
                                          ? 0.356 : tmp.indexMassa==3 
                                                      ? 0.97 : 1.08) / COUNT_MASSA );
   TCHAR buf[128];
   _stprintf_s( buf, _T("%f") , massa );
   specification->ksSpcMassa ( buf ); // Масса детали

   // Подключим геометрию
   specification->D3SpcIncludePart( part, false );

   return specification->ksSpcObjectEnd();
 }
 return 0;
}


//-------------------------------------------------------------------------------
//
// ---
bool Shpeel::DrawSpcObj() 
{
  ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );
  if ( kompas->ksReturnResult() == etError10 ) // Вырожденный объект
    kompas->ksResultNULL();

  spcObj[0] = obj->EditSpcObj( spcObj );
  if( !obj->par.flagAttr && spcObj ) 
  {
    for ( int i = 0, count = obj->GetObjCount(); i < count; i++ ) 
    {
      if ( spcObj[i] ) 
      {
        obj->doc->ksDeleteObj( spcObj[i] );
        spcObj[i] = 0;
      }
    }
  }
  return spcObj[0] ? true : false;
}

//-------------------------------------------------------------------------------
// Процесс создания детали
// ---
void Shpeel::Draw3D( ksDocument3DPtr &_doc )
{
  if ( _doc ) 
  {
    doc           = _doc;
    specification = doc->GetSpecification();
    flagMode      = doc->IsEditMode() ;
    obj           = this;

    // Взяли деталь
    part = doc->GetPart( flagMode ? pEdit_Part : pNew_Part );
    if ( part ) 
    {
      // После определения детали нужно считать параметры редактирования
      if ( flagMode )
        GetParam();
      else
        part->fileName = (LPCTSTR)obj->SetFileName();

      if ( obj->MacroElementParam() == IDOK ) 
      {
        bool ok = false;
        if ( flagMode )     // Режим редактирования без изменения местоположения и mate'ов
        { 
          SetParam( part ); // Установим параметры
          ok = true;        // Удачное завершение
        }
        else                // Создание нового
        {             
          ksRequestInfo3DPtr info( doc->GetRequestInfo(part) );
          if ( info ) 
          {
            CString prompt;
           
            prompt.LoadString( flagMode ? STR_SELECT_PLANE : STR_SELECT_POINT ); // Укажите точку привязки детали
            info->prompt = (LPCTSTR)prompt;
            SetCallBackAndFilterFunction( info );
            info->CreatePhantom();
            ksPartPtr phantom ( info->GetIPhantom() );
            if ( phantom )
              SetParam( phantom ); 
            
            // Теперь временные српряжения
            if ( doc->UserGetPlacementAndEntity(3) ) 
            {
              ksPlacementPtr lpace( info->GetPlacement() );
              part->SetPlacement( lpace );
              if ( flagMode || doc->SetPartFromFile( (LPCTSTR)obj->SetFileName(), part, false/*externalFile*/ ) ) {
                SetParam( part );

                if ( IsCollectionChange(info) )  // Массив Mate'ов изменился
                { 
                  if ( flagMode )                // Режим редактирования
                    SetMates( doc, info, true ); // Удалить сопряжения

                  SetMates( doc, info );         // Создать сопряжения
                }

                if ( IsCollectionEmpty(info) )   // Указали placement
                  part->UpdatePlacement();        // Изменм положение детали
                
                // Устанавливаем признак, стандартное изделие
                part->standardComponent = true;
              }
              DrawSpcObj();    // Создать объект СП

              if ( spcObj[0] ) // Вывод объекта СП
              {                       
                // Олегово окно - редактируем параметры
                for ( int i = 0, count = obj->GetObjCount(); i < count; i++ ) //{
                  specification->ksEditWindowSpcObject( spcObj[i] );
                  ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );
              }
            }
            else if ( !flagMode )       // Если нажали Stop и это не редактирование ранее вставленного элемента
              doc->DeleteObject( part ); // Удаляем фантом
          }
        }
      }
    }
    part = NULL;
  }
}


//------------------------------------------------------------------------------
// присваивает переменной с именем varName значение val
// ---
void SetVarValue( ksVariableCollectionPtr& varArr, LPCTSTR varName, double val ) {
  ksVariablePtr var( varArr->GetByName(varName, true, false) ); // текущая переменная
  if ( var )
    var->value = val;                     // сменить значение
}


//------------------------------------------------------------------------------
//
// ---
void Shpeel::SetParam( ksPartPtr& _part ) 
{
  // Редактируем внешние переменные
  if ( _part ) 
  {
    // Массив внешних переменных детали
    ksVariableCollectionPtr varArr( _part->VariableCollection() );
    if ( varArr ) 
    {
      float l, b1 = 0, b; // b1 = 0 - условие резьбы на всю длину
      l = tmp.b1 + tmp.l; // Длина всей шпильки
      b = tmp.b;
      float step = tmp.f & PITCH ? tmp.p1 : tmp.p2;
      if( ::fabs(tmp.b1) < 0.001 ) // ГОСТ 22042, ГОСТ 22043 
      { 
        if( ::fabs(tmp.b) > 0.001 ) 
          b1 = b;
      }
      else {
        b1 = tmp.b1;
        if ( ::fabs(tmp.b) < 0.001  )
          b = (float)(tmp.l - 0.5 * tmp.d - 2 * step);
      }
      // Основные параметры
      ::SetVarValue( varArr, _T("d"),      tmp.d                        ); // Диаметр резьбы
      float len = ::fabs(b1 - b) < 0.001 ? tmp.l - b1 : tmp.l;
      ::SetVarValue( varArr, _T("l"),      len                          ); // Длина шпильки
      ::SetVarValue( varArr, _T("b1"),     b1                           ); // Длина ввинчиваемого конца
      ::SetVarValue( varArr, _T("c1"),     tmp.c                        ); // Размер фаски на конце стержня
      if ( ::fabs(l - b1 - b) > 0.001 )
        ::SetVarValue( varArr, _T("l1"),     l - b1 - b                 ); // Длина гладкой части стержня

      ::SetVarValue( varArr, _T("t"),      (step * 0.866 * 3 / 8)       ); // Толщина удаляемого материала

      int perf2 = ( !(tmp.f & ISPOLN) ) || ( tmp.f & ALLST ) || ( ::fabs(l - b1 - b) < 0.001 ) ? 1 : 0;
      ::SetVarValue( varArr, _T("cut1"),   perf2                        ); // Вкл/выкл исполнение 2
      ::SetVarValue( varArr, _T("f1"),     !(tmp.f & SIMPLE) ? 0.0 : 1.0); // Вкл/выкл подголовок

      // Задать название детали
      CString buf1;
      buf1.LoadString( IDS_STUD_NAME );               // Заготовка имени детали из ресурса
      TCHAR buf[255];
      ::_stprintf_s( buf, buf1, tmp.d, tmp.l, tmp.gost ); // Создать имя детали
      _part->name = buf;                           // Присвоить детали новое имя
      _part->Update();                                 // Обновить деталь

      // Перестроим модель с измененными внешними переменными
      _part->RebuildModel();
    }

    SetUserParam();
    _part->SetUserParam( param );
  }
}


//------------------------------------------------------------------------------
// Выбор меню
// ---
int Shpeel::ChoiceMenuId() 
{
  switch ( par.drawType ) 
  {
    case ID_VID    : // Вид
      return  !par.typeSwitch ?  MENU_22032_1 : MENU_22032_3;
    case ID_TOPVID : // Вид сверху
      return  !par.typeSwitch ?  MENU_22032_2 : MENU_22032_4;
  }
  return 0;
}


//------------------------------------------------------------------------------
//
// ---
CString&  Shpeel::SetFileName()
{
  TCHAR name[_MAX_PATH];
  ::GetFullName( STUDS_FILE, name );
  fileName = name;
  return fileName;
}

