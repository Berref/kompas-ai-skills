// gayka.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "gayka.h"
#include <math.h>

#include <objbase.h>
#include <initguid.h> //  -  Definitions for controlling GUID initialization
                      // Include after compobj.h to enable GUID initialization.  This
                      //              must be done once per exe/dll.
                      // After this file, include one or more of the GUID definition files.
                      //

#ifndef __LIBHPPAR_H
#include <libhppar.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//название колонок для спецификации
#define   SPC_FORMAT     1     //формат
#define   SPC_ZONA       2     //зона
#define   SPC_POSITION   3     //позиция
#define   SPC_MARKER     4     //обозначение
#define   SPC_NAME       5     //наименование
#define   SPC_COUNT      6     //количество
#define   SPC_NOTE       7     //примечание


#define   SPC_CLEAR_GEOM       0     // очищать геометрию при редактировании объекта спецификации
#define   STANDART_SECTION     25
#define    LIB_HELPFILE         "gayka.chm" // имя файла помощи

#define MIN_H_ANG -90
#define MAX_H_ANG 90
#define MIN_H_SHAG 0.1
#define MAX_H_SHAG 1000
#define KONSTR_TXT "konstr.txt"
#define SPC_LIB "graphic.lyt"

#define COUNT_MASSA 1000
#define MAX_COUNT_SPCOBJ 4     //максимальное число объектов СП за раз 4

//
//  Note!
//
//    If this DLL is dynamically linked against the MFC
//    DLLs, any functions exported from this DLL which
//    call into MFC must have the AFX_MANAGE_STATE macro
//    added at the very beginning of the function.
//
//    For example:
//
//    extern "C" BOOL PASCAL EXPORT ExportedFunction()
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
// CGaykaApp

BEGIN_MESSAGE_MAP(CGaykaApp, CWinApp)
  //{{AFX_MSG_MAP(CGaykaApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaykaApp construction

CGaykaApp::CGaykaApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGaykaApp object

CGaykaApp theApp;

//-------------------------------------------------------------------------------
//
// ---
char* WINAPI LIBRARYNAME(){
  return  "Конструкторский элемент";
}

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIBID;
}

KompasObjectPtr kompas;
ksDocument2DPtr doc   ;
Gayka5915*   obj;

//-------------------------------------------------------------------------------
//
// ---
void _MessageBoxResult() {
  if ( kompas->ksReturnResult() ) {
    if ( kompas->ksReturnResult() == etError10 )    //  10  "Ошибка! Вырожденный объект"
      kompas->ksResultNULL();
    else
      kompas->ksMessageBoxResult();
  }
}

//------------------------------------------------------------------------------
// загрузить строку из ресурса
// ---
CString LoadStr( int id ) {
  if ( kompas ) {
    CString b;
    b.LoadString( id );
    TCHAR buf[255];
    ::_tcscpy_s( buf, kompas->ksConvertLangStr((LPCTSTR)b) );
    if ( !::_tcslen( buf ) )
      ::_tcscpy_s( buf, b );
    return CString ( buf );
  }
  return CString ( "" );
}

//-------------------------------------------------------------------------------
//
// ---
void GetKompas() 
{
  CString filename;
  if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
  {
    filename.ReleaseBuffer( 255 );
    CString libname;

    #ifdef __LIGHT_VERSION__
      libname.LoadString( IDS_STRING5 );  // klAPI5.dll
    #else
      libname.LoadString( IDS_STRING4 );  // kAPI5.dll
    #endif

    filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                      libname );

    HINSTANCE hAppAuto = LoadLibrary( filename ); // Идентификатор kAPI5.dll
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

//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());
  
  ASSERT( (size_t)(AfxGetApp()->m_hInstance) <= 0xFFFFFFFF );
  GetKompas();
  if ( kompas ) {
    doc = kompas->ActiveDocument2D();
    if ( doc && doc->reference ) {
      Gayka5915* par = new Gayka5915();
      if ( par ) {
        par->Draw1();
        delete par;
      }
    }
    else {
      CString mess;
      mess = ::LoadStr( IDS_2DDOCERROR ); // Достать строку сообщения из ресурса
      kompas->ksError( (LPCTSTR)mess );   // выдать сообщение о ошибке
    }
  }
}

bool flagSwitch;  // false переключения нет true переключение с
                  // Placement на Cursor

