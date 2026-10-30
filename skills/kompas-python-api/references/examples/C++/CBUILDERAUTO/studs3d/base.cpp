//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <Ks_TLB.h>
#include <ldefin2d.h>
#include <ldefin3d.h>
#include <ksConstants.h>

#include "base.h"
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------
HINSTANCE _hinst;

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  _hinst = hinst;
  return 1;
}

#ifdef _WIN64
 #define __TODO__ " TODO: "
 #define __WARN__ " warning: "
#else
#define __ANYTOSTR__(x) #x
#define __DEFTOSTR__(x) __ANYTOSTR__(x)
#define __TODO__ __FILE__ "("__DEFTOSTR__(__LINE__)") : TODO: "
#define __WARN__ __FILE__ "("__DEFTOSTR__(__LINE__)") : warning: "
#endif

#ifdef VARIANT_COPIES_BSTR
	wchar_t * TO_OLE(wchar_t *x) { return x; }
	wchar_t * TO_OLE(char    *x) { return WideString(x).c_bstr(); }
	wchar_t * TO_OLE(WideString & x) { return x.c_bstr(); }
#else
#pragma message(  __TODO__ "Рекомендуется добавить в настройки проекта определение VARIANT_COPIES_BSTR\n" )
// подробнее см http://sites.google.com/site/akxsolutions/articles/borland-c-dicom
	wchar_t * TO_OLE(wchar_t *x) { return WideString(x).Copy(); }
	wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
	wchar_t * TO_OLE(WideString & x) { return x.Copy(); }
#endif

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();

KompasObjectPtr kompas;
Shpeel* obj;

extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}

extern "C" char * __declspec(dllexport) __stdcall LIBRARYNAME()
{
	return  "Крепежный элемент на C++Builder";
}

#define  MAX_COUNT_SPCOBJ 4     //максимальное число объектов СП за раз 4
static reference spcObj[MAX_COUNT_SPCOBJ];

#define STANDART_SECTION     25
#define SPC_NAME             5           // наименование