static bool       flagCalcPaket;  // true - нужно считать длину пакета
static reference spcObj[MAX_COUNT_SPCOBJ];
static TCHAR     buf[255];

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
static int GetFullName( LPCTSTR name, TCHAR *fName  ) {
  if( ::GetModuleFileName(theApp.m_hInstance, fName, 255) ) {
   TCHAR *c = _tcsrchr( fName, _T('\\') );
    if ( c ) {
      *(c + 1) = '\0';
      _tcscat_s( fName, 255, name );
      OFSTRUCT ofs;
      if ( ::OpenFile(_bstr_t(fName), &ofs, OF_EXIST) != HFILE_ERROR )
        return 1;
      else {
        *(c + 1) = '\0';
        _tcscat_s( fName, 255, _T("LOAD\\") );
        _tcscat_s( fName, 255, name );
        if ( ::OpenFile(_bstr_t(fName), &ofs, OF_EXIST) != HFILE_ERROR )
          return 1;
      }
    }
  }
  return 0;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
int Gayka5915::_ConnectDB( reference bd, LPCTSTR name ) {
  return ::GetFullName( name, buf ) ? data->ksConnectDB( base.bg, buf  ) 
                                    : data->ksConnectDB( base.bg, name );
}

// HOT_POINTS ##################################################################

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

//-------------------------------------------------------------------------------
// Накрутка для работы с Hot-точками
// ---
class Gayka5915HP : public ILibHPObject {
  protected :
    Gayka5915 obj;
    int count;
  public :
    Gayka5915HP() : obj(), count (0) {};
   ~Gayka5915HP();
  public:
  virtual unsigned long _IFUNC AddRef();
  virtual unsigned long _IFUNC Release();
  virtual HRESULT        _IFUNC QueryInterface(const GUID far& iid, void far*far* iface);


  virtual int    _IFUNC LibHotPnt_GetMenu       ()                                        { return obj.GetMenu(); }
  virtual BOOL   _IFUNC LibHotPnt_Prepare       ( int index )                            { return TRUE; }
  virtual BOOL   _IFUNC LibHotPnt_Complete      ( int index, BOOL success )               { return obj.EditComplete( index, success ); }
  virtual BOOL   _IFUNC LibHotPnt_Get           ( HotPointDescription* point, int index ) { return obj.GetHotPoints( point, index ); }
  virtual BOOL   _IFUNC LibHotPnt_Set           ( HotPointDescription* point, int index ) { return obj.SetHotPoint( point, index ) ? true : false; }
  virtual BOOL   _IFUNC LibHotPnt_GetCursorText ( int index, char** text )                { return obj.GetCursorText( index, text ); }
  virtual BOOL   _IFUNC LibHotPnt_ExecuteCommand( int id )                                { return obj.ExecuteCommand( id ); }
};

//------------------------------------------------------------------------------
//
// ---
unsigned long _IFUNC Gayka5915HP::AddRef() {
  count++;
  return count;
}

//------------------------------------------------------------------------------
//
// ---
unsigned long _IFUNC Gayka5915HP::Release() {
  count--;
  unsigned long rez = count;
  if( !count )
    delete this;
  return rez;
}

//------------------------------------------------------------------------------
//
// ---
HRESULT _IFUNC Gayka5915HP::QueryInterface(const GUID far& iid, void far*far* iface){
  if ( iid == IID_ILibHPObject ) {
    *iface = this;
    return S_OK;
  }
  *iface = NULL;
  return E_NOINTERFACE;
}


//------------------------------------------------------------------------------
extern "C" void __stdcall LibObjInterfaceEntry( int idType, unsigned int Comm, 
                                                ILibHPObject** object ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define

  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( object && kompas ) {
    doc = kompas->ActiveDocument2D();
    if ( doc && doc->reference ) {
      if ( idType == 1 )//если не hot точки  обнулить
        switch (Comm) {
          case 1 : *object = new Gayka5915HP(); (*object)->AddRef(); break;
        }
    }
  }

}


Gayka5915HP::~Gayka5915HP() {
}

// HOT_POINTS ##################################################################

//-------------------------------------------------------------------------------
// конструктор
// ---
Gayka5915::Gayka5915() 
  : param   ( kompas->GetParamStruct(ko_UserParam) ),
    paramTmp( kompas->GetParamStruct(ko_UserParam) ),
    data    ( kompas->DataBaseObject()                ) {
  par.flagAttr    = 0 ;
  par.typeSwitch  = 0;
  par.ang         = 0;
  par.drawType    = (short)ID_VID;

  refMacr  = 0;
  countObj = 1;
  flagMode = 0;

  InitUserParam();

  if ( !::doc->ksGetMacroParam(0, param) ) {
    // ВРЕМЕННО
    kompas->ksResultNULL();
    tmp.gost       = 5915;
    tmp.hatchAng   = 45;
    tmp.hatchShag  = 2;
    tmp.f          = 0; 
    tmp.dr         = 20;  
    tmp.p          = 2.5;
    tmp.f1         = 0;
    tmp.ver        = 1;
    tmp.indexMassa = 0;
    tmp.s           = 30; 
    tmp.D          = 33;  
    tmp.da         = (float)21.6;  
    tmp.h          = 16;
    tmp.d2         = (float)27.7;  
    tmp.klass      = 2;   /*класс точности*/
    tmp.f         |= TAKEISPOLN;
    tmp.f1        |= KEY_S_ON;
    tmp.f1        |= KOEFF_MAT_ON;
    tmp.massa      = (float)71.44;
  }
  else {
    // ВРЕМЕННО
    kompas->ksResultNULL();

    GetUserParam();
    tmp.ver = 1;
    tmp.f1 |= KEY_S_ON;
    tmp.f1 |= KOEFF_MAT_ON;
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::Assign( Gayka5915& other ) {
  refMacr  = other.refMacr;
  countObj = other.countObj;
  flagMode = other.flagMode;
  ::memcpy( &par.ang, &other.par.ang, sizeof(BaseMakroParam) );
  ::memcpy( &tmp.dr,  &other.tmp.dr,  sizeof(GAYKA5915)      );
}

//-------------------------------------------------------------------------------
//
// ---
Gayka5915* Gayka5915::Dublicate() {
  return new Gayka5915( *this );
}

//-------------------------------------------------------------------------------
//
// ---
Gayka5915::Gayka5915( Gayka5915& other ) 
  : param   ( kompas->GetParamStruct(ko_UserParam) ),
    paramTmp( kompas->GetParamStruct(ko_UserParam) ),
    data    ( kompas->DataBaseObject()                ) {
  Assign( other );
  InitUserParam();
}

/*
struct GaykaTMP{
  float dr;
  float p1;
  float p2;
  float s;
  float D;
  float da;
  float h;
  float d2;
  float m;
  float s1;
  float D1;
  float m1;
};
*/
//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::InitUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr      item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( item && arr ) {
      paramTmp->Init();
      paramTmp->SetUserArray( arr );
      item->Init();
      item->floatVal = tmp.dr;      // 0 - dr
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p;       // 1 - p1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p;       // 2 - p2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.s;       // 3 - s
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.D;       // 4 - D
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.da;      // 5 - da
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.h;       // 6 - h
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d2;      // 7 - d2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.massa;   // 8 - m
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.s;       // 9 - s1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.D;       // 10 - D1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.massa;   // 11 - m1
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::GetUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr      item ( kompas->GetParamStruct(ko_LtVariant) );
    ksLtVariantPtr      item1( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr   ( paramTmp->GetUserArray() );
    if ( item && item1 && arr  && arr->ksGetArrayCount() >= 12 ) {
      item->Init();
      arr->ksGetArrayItem( 0, item ); // dr
      tmp.dr = item->floatVal;

      arr->ksGetArrayItem( 5, item ); // da
      tmp.da = item->floatVal;

      arr->ksGetArrayItem( 6, item ); // h
      tmp.h = item->floatVal;

      arr->ksGetArrayItem( 7, item ); // d2
      tmp.d2 = item->floatVal;

      arr->ksGetArrayItem( 1, item  ); // p1
      arr->ksGetArrayItem( 2, item1 ); // p2
      if ( tmp.f & PITCH )
        tmp.p = item1->floatVal;
      else
        tmp.p = item->floatVal;

      if ( ::fabs(item1->floatVal - item->floatVal) < 0.001 )
        tmp.f |= PITCHOFF;
      else
        tmp.f &=~PITCHOFF;

      arr->ksGetArrayItem( 9, item1 ); // s1
      if ( tmp.f1 & KEY_S_ON && ::fabs(item1->floatVal) > 0.001 )
        tmp.f1 |= KEY_S_GRAY;
      else {
        tmp.f1 &=~ KEY_S_GRAY;
        tmp.f1 &=~ KEY_S;
      }

      if ( tmp.f1 & KEY_S_ON && tmp.f1 & KEY_S ) {
        tmp.s  = item1->floatVal;    /*размер под ключ*/
        arr->ksGetArrayItem( 10, item1 ); // D1
        tmp.D  = item1->floatVal;    /* диаметр описанной окружности*/
        arr->ksGetArrayItem( 11, item1 ); // m1
        tmp.massa  = item1->floatVal;
      }
      else {
        arr->ksGetArrayItem( 3, item1 ); // s
        tmp.s  = item1->floatVal;    /*размер под ключ*/
        arr->ksGetArrayItem( 4, item1 ); // D
        tmp.D  = item1->floatVal;    /* диаметр описанной окружности*/
        arr->ksGetArrayItem( 8, item1 ); // m
        tmp.massa  = item1->floatVal;
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
int Gayka5915::OpenGaykaBase() {
  InitUserParamTmp();
  if ( data ) {
    base.bg = data->ksCreateDB( _T("TXT_DB") );   // TXT_DB

    if( !_ConnectDB(base.bg, _T("5915.loa")) ) // "5915.loa"
      return 0;
    else {
      base.rg = data->ksRelation( base.bg );
        data->ksRFloat( _T("dr") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
        data->ksRFloat( _T("") );
      data->ksEndRelation();
      if ( !data->ksDoStatement( base.bg, base.rg, _T("")) ) //TXT_ALL
        return 0;
      else
        return 1;
    }
  }
  return 0;
}

//-------------------------------------------------------------------------------
//  Читать параметры гайки по диаметру
//  возвращает 1 - успех 0 - не найдено записи , ошибка связи с БД
// ---
int Gayka5915::ReadGaykaBase( float d ) {
  CString s;
  s.Format( _T("dr=%.1f"), (float)(d > 0 ? d : tmp.dr) );
  if ( !data->ksCondition(base.bg, base.rg, (LPCTSTR)s) ) { return 0;}
  int i = data->ksReadRecord( base.bg, base.rg, paramTmp );
  if ( i ) {
    GetUserParamTmp();
    return 1;
  }
  return 0;
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::CloseGaykaBase() {
  if ( base.bg )
    data->ksDeleteDB( base.bg );
}

/*
  float          ang;
  unsigned short flagAttr;
  short          drawType;
  BYTE           typeSwitch;  // тип запроса положения базовой точки элемента 0 Placement 1 Curso


  float  dr;
  float  s;
  float  D;
  float  da;
  float  h;
  float  d2;
  float  p;
  short  f;          // битовые маски
  short  klass;      // класс точности
  short  gost;       // номер госта
  float  hatchAng;
  float  hatchShag;
  short  ver;        // версия макро
  float  massa;
  short  indexMassa; // 0-металл 1- алюмин сплав 2-латунь
  short  f1;          // битовые маски
*/
//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::InitUserParam() {
  if ( param ) {
    ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
    if ( item && arr ) {
      param->Init();
      param->SetUserArray( arr );
      item->Init();
      item->floatVal = par.ang;     // 0 - ang
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.flagAttr; // 1 - flagAttr
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.drawType; // 2 - drawType
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.typeSwitch; // 3 - typeSwitch
      arr->ksAddArrayItem( -1, item );

      item->floatVal = tmp.dr;      // 4 - dr
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.s;       // 5 - s
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.D;       // 6 - D
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.da;       // 7 - da
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.h;       // 8 - h
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d2;      // 9 - d2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p;       // 10 - p
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.f;       // 11 - f
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.klass;   // 12 - klass
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.gost;    // 13 - gost
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.hatchAng; // 14 - hatchAng
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.hatchShag; // 15 - hatchShag
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.ver;     // 16 - ver
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.massa;   // 17 - m
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.indexMassa; // 18 - indexMassa
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.f1;    // 19 - f1
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::SetUserParam() {
  if ( param ) {
    ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr  ( param->GetUserArray() );
    if ( item && arr && arr->ksGetArrayCount() >= 20 ) {
      item->Init();
      item->floatVal = par.ang;     // 0 - ang
      arr->ksSetArrayItem( 0, item );
      item->shortVal = par.flagAttr; // 1 - flagAttr
      arr->ksSetArrayItem( 1, item );
      item->shortVal = par.drawType; // 2 - drawType
      arr->ksSetArrayItem( 2, item );
      item->shortVal = par.typeSwitch; // 3 - typeSwitch
      arr->ksSetArrayItem( 3, item );
      item->floatVal = tmp.dr;      // 4 - dr
      arr->ksSetArrayItem( 4, item );
      item->floatVal = tmp.s;       // 5 - s
      arr->ksSetArrayItem( 5, item );
      item->floatVal = tmp.D;       // 6 - D
      arr->ksSetArrayItem( 6, item );
      item->floatVal = tmp.da;       // 7 - da
      arr->ksSetArrayItem( 7, item );
      item->floatVal = tmp.h;       // 8 - h
      arr->ksSetArrayItem( 8, item );
      item->floatVal = tmp.d2;      // 9 - d2
      arr->ksSetArrayItem( 9, item );
      item->floatVal = tmp.p;       // 10 - p
      arr->ksSetArrayItem( 10, item );
      item->shortVal = tmp.f;       // 11 - f
      arr->ksSetArrayItem( 11, item );
      item->shortVal = tmp.klass;   // 12 - klass
      arr->ksSetArrayItem( 12, item );
      item->shortVal = tmp.gost;    // 13 - gost
      arr->ksSetArrayItem( 13, item );
      item->floatVal = tmp.hatchAng; // 14 - hatchAng
      arr->ksSetArrayItem( 14, item );
      item->floatVal = tmp.hatchShag; // 15 - hatchShag
      arr->ksSetArrayItem( 15, item );
      item->shortVal = tmp.ver;     // 16 - ver
      arr->ksSetArrayItem( 16, item );
      item->floatVal = tmp.massa;   // 17 - m
      arr->ksSetArrayItem( 17, item );
      item->shortVal = tmp.indexMassa; // 18 - indexMassa
      arr->ksSetArrayItem( 18, item );
      item->shortVal = tmp.f1;    // 19 - f1
      arr->ksSetArrayItem( 19, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::GetUserParam() {
  if ( param ) {
    ksLtVariantPtr    item ( kompas->GetParamStruct(ko_LtVariant) );
    ksDynamicArrayPtr  arr   ( param->GetUserArray() );
    if ( item && arr && arr->ksGetArrayCount() >= 20 ) {
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
      tmp.dr = item->floatVal;
      arr->ksGetArrayItem( 5, item );
      tmp.s = item->floatVal;
      arr->ksGetArrayItem( 6, item );
      tmp.D = item->floatVal;
      arr->ksGetArrayItem( 7, item );
      tmp.da = item->floatVal;
      arr->ksGetArrayItem( 8, item );
      tmp.h = item->floatVal;
      arr->ksGetArrayItem( 9, item );
      tmp.d2 = item->floatVal;
      arr->ksGetArrayItem( 10, item );
      tmp.p = item->floatVal;
      arr->ksGetArrayItem( 11, item );
      tmp.f = item->shortVal;
      arr->ksGetArrayItem( 12, item );
      tmp.klass = item->shortVal;
      arr->ksGetArrayItem( 13, item );
      tmp.gost = item->shortVal;
      arr->ksGetArrayItem( 14, item );
      tmp.hatchAng = item->floatVal;
      arr->ksGetArrayItem( 15, item );
      tmp.hatchShag = item->floatVal;
      arr->ksGetArrayItem( 16, item );
      tmp.ver = item->shortVal;
      arr->ksGetArrayItem( 17, item );
      tmp.massa = item->floatVal;
      arr->ksGetArrayItem( 18, item );
      tmp.indexMassa = item->shortVal;
      arr->ksGetArrayItem( 19, item );
      tmp.f1 = item->shortVal;
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
int Gayka5915::ChoiceMenuId() {
  if ( !par.typeSwitch )
    return par.drawType == ID_VID ?  MENU_G5915_1 : par.drawType == ID_TOPVID  ? MENU_G5915_2 :
           par.drawType == ID_SIDEVID ? MENU_G5915_4 : MENU_G5915_3;
  else
    return par.drawType == ID_VID ?  MENU_G5915_5 : par.drawType == ID_TOPVID  ? MENU_G5915_6 :
           par.drawType == ID_SIDEVID ? MENU_G5915_8 : MENU_G5915_7;
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::SetHatchAngl() {
  double a;
  kompas->ksEnableTaskAccess( 0 );
  if ( kompas->ksReadDouble(_T("Введите угол штриховки"), tmp.hatchAng, -90, 90, &a) )
    tmp.hatchAng = (float)a;
  kompas->ksEnableTaskAccess( 1 );
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::SetHatchShag(){
  double a;
  kompas->ksEnableTaskAccess( 0 );
  if ( kompas->ksReadDouble(_T("Введите шаг штриховки"), tmp.hatchShag, 0.1, 1000, &a) )
    tmp.hatchShag = (float)a;
  kompas->ksEnableTaskAccess( 1 );
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::SetParam() {
  SetUserParam();
  doc->ksSetMacroParam( refMacr, param, false, true, false );
}

//-------------------------------------------------------------------------------
//
// ---
reference  Gayka5915::EditSpcObj( reference *spcObj, reference geom ) {
  ksSpecificationPtr  specification( doc->GetSpecification() );
  ksUserParamPtr      bufPar( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr      item  ( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr   arr    ( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( specification && bufPar && item && arr ) {
    bufPar->Init();
    item->Init();
    bufPar->SetUserArray( arr );
    if ( !flagMode && !par.flagAttr  )
      return 0;

    if ( flagMode ) {
      *spcObj = specification->ksGetSpcObjForGeomWithLimit( _T(""), //имя библиотеки типов
                                                    0,         //   номер типа спецификации
                                                    geom,
                                                    0, // 1 - присланная геометрия идентична геометрии объекта СП; 0- входит в объект СП
                                                    1, // 1 -первый объект 0- следующий объект
                                                    STANDART_SECTION,    //номер раздела
                                                    297327484710.0 );
      if ( !par.flagAttr )
        return *spcObj;

      if ( *spcObj && !specification->ksSpcObjectEdit(*spcObj) )
        *spcObj  = 0;
    }

    reference flMode = *spcObj;
    // создаем объект спецификации для умолчательногостиля СП
    if ( flMode || specification->ksSpcObjectCreate(_T(""), //имя библиотеки типов
                                            0,         //   номер типа спецификации
                                            STANDART_SECTION,  0,    //номер раздела и подраздела
                                            297327484710.0,0 )) {    //тип атрибута
      arr->ksAddArrayItem( -1, item );
      // исполнение
      if ( !(tmp.f & ISPOLN) )
        specification->ksSpcVisible( SPC_NAME, 2, 0 );
      else {
        item->uIntVal = 2;
        arr->ksSetArrayItem( 0, item );
        specification->ksSpcVisible( SPC_NAME, 2, 1 );
        specification->ksSpcChangeValue( SPC_NAME , 2, bufPar, UINT_ATTR_TYPE  );
      }

      // изменим диаметр
      item->floatVal = tmp.dr;
      arr->ksSetArrayItem( 0, item );
      specification->ksSpcChangeValue( SPC_NAME, 4, bufPar, FLOAT_ATTR_TYPE  );

      // отследим мелкий шаг
      if ( !(tmp.f &PITCH) ){//выключить шаг и его разделитель
        specification->ksSpcVisible( SPC_NAME, 5, 0 );
        specification->ksSpcVisible( SPC_NAME, 6, 0 );   //щаг
      }
      else {
        specification->ksSpcVisible( SPC_NAME, 5, 1 );
        specification->ksSpcVisible( SPC_NAME, 6, 1 );   //щаг
        item->floatVal = tmp.p;
        arr->ksSetArrayItem( 0, item );
        specification->ksSpcChangeValue( SPC_NAME , 6, bufPar, FLOAT_ATTR_TYPE );
      }

      // выключим поле допуска
      if ( !flMode  ) {
        specification->ksSpcVisible( SPC_NAME, 7, 0 );
        // выключим класс прочности
        specification->ksSpcVisible( SPC_NAME, 8, 0 );
        // выключим материал
        specification->ksSpcVisible( SPC_NAME, 9, 0 );
        // выключим покрытие
        specification->ksSpcVisible( SPC_NAME, 10, 0 );
      }


      // изменим ГОСТ
      item->uIntVal = tmp.gost;
      arr->ksSetArrayItem( 0, item );
      specification->ksSpcChangeValue( SPC_NAME , 12, bufPar, UINT_ATTR_TYPE  );

      float  massa = (float)( tmp.massa * (!tmp.indexMassa 
                                              ? 1 : tmp.indexMassa == 1 
                                                      ? 0.356 : 1.08) / COUNT_MASSA );
      CString buf;
      buf.Format( _T("%f"), massa );
      specification->ksSpcMassa( (LPCTSTR)buf );        //масса детали

      // подключим геометрию
      if ( geom )
        specification->ksSpcIncludeReference( geom, SPC_CLEAR_GEOM  );

      return specification->ksSpcObjectEnd();
    }
  }
  return 0;
}

//----------------------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
//----------------------------------------------------------------------------------------------
void DrawPosLeader( reference _spcObj, ksSpecificationPtr & specification ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
  if ( info ) {
    info->Init();
    bool      flag      = false;
    reference posLeater = 0;

    double x1, y1;
    do { 
      info->menuId = MENU_POS_LEADER;
      info->title = (LPCTSTR)::LoadStr( STR11 );
      CString prompt;
      prompt = ::LoadStr( STR226 );
      info->prompt = (LPCTSTR)prompt;
      int j1 = doc->ksCursor( info, &x1, &y1, NULL );
      CString menu;
      switch ( j1 ) {
        case 1: // Создать новую линию выноски
          posLeater = doc->ksCreateViewObject( POSLEADER_OBJ );
          flag = false;
          break;
        case 2: // Подключить существующую
          menu = ::LoadStr( STR226 );
          info->commandsString = (LPCTSTR)menu;
          if ( doc->ksCursor(info, &x1, &y1, NULL) ) {
            posLeater = doc->ksFindObj( x1, y1, 100 );  // величина стороны окошка-ловушки с центром x,y
            if ( !(posLeater && doc->ksGetObjParam(posLeater, NULL, 0) == POSLEADER_OBJ) ) {
              menu = ::LoadStr( STR228 );
              kompas->ksError( (LPCTSTR)menu );
              posLeater = 0;
              flag = true;
            }
            else
              flag = false;
            break;
          }
          else
            flag = false;
          break;
        case -1:
          posLeater = doc->ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
          if ( !(posLeater && doc->ksGetObjParam(posLeater, NULL, 0) == POSLEADER_OBJ) ) {
            menu = ::LoadStr( STR228 );
            kompas->ksError( (LPCTSTR)menu );
            posLeater = 0;
            flag = true;
          }
          else
            flag = false;
        break;
      }
    } while ( flag );

    //линия выноски есть, подключим ее к объекту спецификации 
    if ( posLeater ) {
      //ввойдем в режим редактирования объекта спецификации
      if ( specification->ksSpcObjectEdit( _spcObj ) ) {
        //подключим линию выноски
        specification->ksSpcIncludeReference( posLeater, true );
        //закроем объект спецификации
        specification->ksSpcObjectEnd();
      }
    }
  }
}

// HOT_POINTS ##################################################################

//------------------------------------------------------------------------------
//
// ---
bool Gayka5915::GetHotPoints( HotPointDescription* point, int index ) {
  bool rez = false;
  switch ( index ) {
    case 0 : {  // точка привязки
      point->x = 0;
      point->y = 0;
      point->text = "0";
      rez = true;
      break;
    }
    case 1 : {  // изменение диаметра
      point->x = 0;
      point->y = tmp.dr / 2.0;
      point->cursorInst = theApp.m_hInstance;
      point->cursorId   = CURSOR_DIAMETER;
      point->text       = "Dr";
      rez = true;
      break;
    }
    case 2 : {  // угол поворота
      static char textForHP_2[255]; // обязательно должен быть описан как static
      ::sprintf_s( textForHP_2, "A = %.2f", /*360.0 + */::fmod((double)par.ang, 360.0) );

      point->x = par.drawType == ID_TOPVID ? (tmp.s / 2.0) : tmp.h;
      point->y = 0;
      point->cursorInst = theApp.m_hInstance;
      point->cursorId   = CURSOR_ROTATE;
      point->text       = textForHP_2;
      rez = true;
      break;
    }
  }
  return rez;
}

//------------------------------------------------------------------------------
bool Gayka5915::GetCursorText( int index, char** text ) {
  static char cursorText[255]; // обязательно должен быть описан как static
  switch ( index ) {
    case 2 :
              ::sprintf_s( cursorText, "A = %.2f", /*360.0 + */::fmod((double)par.ang, 360.0) );
              *text = cursorText;
              return true;
    case 1 :
              ::sprintf_s( cursorText, "D = %.2f\nH = %.2f", tmp.dr, tmp.h );
              *text = cursorText;
              return true;
  }

  return false;
}

//------------------------------------------------------------------------------
bool Gayka5915::ChangeHotPointParam( double d ) {
  // подобрать ближайший dR по d
  double dR = 0.0;
  double oldDR = tmp.dr;

  OpenGaykaBase();

  while( true ) {
    if ( data->ksReadRecord(base.bg, base.rg, paramTmp) ) {
      ksLtVariantPtr      item ( kompas->GetParamStruct(ko_LtVariant) );
      ksDynamicArrayPtr  arr   ( paramTmp->GetUserArray() );
      if ( item && arr && arr->ksGetArrayCount() >= 12 ) {
        item->Init();
        arr->ksGetArrayItem( 0, item ); // dr
        float dr = item->floatVal;
        if ( dR <= d )
          dR = dr;
        else
          break;
      }
    }
    else
      break;
  }

  bool retVal = false;
  if ( ::fabs( dR - oldDR ) > 0.01 )
    retVal = ReadGaykaBase( (float)dR ) ? true : false;

  CloseGaykaBase();
  return retVal;
}

//------------------------------------------------------------------------------
//
// ---
int Gayka5915::SetHotPoint( HotPointDescription* point, int index ) {
  double x;
  double y;
  double alpha;
  if ( doc->ksGetMacroPlacement(0, &x, &y, &alpha) ) {

    reference gr=0;
    switch ( index ) {
        case 0 :
          refMacr = 0;
          SetParam();
          doc->ksSetMacroPlacement( refMacr, point->x, point->y, 0.0, 1 );
          break;
        case 1 :
          if ( ChangeHotPointParam( ::fabs(point->y * 2) ) ) {
            GetGroup( gr );
            SetParam();
            doc->ksSetMacroPlacement( refMacr, 0., 0., 0., 1 );
            doc->ksStoreTmpGroup( gr );
            doc->ksClearGroup( gr, true );
          }
          break;
        case 2 : {
          refMacr = 0;
          ksMathematic2DPtr math( kompas->GetMathematic2D() );
          if ( math ) {
            double ang;
            if ( point->y == 0 )
            ang = 0.0;
            else if ( point->x == 0 )
              ang = 90.0;
            else
              ang = math->ksAtanD( point->y/point->x  );//::atan2( point->y, point->x ) * 180.0 / 3.1415926;

            par.ang += (float)ang;
            SetParam();
            doc->ksSetMacroPlacement( refMacr, 0., 0., ang, 1 );
          }
         }
         break;
    } // switch
  }
  return TRUE;
}


//------------------------------------------------------------------------------
//
// ---
//#pragma argsused
//Gayka5915* obj1;
bool Gayka5915::EditComplete( int index, BOOL success ) {
  if ( index == 1 && success ) {
    obj = this;
    DrawSpcObj( 0 ); 
    if ( spcObj[0] ) {
      ksSpecificationPtr specification( doc->GetSpecification() );
      if ( specification )
        for ( UINT i = 0, count = obj->GetObjCount(); i < count; i++ ) {
          if ( specification->ksEditWindowSpcObject(spcObj[i]) ) {
            DrawPosLeader( spcObj[i], specification );
          }
        }
    }
  }
  return TRUE;
}

//------------------------------------------------------------------------------
//
// ---
int Gayka5915::GetMenu() {
  HMENU menu = ::LoadMenu( theApp.m_hInstance, MAKEINTRESOURCE( GAIKA_POPUPMENU ) );
  ::CheckMenuItem( menu, par.drawType, MF_BYCOMMAND | MF_CHECKED );
  if ( par.drawType != ID_VIDSEC ) {
    ::EnableMenuItem( menu, ID_HATCH_ANG,  MF_BYCOMMAND | MF_GRAYED );
    ::EnableMenuItem( menu, ID_HATCH_SHAG, MF_BYCOMMAND | MF_GRAYED );
  }
  return int(menu);
}

//------------------------------------------------------------------------------
//
// ---
bool  Gayka5915::ExecuteCommand( int id ) {
  double x;
  double y;
  double alpha;
  if ( doc->ksGetMacroPlacement(0, &x, &y, &alpha) ) {

    switch ( id ) {
        case ID_PARAM :
          MacroElementParam();
          break;
        case ID_VID     :
        case ID_TOPVID  :
        case ID_SIDEVID :
        case ID_VIDSEC  :
          par.drawType = (short)id;
          break;
        case ID_HATCH_ANG :
          SetHatchAngl();
          break;
        case ID_HATCH_SHAG :
          SetHatchShag();
          break;
    }

    reference gr;
    GetGroup( gr );

    SetParam();
    doc->ksSetMacroPlacement( refMacr, 0.0, 0.0, 0.0, 1 );
    doc->ksStoreTmpGroup( gr );
    doc->ksClearGroup( gr, true );
  }

  return true;
}

// HOT_POINTS ##################################################################

//-------------------------------------------------------------------------------
//
// ---
void gayka_k( float ls, float l, float d1, float s, float D,
              float l1, float H, short j, int j1, float d2, int j2 ) {
  ksMathematic2DPtr math( kompas->GetMathematic2D() );
  if ( math ) {
    float x[9], y[9];
    float c, h1, rb;
    float xc2, yc2, xcbl, ycbl, xcbp, ycbp, ycml;
    /* Координаты контура рез_части */

    /*j1=1 -   контровочное отверстие  j1=0 - контров. отв. нет*/
    /*j2=1 исполнение 1   j2=2    исполнение 2 */

    D  = (float)( s / math->ksCosD(30) );
    c  = (float)( (D - d2) / 2 * math->ksTanD(30) );
    h1 = (float)( D * 0.5 * math->ksSinD(30) );
    rb = ( h1 * h1 + c * c ) / 2 / c;

    x[1] = ls; y[1] = 0;
    if ( j2 == 1 ){
      x[2] = ls;      y[2] = (float)( j * (d2 * 0.5) );
      x[3] = ls + c;  y[3] = (float)( j * (D * 0.5) );
      x[7] = ls + c;  y[7] = j * h1;
    }
    else {
      x[2] = ls; y[2] = (float)( j * (D * 0.5) );
      x[7] = ls; y[7] = j * h1;
    }
    x[4] = ls + H - c;  y[4] = (float)( j * (D * 0.5) );
    x[5] = ls + H;      y[5] = (float)( j * (d2 * 0.5) );
    x[6] = ls + H;      y[6] = 0;

    x[8] = ls + H - c;  y[8] = j * h1;
    xc2  = ls + l;      yc2 = (float)( j * (D * 0.5 - l1) );

    xcbl = ls + rb; ycbl = 0;
    xcbp = ls + H - rb; ycbp = 0;
    ycml = (float)( j * ((D *0.5 - h1) / 2 + h1) );

    if ( j2 == 1) {
      doc->ksLineSeg( x[1], y[1], x[2], y[2], 1 );
      doc->ksLineSeg( x[2], y[2], x[3], y[3], 1 );
      doc->ksLineSeg( x[3], y[3], x[4], y[4], 1 );
      doc->ksLineSeg( x[4], y[4], x[5], y[5], 1 );
      doc->ksLineSeg( x[5], y[5], x[6], y[6], 1 );
      doc->ksLineSeg( x[7], y[7], x[8], y[8], 1 );
      doc->ksArcByPoint( xcbl, ycbl, rb, x[1], y[1], x[7], y[7],(short) -j, 1 );
      doc->ksArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
      doc->ksArcBy3Points( ls + c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                          ls, ycml, x[7], y[7], 1 );
      doc->ksArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j, ls + H,
                          ycml, x[8], y[8], 1 );
    }
    else {
     doc->ksLineSeg( x[1], y[1], x[2], y[2], 1 );
     doc->ksLineSeg( x[2], y[2], x[4], y[4], 1 );
     doc->ksLineSeg( x[4], y[4], x[5], y[5], 1 );
     doc->ksLineSeg( x[5], y[5], x[6], y[6], 1 );
     doc->ksLineSeg( x[7], y[7], x[8], y[8], 1 );
     doc->ksArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
     doc->ksArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                         ls + H, ycml, x[8], y[8], 1 );

    }

    if ( j1 == 1) {
     doc->ksCircle( xc2, yc2, d1 * 0.5, 1 );
     doc->ksLineSeg( xc2 - 2, yc2, xc2 + 2, yc2, 2 );
     doc->ksLineSeg( xc2, yc2 - 2, xc2, yc2 + 2, 2 );
    }
  }
} 

//-------------------------------------------------------------------------------
//
// ---
void gayka_k_side( float ls, float s, float D, float d2,
                   float H,   int   j, int   j2 ) {
  ksMathematic2DPtr math( kompas->GetMathematic2D() );
  if ( math ) {
    float x, y;
    float x2, y2;
    // j2 = 1 исполнение 1   j2 = 2    упрощенное 
    float c = (float)( (D - d2) / 2 * math->ksTanD(30) );

    y = (float)( j * s * 0.5 );
    if ( j2 == 1 )  {
      x = ls + c;
      doc->ksLineSeg( ls, 0,            ls, j * d2 * 0.5, 1 );
      doc->ksLineSeg( ls, j * d2 * 0.5, x,  y,            1 );
      doc->ksArcBy3Points( ls + c, j * (s * 0.5), ls, s * 0.25 * j, ls + c, 0, 1 );
    }
    else {
      x = ls;
      doc->ksLineSeg( x, 0, x, y, 1 );
    }

    if ( j2 == 3 ) {
      x2 =ls + H;
      y2 = y;
    }
    else {
      x2 = ls + H - c;
      y2 = (float)( j * d2 * 0.5 );
    }
    doc->ksLineSeg( x, y, x2, y, 1 );
    if ( j2 != 3 )  {
      doc->ksLineSeg( x2, y, ls + H, y2, 1 );
      doc->ksArcBy3Points( ls + H - c, j * (s * 0.5), ls + H,s * 0.25 * j,
                          ls + H - c, 0, 1 );
    }
    doc->ksLineSeg( ls + H, y2, ls + H, 0, 1 );
    if ( j > 0 )
      doc->ksLineSeg( x, 0, x2, 0, 1 );
  }
}

//-------------------------------------------------------------------------------
//
// ---
void gayka_k_y( float ls, GAYKA5915* tmp, int j ) {
  ksMathematic2DPtr math( kompas->GetMathematic2D() );
  if ( math ) {
    float h1;
    tmp->D = (float)( tmp->s / math->ksCosD(30) );

    h1 = (float)( tmp->D * 0.5 * math->ksSinD(30) );

    float p1 = (float)( j * tmp->D * 0.5 );
    float p2 = ls + tmp->h;
    doc->ksLineSeg( ls, 0,      ls, p1,     1 );
    doc->ksLineSeg( ls, p1,     p2, p1,     1 );
    doc->ksLineSeg( p2, p1,     p2, 0,      1 );
    doc->ksLineSeg( ls, j * h1, p2, j * h1, 1 );
  }
} 

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::gayka_p_k( int j ) {
  ksMathematic2DPtr math( kompas->GetMathematic2D() );
  if ( math ) {
    float c1 = 0, c2 = 0;
    float x = 0, x1, x2, x3, y3, y2;

    float c = (float)( (tmp.D - tmp.d2) / 2 * math->ksTanD(30) );
    float y = (float)( j * (!(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) ? tmp.d2 : tmp.D) * 0.5 );
    doc->ksLineSeg( 0, 0, 0, y, 1 );

    if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) ) {
      x = c;
      doc->ksLineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
    }
    float dd = (float)( tmp.dr - 2 * MODSTEP_REAL * tmp.p );

    if ( !(tmp.f & SIMPLE) ) {
      x3 = tmp.h - c ;
      y3 = (float)( j * tmp.d2 * 0.5 ); 
      y2 = (float)( j * tmp.da * 0.5 );
    }
    else {
      x3 = tmp.h;
      y3 = (float)( j * tmp.D * 0.5 );
      y2 = (float)( j * dd * 0.5 );
    }

    doc->ksLineSeg( x, j * tmp.D * 0.5, x3, j * tmp.D * 0.5, 1 );
    if ( !(tmp.f & SIMPLE) )
      doc->ksLineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );
    doc->ksLineSeg( tmp.h, y3, tmp.h, 0, 1 );

    x1 = tmp.h;
    x2 = x1;
    if ( !(tmp.f & SIMPLE) ) {
      c1 = (float)( (tmp.da - dd) * 0.5 );
      c2 = (float)( (tmp.da - tmp.dr) * 0.5 );
      if ( !(tmp.f & ISPOLN) )
        x2 = x2 - c2;
    }

    if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) ) {
      x1 = x1 - c1;
      doc->ksLineSeg( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
      doc->ksLineSeg( x1, j * dd * 0.5, x1, 0, 1 );
    }

    doc->ksLineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );

    if ( !(tmp.f & SIMPLE) ) {
      doc->ksLineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1);
      doc->ksLineSeg( c1, j * dd * 0.5, c1, 0, 1 );
    }

    doc->ksHatch( 0, tmp.hatchAng, tmp.hatchShag, 0, 0, 0 );
      doc->ksLineSeg( 0, y2, 0, y, 1 );
      if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
        doc->ksLineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
      doc->ksLineSeg( x, j * (tmp.D * 0.5), x3, j * tmp.D * 0.5, 1 );
      if ( !(tmp.f & SIMPLE) )
        doc->ksLineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );

      if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
        doc->ksLineSeg( tmp.h, y3, tmp.h, j * tmp.da * 0.5, 1 );
      else
        doc->ksLineSeg( tmp.h, y3, tmp.h, j * dd * 0.5, 1 );


      if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
        doc->ksLineSeg( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
      doc->ksLineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );
      if ( !(tmp.f & SIMPLE) )
        doc->ksLineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1 );
    doc->ksEndObj();
    doc->ksLineSeg( c2, j * 0.5 * tmp.dr, x2, j * 0.5 * tmp.dr, 2 );
  }
}


//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::gayka_sverhu() {
  ksMathematic2DPtr math( kompas->GetMathematic2D() );
  if ( math ) {
    float s  = (float)( tmp.s * 0.5 );
    float D  = (float)( s / math->ksCosD(30) );
    float dd = (float)( tmp.dr - 2 * MODSTEP_REAL * tmp.p );
    float h1 = (float)( D * math->ksSinD(30) );

    doc->ksLineSeg( -s, h1,  0,  D,   1 );
    doc->ksLineSeg( 0,  D,   s,  h1,  1 );
    doc->ksLineSeg( s,  h1,  s,  -h1, 1 );
    doc->ksLineSeg( s,  -h1, 0,  -D,  1 );
    doc->ksLineSeg( 0,  -D,  -s, -h1, 1 );
    doc->ksLineSeg( -s, -h1, -s, h1,  1 );

    if ( !(tmp.f & SIMPLE) )
      doc->ksCircle( 0, 0, tmp.d2 * 0.5, 1 );

    doc->ksCircle( 0, 0, dd * 0.5, 1 );
    float rad = (float)( tmp.dr * 0.5 );
    float x1  = (float)( rad * math->ksSinD(15) );
    float y1  = (float)( rad * math->ksCosD(15) );
    doc->ksArcByPoint( 0, 0, rad, x1, y1, y1, -x1, 1, 2 );

    if ( !(tmp.f & AXIS_OFF ) ) {
      if ( D >= 6 )  {
        doc->ksLineSeg( -3 -s, 0,  s + 3, 0,     3 );
        doc->ksLineSeg( 0, -3  -D, 0,     3 + D, 3 );
      }
      else  {
        doc->ksLineSeg( -1 -s, 0,  s + 1, 0,     3 );
        doc->ksLineSeg( 0, -1  -D, 0,     1 + D, 3 );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::GetGroup( reference &gr ) {
  int k2 = tmp.f & ISPOLN ? 2 : 1;

  if ( doc->ksExistObj(gr) )
    doc->ksDeleteObj( gr );

  gr = doc->ksNewGroup( 1 );
  doc->ksMacro( 0 );
  switch ( par.drawType ) {
    case ID_VID :  /*вид*/
      if ( !(tmp.f & SIMPLE) ) {
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1,  0, tmp.d2, k2 );
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, -1, 0, tmp.d2, k2 );
      }
      else {
       gayka_k_y( 0, &tmp,  1 );
       gayka_k_y( 0, &tmp, -1 );
      }
      if ( !(tmp.f & AXIS_OFF) )
        doc->ksLineSeg( -3, 0, tmp.h + 3, 0, 3 );
    break;
    case ID_SIDEVID : /*вид сбоку*/
      if ( !(tmp.f & AXIS_OFF ) )
        doc->ksLineSeg( -3, 0, tmp.h + 3, 0, 3 );
      if ( tmp.f & SIMPLE )
        k2 = 3;
      gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, 1,  k2 );
        gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, -1, k2 );
      break;
    case ID_TOPVID    : gayka_sverhu(); break; // вид ссверху
    case ID_VIDSEC: /*пол-вида/пол-разреза*/
      if( !(tmp.f & SIMPLE) ) {
        gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1, 0, tmp.d2, k2 );
        gayka_p_k( -1 );
      }
      else {
        gayka_k_y( 0, &tmp, 1 );
        gayka_p_k( -1 );
      }
      if ( !( tmp.f & AXIS_OFF ) )
        doc->ksLineSeg( -3, 0, tmp.h + 3, 0, 3 );
    break;
  }

  refMacr = doc->ksEndObj();
  doc->ksEndGroup();
}

//------------------------------------------------------------------------------
//
// ---
void  Gayka5915::SetPlacement( double x, double y, double angl ) {
  doc->ksSetMacroPlacement( refMacr, x,  y,  angl, 0 );
}


//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
int WINAPI CALLBACKPROCCURSOR( int comm, double* x, double*y, LPDISPATCH rInfo,
                               LPDISPATCH rPhan, int dynamic ) 
{
  int res = 1;
  ksRequestInfoPtr info( rInfo );
  ksPhantomPtr     phan( rPhan );

  if ( info && phan ) 
  {
    ksType1Ptr t1( phan->GetPhantomParam() );
    if( !dynamic ) 
    { 
      switch ( comm ) 
      {
        case ID_ANGLE  :
          flagSwitch = true;
          res = 0;
          break;
        case ID_VID       :
        case ID_TOPVID    :
        case ID_SIDEVID   :
        case ID_VIDSEC    :
          obj->GetParam().drawType = (short)comm;
          break;
        case ID_HATCH_ANG :
          obj->SetHatchAngl();
          break;
        case ID_HATCH_SHAG :
          obj->SetHatchShag();
          break;
        case ID_PARAM :
          obj->MacroElementParam();
          break;
        case -1 : // Поставить в модель
        { 
          obj->SetParam();

// HOT_POINTS ##################################################################
          obj->ServiceObj1( (float)*x, (float)*y );
          obj->SetPlacement( *x, *y, obj->GetParam().ang );
          doc->ksStoreTmpGroup( t1->gr );
// HOT_POINTS ##################################################################
          
          if ( obj->DrawSpcObj(t1->gr) ) 
          {
            doc->ksClearGroup( t1->gr, true );
            res = 0;
            break;
          }
          doc->ksClearGroup( t1->gr, true );
          if( obj->GetFlagMode() )
            res = 0;
          break;
        }
      }

      if( res ) 
      {
        info->menuId = obj->ChoiceMenuId();
        reference gr;
        obj->GetGroup( gr );
        t1->gr = gr;
      }
    }
  }

  return res;
}


//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
// ---
int WINAPI CALLBACKPROCPLACEMENT( int comm, double* x, double* y, double* ang, LPDISPATCH rInfo,
                                  LPDISPATCH rPhan, int dynamic ) 
{
  int res = 1;
  ksRequestInfoPtr info( rInfo );
  ksPhantomPtr     phan( rPhan );

  if ( info && phan ) 
  {
    ksType1Ptr t1( phan->GetPhantomParam() );
    if( !dynamic ) 
    { 
      switch ( comm ) 
      {
        case ID_ANGLE   :
          flagSwitch = true;
          res = 0;
          break;
        case ID_VID     :
        case ID_TOPVID  :
        case ID_SIDEVID :
        case ID_VIDSEC  :
          obj->GetParam().drawType = (short)comm;
          break;
        case ID_HATCH_ANG :
          obj->SetHatchAngl();
          break;
        case ID_HATCH_SHAG :
          obj->SetHatchShag();
          break;
        case ID_PARAM :
          obj->MacroElementParam();
          break;
        case -1 : // Поставить в модель
        {                 
          obj->GetParam().ang = (float)*ang;
          obj->SetParam();

// HOT_POINTS ##################################################################
          obj->ServiceObj1( (float)*x, (float)*y );
          obj->SetPlacement( *x, *y, *ang );
          doc->ksStoreTmpGroup( t1->gr ); // Поставить временную группу в вид
// HOT_POINTS ##################################################################
        
          if ( obj->DrawSpcObj(t1->gr) ) 
          {
            doc->ksClearGroup( t1->gr, true );
            res = 0;
            break;
          }
          doc->ksClearGroup( t1->gr, true );
          if( obj->GetFlagMode() )
            res = 0;
          break;
        }
      }

      if( res )
      {
        info->menuId = obj->ChoiceMenuId();
        reference gr;
        obj->GetGroup( gr );
        t1->gr = gr;
      }
    }
    else 
      obj->GetParam().ang = (float)*ang;
  }

  return res;
}

//-------------------------------------------------------------------------------
//
// ---
void Gayka5915::Draw1() {
   ksPhantomPtr phan( kompas->GetParamStruct(ko_Phantom) );
  if ( phan ) {
    phan->Init();
//    phan.SetPhantom( 1 );
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = 0;   // временная группа

      int j=1;
      double x, y, ang;
      if ( !kompas->ksReturnResult() ) {
        flagMode = doc->ksEditMacroMode();
        obj       = this;
        if ( MacroElementParam() != IDOK )
          return;

        while ( j ) {
          flagSwitch    = 0;
          flagCalcPaket = false;
          reference gr;
          GetGroup( gr );
          t1->gr = gr;
          t1->angle = par.ang;

          ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
          if ( info ) {
            info->Init();
            info->menuId = ChoiceMenuId();
            info->dynamic = 1;
            info->title = (LPCTSTR)::LoadStr( STR11 );

            if ( par.typeSwitch ) {
              // указываем адрес обратной функции для Cursor
              info->SetCallBackC( _T("CALLBACKPROCCURSOR"), PtrToLong(theApp.m_hInstance), 0 );
              j = doc->ksCursor( info, &x, &y, phan );
            }
            else {
              // указываем адрес обратной функции для Placement
              info->SetCallBackP( _T("CALLBACKPROCPLACEMENT"), PtrToLong(theApp.m_hInstance), 0 );
              j = doc->ksPlacement( info, &x, &y, &ang, phan );
            }

            if ( spcObj[0] ) {
              ksSpecificationPtr  specification( doc->GetSpecification() );
              for ( UINT i = 0, count = GetObjCount(); i < count; i++ ) {
                // Олегово окно - редактируем параметры
                if ( specification && specification->ksEditWindowSpcObject(spcObj[i]) ) 
                  ::DrawPosLeader( spcObj[i], specification );
              }
              ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );
              if ( !flagMode ) {
                flagSwitch = true;
                par.typeSwitch ? par.typeSwitch = 0 : par.typeSwitch = 1;
              }
            }

            if ( flagSwitch ) {
              j = 1;
              par.typeSwitch ? par.typeSwitch = 0 : par.typeSwitch = 1;
            }
            if ( flagCalcPaket ) {
              CalkPaket();
              j = 1;
            }
          }
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
bool Gayka5915::DrawSpcObj( reference geom ) {

  ksSpecificationPtr  specification( doc->GetSpecification() );
  ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );
  if( specification && obj->IsSpcObjCreate() ) {
    if ( kompas->ksReturnResult() == etError10 )    //  10  "Ошибка! Вырожденный объект"
      kompas->ksResultNULL();

    spcObj[0] = obj->EditSpcObj( spcObj, geom );
    if( !obj->GetParam().flagAttr && spcObj ) {
      for ( UINT i = 0, count = obj->GetObjCount(); i < count; i++ ) {
        if( spcObj[i] ) {
          // ввойдем в режим редактирования объекта спецификации
          if ( specification->ksSpcObjectEdit(spcObj[i]) ) {
            // очистим геометрию, чтобы не удалялась в месте с объектом  
            specification->ksSpcIncludeReference( 0, 0 );
            // закроем объект спецификации
            specification->ksSpcObjectEnd();
          }
          doc->ksDeleteObj( spcObj[i] );
          spcObj[i] = 0;
        }
      }
    }  
  }
  return spcObj[0] ? true : false;
}