#define EPSILON    0.001
#define STUDS_FILE "stud.l3d|Шпильки|Шпилька_1"

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas )
  {
    Application->Handle =(HWND)kompas->ksGetHWindow();

    Shpeel* par = new Shpeel();
    if ( par )
    {
      kompas->ksResultNULL();
      ksDocument3DPtr doc( (ksDocument3D*)kompas->ActiveDocument3D(), false/*AddRef*/ );
      if ( (bool)doc && !doc->IsDetail() )
        par->Draw3D( doc );
      else
        kompas->ksError( L"Документ не активизирован или не является сборкой" );
    }
    Application->Handle =NULL;

    kompas.Unbind();
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
bool IsSurface( ksEntity * entity, bool planar = true )
{
  bool rez = false;                                // результат проверки
  if ( (bool)entity && entity->IsIt(o3d_face) )
  {
    ksFaceDefinitionPtr faceDef( (ksFaceDefinition*)entity->GetDefinition(), false/*AddRef*/ );
    if ( faceDef )
    {
      if ( planar && faceDef->IsPlanar() )
        rez = true;
      else if ( !planar && faceDef->IsCylinder() )
        rez = true;
    }
  }
  return rez;
}

//------------------------------------------------------------------------------
// определяет является ли объект осью
// ---
bool IsAxis( ksEntity * entity ) {
  if ( entity ) {
    int type = entity->type;
    return type == o3d_axis2Planes   ||  // ось по двум плоскостям
           type == o3d_axisOperation ||  // ось операций
           type == o3d_axis2Points   ||  // ось по двум точкам
           type == o3d_axisConeFace  ||  // ось конической поверхности
           type == o3d_axisEdge;         // ось по ребру
  }
  return false;
}

//------------------------------------------------------------------------------
// функция фильтр
// ---
bool WINAPI SELECTFILTERPROC( ksEntity * entity ) {
  bool rez = false;                                       // выделять нельзя
  if ( entity ) {                                         // если объект есть
    ksPartPtr entPart( (ksPart*)entity->GetParent(), false/*AddRef*/ ); // деталь присланного объекта
    if ( (ksPart*)entPart != (ksPart*)obj->GetPart() )                      // если деталь другая
      rez = ::IsSurface( entity ) || ::IsSurface( entity, false/*planar*/ )
                                  || ::IsAxis( entity );  // проверяем объект на принадлежность к
  }                                                       // плоскости, конической поверхности или оси
  return rez;
}

//------------------------------------------------------------------------------
// функция обратной связи
// 0 - плоскость, 1 - цилиндр, 2 - ось - состав collection
// ---
int WINAPI SELECTCALLBACKPROC( ksEntity* entity, ksRequestInfo3D* info ) {
	char buf[128];

  ksEntityCollectionPtr collection( info ? (ksEntityCollection*)info->GetEntityCollection() : NULL, false/*AddRef*/ );
  if ( collection )
  {
    if ( entity )
    {
      int rez = 0;
      if ( ::IsSurface(entity) ) {
        // При повторном указании объекта снимаем с него выбор
        ksEntityPtr oldPlane( (ksEntity*)collection->GetByIndex(0), false/*AddRef*/ );
        if ( entity == (ksEntity*)oldPlane )
          collection->SetByIndex( NULL, 0   ); // Обнулить плоскость
        else
          collection->SetByIndex( entity, 0 ); // Заменить плоскость
        rez = 1;
      }

      if ( ::IsSurface(entity, false/*planar*/) ) {
        // При повторном указании объекта снимаем с него выбор
        ksEntityPtr oldPlane( (ksEntity*)collection->GetByIndex(1), false/*AddRef*/ );
        if ( (ksEntity*)oldPlane == entity )
          collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
        else
        {
          collection->SetByIndex( entity, 1 ); // Заменить коническую плоскость
          collection->SetByIndex( NULL,   2 ); // Обнулить ось
        }
        rez = 1;
      }

      if ( ::IsAxis(entity) ) {
        // При повторном указании объекта снимаем с него выбор
        ksEntityPtr oldAxis( (ksEntity*)collection->GetByIndex(2), false/*AddRef*/ );
        if ( (ksEntity*)oldAxis == entity )
          collection->SetByIndex( NULL,   2 ); // Обнулить ось
        else
        {
          collection->SetByIndex( entity, 2 ); // Заменить ось
          collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
        }
        rez = 1;
      }

      if ( rez )
        obj->GetCollectChanged() = true;

			LoadStringA( _hinst, STR_SELECT_PLANE, buf, 128 );   // Укажите точку привязки детали
			info->prompt = TO_OLE(buf);
			return rez;
		}
		else {
			for ( int i = 0; i < 3; i++ )
				collection->SetByIndex( NULL, i ); // обнулить

			LoadStringA( _hinst, STR_SELECT_PLANE, buf, 128 );   // Укажите точку привязки детали
			info->prompt = TO_OLE(buf);
			return 1;
		}
	}
	return 0;
}

//------------------------------------------------------------------------------
// добавить сопряжения
// ---
void AddMates( Shpeel& object, ksDocument3DPtr & doc, ksEntityCollectionPtr & collection ) {
	ksEntityPtr ent( (ksEntity*)collection->GetByIndex(0), false/*AddRef*/ );
	if ( ent && ::IsSurface(ent) ) {                   // поверхность
		if ( doc->AddMateConstraint(mc_Coincidence, ent, object.GetEntityByName( L"Plane" ),
					object.GetDirectionElem(), 1, 0) ==false) {
      collection->SetByIndex( NULL, 0 );
    }
  }

  ent.Bind( (ksEntity*)collection->GetByIndex( 1 ), false/*AddRef*/ ); // использовать только оператор =
  if ( ent && ::IsSurface(ent, false/*planar*/) ) {  // коническая поверхность
    if ( doc->AddMateConstraint(mc_Concentric, ent, object.GetEntityByName(L"Axis"),
          0, 1, 0) ==false) {
      collection->SetByIndex( NULL, 1 );
    }
  }

  ent.Bind( (ksEntity*)collection->GetByIndex( 2 ), false/*AddRef*/ ); // использовать только оператор =
  if ( ent && ::IsAxis(ent) ) {                      // ось
    if ( doc->AddMateConstraint(mc_Concentric, ent, object.GetEntityByName(L"Axis"),
          0, 1, 0) ==false) {
      collection->SetByIndex( NULL, 2 );
    }
  }
}

//------------------------------------------------------------------------------
// удалить сопряжения
// ---
void DelMates( Shpeel& object, ksDocument3D* doc, ksEntityCollection* collection ) {
  ksEntity* ent = (ksEntity*)collection->GetByIndex(0);
  if ( ent && ::IsSurface(ent) ) {                   // поверхность
    doc->RemoveMateConstraint( mc_Coincidence, ent, object.GetEntityByName(L"Plane") );
  }

  ent = (ksEntity*)collection->GetByIndex( 1 ); // использовать только оператор =
  if ( ent && ::IsSurface(ent, false/*planar*/) ) {  // коническая поверхность
    doc->RemoveMateConstraint( mc_Concentric, ent, object.GetEntityByName(L"Axis") );
  }

  ent = (ksEntity*)collection->GetByIndex( 2 ); // использовать только оператор =
  if ( ent && ::IsAxis(ent) ) {                      // ось
    doc->RemoveMateConstraint( mc_Concentric, ent, object.GetEntityByName(L"Axis") );
  }
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
  : param         ( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ )
  , paramTmp      ( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ )
  , paramSTmp     ( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ )
  , data          ( (ksDataBaseObject *)kompas->DataBaseObject()       , false/*AddRef*/ )
  , collectChanged( false )
{
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
  : param    ( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ ),
    paramTmp ( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ ),
    paramSTmp( (ksUserParam *)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ ),
    data     ( (ksDataBaseObject *)kompas->DataBaseObject()       , false/*AddRef*/ )
{
  openBase = false;
  ::memcpy( &base, &other.base, sizeof(ShpeelBase) );
  Assign( other );
  InitUserParam();
}

//------------------------------------------------------------------------------
// конструктор копии
// ---
Shpeel* Shpeel::Dublicate()
{
  return new Shpeel( *this );
}

//------------------------------------------------------------------------------
//
// ---
void Shpeel::Assign( const Shpeel& other )
{
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

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*) kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( item && arr ) {
      paramTmp->Init();
      paramTmp->SetUserArray( arr );
      item->Init();
      item->shortVal = 0   ;            // 0 - t
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d;           // 1 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p1;          // 2 - p1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p2;          // 3 - p2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b1;          // 4 - b1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.c;           // 5 - c
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParamTmp() {
  if ( paramTmp ) {
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksLtVariantPtr item1( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)paramTmp->GetUserArray(), false/*AddRef*/ );
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

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParamSTmp() {
  if ( paramSTmp ) {
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( item && arr ) {
      paramSTmp->Init();
      paramSTmp->SetUserArray( arr );
      item->Init();
      item->shortVal = 0;               // 0 - t
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.l;           // 1 - l
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.d;           // 2 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b;           // 3 - b
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m1;          // 4 - m1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m2;          // 5 - m2
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParamSTmp() {
  if ( paramSTmp ) {
    ksLtVariantPtr    item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr(  (ksDynamicArray*)paramSTmp->GetUserArray(), false/*AddRef*/ );
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
static int GetFullName( char *name, char *fName  ) {
	char bufName[512] = {0};
	strcpy( bufName, name );
	char buffer[512] = {0};
	bool rez = false;
	if( ::GetModuleFileNameA(_hinst, fName, _MAX_PATH) ) {
		char *c = ::strchr( bufName, '|' );
		if ( c ) {
			strcpy( buffer, c );
			*c = '\0';
		}

		c = ::strrchr( fName, '\\' );
		if ( c ) {
			*( c + 1 ) = '\0';
			strcat( fName, bufName );
			OFSTRUCT ofs;
			if ( OpenFile(fName , &ofs, OF_EXIST) != HFILE_ERROR )
				rez = true;
			else {
				*(c + 1) = '\0';
				strcat( fName, "LOAD\\" );
				strcat( fName, bufName );
				if ( OpenFile(fName , &ofs, OF_EXIST) != HFILE_ERROR )
					rez = true;
				else {
#ifndef MODEL_LIB
					*(c+1) = '\0';
					strcat( fName, "MODEL\\" );
					strcat( fName, bufName );
					rez = OpenFile(fName , &ofs, OF_EXIST) != HFILE_ERROR ? true : false;
#endif
				}
			}
		}
	}

	if ( buffer && *buffer )
		strcat( fName, buffer );

	return rez;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
int Shpeel::_ConnectDB( reference bd, char *name ) {
  char buf[255];
	return ::GetFullName( name, buf ) ? data->ksConnectDB( bd, TO_OLE(buf ) )
																		: data->ksConnectDB( bd, TO_OLE(name) );
}

//------------------------------------------------------------------------------
// Открытие БД и создание отношений к БД
// ---
bool Shpeel::OpenBase( bool initParam ) {

	if ( initParam ) {
		InitUserParamTmp();
		InitUserParamSTmp();
	}

	if ( data ) {
		char buf[128]; //
		LoadStringA( _hinst, BASE_STR1, buf, 128 );

		base.bg = data->ksCreateDB( TO_OLE(buf) );   // TXT_DB
		base.bs = data->ksCreateDB( TO_OLE(buf) );   // TXT_DB

		int gNumb, stNumb;
    ::NumberGost( tmp.gost, &gNumb, &stNumb );

		LoadStringA( _hinst, gNumb, buf, 128 );
    if( _ConnectDB(base.bg, buf) ) { //"22032.loa"
			LoadStringA( _hinst, stNumb, buf, 128 );
      if( _ConnectDB(base.bs, buf) ) { //"st22032.loa"
				LoadStringA( _hinst, STR_241, buf, 128 );
        base.rg1 = data->ksRelation( base.bg );
        data->ksRInt ( L"t" );
        data->ksRChar( L"d", 20, 0 );
        data->ksEndRelation();
        if ( data->ksDoStatement(base.bg, base.rg1, WideString(buf).c_bstr() ) ) { //"1 2"
          base.rg2 = data->ksRelation( base.bg );
            data->ksRInt  ( L"t" );
            data->ksRFloat( L"d" );
            data->ksRFloat( L""  );
            data->ksRFloat( L""  );
            data->ksRFloat( L""  );
            data->ksRFloat( L""  );
          data->ksEndRelation();
          if ( data->ksDoStatement(base.bg, base.rg2, L"") ) { //TXT_ALL
            LoadStringA( _hinst, STR_243, buf, 128 );
            base.rs1 = data->ksRelation( base.bs );
              data->ksRInt  ( L"t" );
              data->ksRChar ( L"L", 20, 0 );
              data->ksRFloat( L"d" );
            data->ksEndRelation();
            if ( data->ksDoStatement(base.bs, base.rs1, WideString(buf).c_bstr()) ) { //"1 2 3"
              base.rs2 = data->ksRelation( base.bs );
                data->ksRInt  ( L"t" );
                data->ksRFloat( L"L" );
                data->ksRFloat( L"d" );
                data->ksRFloat( L""  );
                data->ksRFloat( L""  );
                data->ksRFloat( L""  );
              data->ksEndRelation();
              if ( data->ksDoStatement(base.bs, base.rs2, L"") ) { // TXT_ALL
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
  char buf[128];
  char s[128];

	LoadStringA( _hinst, STR_245, buf, 128 );
  ::sprintf( s, buf, d );   //"d=%.1f"
  if ( data->ksCondition(base.bg, base.rg2, WideString(s).c_bstr() ) ) {
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
  char buf[128],buf1[128];

	LoadStringA( _hinst, STR_246, buf, 128 );
	::sprintf( buf1, buf, tmp.l, tmp.d );  // "L=%.1f && d=%.1f"

	if ( !data->ksCondition(base.bs,  base.rs2, WideString(buf1).c_bstr()) )
    return -1;
	int i = data->ksReadRecord( base.bs, base.rs2, paramSTmp );
  if ( !i )  {
		LoadStringA( _hinst, STR_245, buf, 128 );
    ::sprintf( buf1, buf, tmp.d);   //" d=%.0f "

    if ( !data->ksCondition(base.bs,  base.rs2,WideString(buf1).c_bstr()) )
			return -1;
    data->ksReadRecord( base.bs, base.rs2, paramSTmp );
  }
  GetUserParamSTmp();
  return 1;
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::InitUserParam() {
  if ( param ) {
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( item && arr ) {
      param->Init();
      param->SetUserArray( arr );
      item->Init();
      item->floatVal = par.ang;           // 0 - ang
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.flagAttr;      // 1 - flagAttr
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.drawType;      // 2 - drawType
      arr->ksAddArrayItem( -1, item );
      item->shortVal = par.typeSwitch;    // 3 - typeSwitch
      arr->ksAddArrayItem( -1, item );

      item->floatVal = tmp.d;             // 4 - d
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p1;            // 5 - p1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.p2;            // 6 - p2
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b1;            // 7 - b1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.c;             // 8 - c
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.l;             // 9 - l
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.b;             // 10 - b
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.f;             // 11 - f
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.klass;         // 12 - klass
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.gost;          // 13 - gost
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.ver;           // 14 - ver
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m1;            // 15 - m1
      arr->ksAddArrayItem( -1, item );
      item->floatVal = tmp.m2;            // 16 - m2
      arr->ksAddArrayItem( -1, item );
      item->shortVal = tmp.indexMassa;    // 17 - indexMassa
      arr->ksAddArrayItem( -1, item );
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::SetUserParam() {
  if ( param ) {
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)param->GetUserArray(), false/*AddRef*/ );
    if ( item && arr && arr->ksGetArrayCount() >= 18 ) {
      item->Init();
      item->floatVal = par.ang;           // 0 - ang
      arr->ksSetArrayItem( 0, item );
      item->shortVal = par.flagAttr;      // 1 - flagAttr
      arr->ksSetArrayItem( 1, item );
      item->shortVal = par.drawType;      // 2 - drawType
      arr->ksSetArrayItem( 2, item );
      item->shortVal = par.typeSwitch;    // 3 - typeSwitch
      arr->ksSetArrayItem( 3, item );

      item->floatVal = tmp.d;             // 4 - d
      arr->ksSetArrayItem( 4, item );
      item->floatVal = tmp.p1;            // 5 - p1
      arr->ksSetArrayItem( 5, item );
      item->floatVal = tmp.p2;            // 6 - p2
      arr->ksSetArrayItem( 6, item );
      item->floatVal = tmp.b1;            // 7 - b1
      arr->ksSetArrayItem( 7, item );
      item->floatVal = tmp.c;             // 8 - c
      arr->ksSetArrayItem( 8, item );
      item->floatVal = tmp.l;             // 9 - l
      arr->ksSetArrayItem( 9, item );
      item->floatVal = tmp.b;             // 10 - b
      arr->ksSetArrayItem( 10, item );
      item->shortVal = tmp.f;             // 11 - f
      arr->ksSetArrayItem( 11, item );
      item->shortVal = tmp.klass;         // 12 - klass
      arr->ksSetArrayItem( 12, item );
      item->shortVal = tmp.gost;          // 13 - gost
      arr->ksSetArrayItem( 13, item );
      item->shortVal = tmp.ver;           // 14 - ver
      arr->ksSetArrayItem( 14, item );
      item->floatVal = tmp.m1;            // 15 - m1
      arr->ksSetArrayItem( 15, item );
      item->floatVal = tmp.m2;            // 16 - m2
      arr->ksSetArrayItem( 16, item );
      item->shortVal = tmp.indexMassa;    // 17 - indexMassa
      arr->ksSetArrayItem( 17, item );
    }
  }
}


//-------------------------------------------------------------------------------
//
// ---
void Shpeel::GetUserParam() {
  if ( param ) {
    ksLtVariantPtr item ( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr ( (ksDynamicArray*)param->GetUserArray(), false/*AddRef*/ );
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
ksEntityPtr Shpeel::GetEntityByName( wchar_t * name ) {
  ksEntityPtr entity;
  if ( part ) {
    if ( !collect )  // массив лежит в классе, и если он ещё не создан - создаём
      collect.Bind( (ksEntityCollection*)part->EntityCollection(o3d_constrElement), false/*AddRef*/ );

    entity.Bind( (ksEntity*)collect->GetByName( name, true/*testFullName*/, true/*testIgnoreCase*/), false/*AddRef*/ );
  }
  return entity;
}


//-------------------------------------------------------------------------------
// массив пуст - указали placement
// ---
bool Shpeel::IsCollectionEmpty( ksRequestInfo3DPtr & info ) {
  bool rez = true;                                     // массив пуст
  ksEntityCollectionPtr collection( (ksEntityCollection*)info->GetEntityCollection(), false/*AddRef*/ ); // новый массив
  if ( collection )
    for( int i = 0, count = collection->GetCount(); i < count; i++ ) {       // цикл по массиву
      ksEntityPtr ent( (ksEntity*)collection->GetByIndex(i), false/*AddRef*/ );       // текущий элемент
      if ( ent ) {                                                // если он не NULL
        rez = false;                                              // массив не пуст
        break;                                                    // завершить цикл
      }
    }
  return rez; // результат
}

//-------------------------------------------------------------------------------
//
// ---
bool Shpeel::IsCollectionChange( ksRequestInfo3DPtr & info ) {
  bool rez = true;                                     // перестраиваем
  if ( !collectChanged ) {                             // если новые объекты не указывали - сравниваем массивы
    // возможен вариант когда указали точку и массив в info заполнен NULL'ми а старый нет
    rez = false;                                       // ненадо перестраивать
    ksEntityCollectionPtr collection1( (ksEntityCollection*)info->GetEntityCollection(), false/*AddRef*/ ); // новый массив
    ksEntityCollectionPtr collection2( (ksEntityCollection*)part->GetMateConstraintObjects(), false/*AddRef*/ ); // старый массив
    if ( collection1 && collection2 && (collection1->GetCount() > 2)
          && (collection2->GetCount() > 2) ) {
      for( int i = 0; i < 3; i++ ) {                        // цикл по массивам
        ksEntityPtr ent1( (ksEntity*)collection1->GetByIndex(i), false/*AddRef*/ );        // текущий элемент 1
        ksEntityPtr ent2( (ksEntity*)collection2->GetByIndex(i), false/*AddRef*/ );        // текущий элемент 2
        if ( (ksEntity*)ent1 != (ksEntity*)ent2 ) {                              // если они не равны
          rez = true;                                       // перестраиваем
          break;                                            // завершить цикл
        }
      }
    }
  }
  return rez; // результат
}

//-------------------------------------------------------------------------------
//
// ---
void Shpeel::SetMates( ksDocument3DPtr & doc, ksRequestInfo3DPtr & info, bool delMates ) {
  ksEntityCollectionPtr collection( !delMates ? (ksEntityCollection*)info->GetEntityCollection()
                                              : (ksEntityCollection*)part->GetMateConstraintObjects(), false/*AddRef*/ );
  if ( collection ) {
    if ( doc && collection->GetCount() > 2 )
      if ( !delMates )
        ::AddMates( *this, doc, collection );
      else
        ::DelMates( *this, doc, collection );

    if ( !delMates )
      part->SetMateConstraintObjects( collection/*NULL*/ );
  }
}

//-------------------------------------------------------------------------------
// заполняет адреса функций фильтра и обратной связи
// ---
void Shpeel::SetCallBackAndFilterFunction( ksRequestInfo3DPtr & info ) {
  info->SetFilterCallBack( L"SELECTFILTERPROC",  (long)_hinst, 0 );
  info->SetCallBack      ( L"SELECTCALLBACKPROC", (long)_hinst, 0 );
}

//------------------------------------------------------------------------------
//
// ---
reference  Shpeel::EditSpcObj( reference *spcObj ){
  ksUserParamPtr par1( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( !par1 || !item || !arr )
    return 0;

  par1->Init();
  par1->SetUserArray( arr );
  item->Init();

  if ( !flagMode && !par.flagAttr && !specification )
    return 0;

  if ( flagMode ) {
    *spcObj = specification->D3GetSpcObjForGeomWithLimit( NULL,             //имя библиотеки типов
                                                          0,                //   номер типа спецификации
                                                          part,
                                                          1,                // 1 -первый объект 0- следующий объект
                                                          STANDART_SECTION, //номер раздела
                                                          81764182256.0 );
    if( !par.flagAttr )
      return *spcObj;


    if ( *spcObj && !specification->ksSpcObjectEdit( *spcObj ) )
      *spcObj  = 0;
  }
  bool flagMode = *spcObj ? true : false;
  if ( flagMode || specification->ksSpcObjectCreate(NULL,                 //имя библиотеки типов
                                                    0,                    //номер типа спецификации
                                                    STANDART_SECTION, 0,  //номер раздела и подраздела
                                                    81764182256.0, 0) ) { //тип атрибута


   //исполнение
   unsigned int uBuf = !!(tmp.f & ISPOLN );
   specification->ksSpcVisible( SPC_NAME, 2, uBuf );
   if ( uBuf ) {
     arr->ksClearArray();
     item->uIntVal = 2;
     arr->ksAddArrayItem( -1, item );
     specification->ksSpcChangeValue( SPC_NAME, 2, par1, UINT_ATTR_TYPE );
   }

   //изменим диаметр
   arr->ksClearArray();
   item->floatVal = tmp.d;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME, 4, par1, FLOAT_ATTR_TYPE  );

   //отследим мелкий шаг
   uBuf = !(tmp.f & PITCHOFF  || !(tmp.f &PITCH));
   specification->ksSpcVisible( SPC_NAME, 5, uBuf );
   specification->ksSpcVisible( SPC_NAME, 6, uBuf );   //щаг
   if( uBuf ) {//выключить шаг и его разделитель
     arr->ksClearArray();
     item->floatVal = tmp.p2;
     arr->ksAddArrayItem( -1, item );
     specification->ksSpcChangeValue( SPC_NAME, 6, par1, FLOAT_ATTR_TYPE );
   }

   //изменим длину
   arr->ksClearArray();
   item->uIntVal = (unsigned int)tmp.l;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 9, par1, UINT_ATTR_TYPE  );

   if ( !flagMode ) {
     specification->ksSpcVisible( SPC_NAME, 7,  0 ); // выключим поле допуска
     specification->ksSpcVisible( SPC_NAME, 10, 0 ); // выключим класс прочности
     specification->ksSpcVisible( SPC_NAME, 11, 0 ); // выключим материал
     specification->ksSpcVisible( SPC_NAME, 12, 0 ); // выключим покрытие
   }

   //изменим ГОСТ
   arr->ksClearArray();
   item->uIntVal = tmp.gost;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 14, par1, UINT_ATTR_TYPE  );
   float  massa  = tmp.f & ISPOLN ? tmp.m2 : tmp.m1;
   massa = (float)( massa * (!tmp.indexMassa 
                                  ? 1 : tmp.indexMassa==1 
                                          ? 0.356 : tmp.indexMassa==3 
                                                      ? 0.97 : 1.08) / COUNT_MASSA );
   char buf[128];
   sprintf( buf, "%f" , massa );
   specification->ksSpcMassa ( WideString(buf).c_bstr() );        //масса детали

   //подключим геометрию
   specification->D3SpcIncludePart( part, false );

   return specification->ksSpcObjectEnd();
 }
 return 0;
}

//-------------------------------------------------------------------------------
//
// ---
bool Shpeel::DrawSpcObj() {

  ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );

  if ( kompas->ksReturnResult() == etError10 )    //  10  "Ошибка! Вырожденный объект"
    kompas->ksResultNULL();

  spcObj[0] = obj->EditSpcObj( spcObj );
  if( !obj->par.flagAttr && spcObj ) {
    for ( int i = 0, count = obj->GetObjCount(); i < count; i++ ) {
      if ( spcObj[i] ) {
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
void Shpeel::Draw3D( ksDocument3DPtr & _doc )
{
  char buf[128];

  if ( _doc ) {
    doc           = _doc;
    specification.Bind( (ksSpecification*)doc->GetSpecification(), false/*AddRef*/ );
    flagMode      = doc->IsEditMode() ;
    obj           = this;

    // взяли деталь
    part.Bind( (ksPart*)doc->GetPart( flagMode ? pEdit_Part : pNew_Part ), false/*AddRef*/ );
    if ( part ) {
      //после определения детали нужно считать параметры редактирования
      if ( flagMode )
        GetParam();

      if ( obj->MacroElementParam() == IDOK ) {

        ksRequestInfo3DPtr info( (ksRequestInfo3D*)doc->GetRequestInfo(part), false/*AddRef*/ );
        if ( info ) {
          if ( flagMode )
						LoadStringA( _hinst, STR_SELECT_PLANE, buf, 128 );
          else
						LoadStringA( _hinst, STR_SELECT_POINT, buf, 128 );
          info->prompt = WideString(buf).c_bstr(); // Укажите точку привязки детали
          
          SetCallBackAndFilterFunction( info );
          if ( doc->UserGetPlacementAndEntity(3) ) {
            part->SetPlacement( info->GetPlacement() );
            if ( flagMode || doc->SetPartFromFile( obj->SetFileName().c_bstr(), part, false/*externalFile*/ ) )
            {
              SetParam();

              if ( IsCollectionChange(info) ) { // массив Mate'ов изменился
                if ( flagMode )                            // режим редактирования
                  SetMates( doc, info, true/*delMates*/ ); // удалить сопряжения

                SetMates( doc, info );                     // создать сопряжения
              }

              if ( IsCollectionEmpty(info) ) // указали placement
                part->UpdatePlacement();      // изменм положение детали
              //устанавливаем признак, стандартное изделие
              part->standardComponent = true;
            }
            DrawSpcObj(); // создать объект СП

            if ( spcObj[0] ) {                       // вывод объекта СП
              //Олегово окно - редактируем параметры
              for ( int i = 0, count = obj->GetObjCount(); i < count; i++ ) //{
                specification->ksEditWindowSpcObject( spcObj[i] );
              ::memset( spcObj, 0, sizeof(reference) * MAX_COUNT_SPCOBJ );
            }

          }
          else if ( !flagMode )        // Если нажали Stop и это не редактирование ранее вставленного элемента
            doc->DeleteObject( part ); // Удаляем фантом

          
        }
//        obj->CloseElemBase();
      }

      part.Unbind();
    }
  }
}

//------------------------------------------------------------------------------
// присваивает переменной с именем varName значение val
// ---
void SetVarValue( ksVariableCollectionPtr & varArr, wchar_t* varName, double val ) {
  ksVariablePtr var( (ksVariable*)varArr->GetByName( varName, true, false), false/*AddRef*/ ); // текущая переменная
  if ( var )
    var->value = val;                     // сменить значение
}

//------------------------------------------------------------------------------
//
// ---
void Shpeel::SetParam() {
  //редактируем внешние переменные
  if ( part ) {
    //массив внешних переменных детали
    ksVariableCollectionPtr varArr( (ksVariableCollection*)part->VariableCollection(), false/*AddRef*/ );
    if ( varArr ) {
      float l, b1 = 0, b; // b1=0;  - условие резьбы на всю длину
      l = tmp.b1 + tmp.l; //длина всей шпильки
      b = tmp.b;
      float step = tmp.f & PITCH ? tmp.p1 : tmp.p2;
      if( ::fabs(tmp.b1) < 0.001 ) { // ГОСТ 22042, ГОСТ 22043
        if( ::fabs(tmp.b) > 0.001 ) //{
          b1 = b;
      }
      else {
        b1 = tmp.b1;
        if ( ::fabs(tmp.b) < 0.001  )
          b = (float)(tmp.l - 0.5 * tmp.d - 2 * step);
      }
      // основные параметры
      ::SetVarValue( varArr, L"d",      tmp.d                        ); // диаметр резьбы
      float len = ::fabs(b1 - b) < 0.001 ? tmp.l - b1 : tmp.l;
      ::SetVarValue( varArr, L"l",      len                          ); // длина шпильки
      ::SetVarValue( varArr, L"b1",     b1                           ); // длина ввинчиваемого конца
      ::SetVarValue( varArr, L"c1",     tmp.c                        ); // размер фаски на конце стержня
      if ( ::fabs(l - b1 - b) > 0.001 )
        ::SetVarValue( varArr, L"l1",     l - b1 - b                   ); // длина гладкой части стержня

      ::SetVarValue( varArr, L"t",      (step * 0.866 * 3 / 8)       ); // толщина удаляемого материала

      int perf2 = ( !(tmp.f & ISPOLN) ) || ( tmp.f & ALLST ) || ( ::fabs(l - b1 - b) < 0.001 ) ? 1 : 0;
      ::SetVarValue( varArr, L"cut1",   perf2                        ); // вкл/выкл исполнение 2
      ::SetVarValue( varArr, L"f1",     !(tmp.f & SIMPLE) ? 0.0/*вкл*/ : 1.0/*выкл*/ ); // вкл/выкл подголовок

      // задать название детали
      char buf[255],buf1[128];
			LoadStringA( _hinst, IDS_STUD_NAME, buf1, 128 );              // заготовка имени детали из ресурса

      ::sprintf( buf, buf1, tmp.d, tmp.l, tmp.gost );  // создать имя детали
			part->name = WideString(buf).c_bstr();           // присвоить детали новое имя
      part->_Update();                                 // Обновить деталь

      //перестроим модель с измененными внешними переменными
      part->RebuildModel();
    }

		SetUserParam();
    part->SetUserParam( param );
  }
}

//------------------------------------------------------------------------------
// Выбор меню
// ---
int Shpeel::ChoiceMenuId() {
  switch ( par.drawType ) {
    case ID_VID    : //      Вид
      return  !par.typeSwitch ?  MENU_22032_1 : MENU_22032_3;
    case ID_TOPVID ://      (Вид_сверху)
      return  !par.typeSwitch ?  MENU_22032_2 : MENU_22032_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
//
// ---
WideString & Shpeel::SetFileName() {
  char name[128];
  ::GetFullName( STUDS_FILE, name );
  fileName = name;
  return fileName;
}
//------------------------------------------------------------------------------


