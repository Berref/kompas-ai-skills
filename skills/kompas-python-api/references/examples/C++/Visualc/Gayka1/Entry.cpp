////////////////////////////////////////////////////////////////////////////////
//
// Класс для работы с хот точками
// ILibHPObject - Интерфейс хот точек
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"
#include "SArray.h"
#include "CPar.h"
#include <SafeArrayUtils.h>


#if !defined(_IFUNC)
 #define _IFUNC STDMETHODCALLTYPE
#endif

extern HINSTANCE g_hInstance = NULL;


ksAPI7::IApplicationPtr newKompasAPI(NULL);


//-------------------------------------------------------------------------------
// EXTENSION Приложение
// ---
AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };

//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  g_hInstance = hInstance;
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    App7NULL();
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI()
{
  if (!(ksAPI7::IApplication*)newKompasAPI)
  {
    CString filename;

    if (::GetModuleFileName(NULL, filename.GetBuffer(255), 255))
    {
      filename.ReleaseBuffer(255);
      CString libname;

      libname = "kAPI7.dll";    // kAPI7.dll
      filename.Replace(filename.Right(filename.GetLength() - (filename.ReverseFind(_T('\\')) + 1)), libname);

      HINSTANCE hAppAuto = LoadLibrary(filename); // идентификатор kAPI7.dll

      if (hAppAuto)
      {
        // Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH(WINAPI * FCreateKompasApplication)();

        FCreateKompasApplication pCreateKompasApplication =
          (FCreateKompasApplication)GetProcAddress(hAppAuto, "CreateKompasApplication");

        if (pCreateKompasApplication)
          newKompasAPI = IDispatchPtr(pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
        FreeLibrary(hAppAuto);
      }
    }
  }
}




//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return ID_LIBID;
}


//-------------------------------------------------------------------------------
// Создание класса элемента 
// ---
CPar* NewGayka5915( reference obj, bool fromDataBase );  // Гайка ГОСТ 5915
CPar* NewBolt7787 ( reference obj, bool fromDataBase );  // Болт  ГОСТ 7787-81

//-------------------------------------------------------------------------------
// Создание класса элемента 
// ---
CPar* NewCParObject( int comm, reference objRef, bool fromDataBase )
{
  CPar* obj = NULL;
  switch ( comm )
  {
    case CM_GAYKA5915 : obj = NewGayka5915( objRef, fromDataBase ); break;
    case CM_BOLT7787  : obj = NewBolt7787 ( objRef, fromDataBase ); break;
    // Здесь можно вставлять другие элементы
  }
  return obj;
}

//-------------------------------------------------------------------------------
// Получить идентификаторы инструментальных и компактных панелей
// ---
reference GetFirstSelectedObj()
{
  reference obj = 0;
  if ( ExistGroupObj( 0 ) )
  {
    reference it = CreateIterator( SELECT_GROUP_OBJ, 0 );
    if ( it )
    {
      obj = MoveIterator( it, 'F' );
      DeleteIterator( it );
    }
  }
  return obj;
}

//-------------------------------------------------------------------------------
// Получить идентификаторы инструментальных и компактных панелей
// ---
void GetSelectedObjects( SArray<reference> & selected )
{
  reference obj = 0;
  if ( ExistGroupObj( 0 ) )
  {
    reference it = CreateIterator( SELECT_GROUP_OBJ, 0 );
    if ( it )
    {
      obj = MoveIterator( it, 'F' );
      while ( obj )
      {
        selected.Add( obj );
        obj = MoveIterator( it, 'N' );
      }
      DeleteIterator( it );
    }
  }
}


int GetMacroCommand( reference obj )
{
  int res = 0;
  int comm = 0;
  TCHAR fileName[MAX_PATH] = _T("");
  TCHAR libName [MAX_PATH] = _T("");
  if ( ksGetMacroEditParamT( obj, fileName, MAX_PATH, libName, MAX_PATH, &comm ) && !_tcscmp(libName, LoadStr(ID_LIBID)) )
    res = comm;
  return res;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
  {
    switch ( comm )
    {
      case ID_VIEW   :
      case ID_TOPVID :
      case ID_VIDSEC :
      case ID_LEFT   :
      case ID_SIMPLE :
      case ID_AXIS   :
      {
        SArray<reference> selected;
        GetSelectedObjects(selected);
        for ( int i = 0, count = selected.Count(); i < count; i++ )
        {
          reference macro = selected[i];
          int cm = GetMacroCommand( macro );
          if ( cm )
          {
            // Создаем объект
            CPar * obj = NewCParObject( cm, macro );
            if ( obj ) 
            {
              obj->OnButtonClick( comm );
              obj->RedrawMacro();
            
            }
          }
        }
      }
      break;
    
      case CM_GAYKA5915 :
      case CM_BOLT7787  :
      {
        // Создаем объект
        GetNewKompasAPI();
        CPar* obj = NewCParObject( comm, EditMacroMode() );
        if (obj->OpenBase()) 
				{
          obj->SetEdit(EditMacroMode());
          obj->InitProcessParam(comm + 4000, pnEnterEscHelp, comm + 4000);
          obj->PlacementProcess();
        }
      }
    } // switch
    
  }
  else
    ErrorT( LoadStr( ID_ERROR_2DDOC ) ); // Выдать сообщение о ошибке

}

//-------------------------------------------------------------------------------
// Получить идентификаторы инструментальных и компактных панелей
// ---
int WINAPI FillContextPanel( LPUNKNOWN _contextPanel )  // Индекс панели
{
  int res = FALSE;
  ksAPI7::IContextPanelPtr contextPanel( _contextPanel );
  if ( contextPanel )
  {
    reference doc = ksGetCurrentDocument( 1 );
    if ( doc )
    {
      reference macro = GetFirstSelectedObj();
      if ( macro )
      {
        int command = GetMacroCommand( macro );
        if ( command )
        {
          CPar * obj = NewCParObject( command, macro );
          switch ( command )
          {
            case CM_GAYKA5915: 
            {
              contextPanel->Fill( _T("GAYKA5915_BAR") );
              int view = ID_VIEW;
              if ( obj->IsButtonChecked(ID_TOPVID) )
                view = ID_TOPVID;
              else if ( obj->IsButtonChecked( ID_SIDEVID ) )
                view = ID_SIDEVID;
              else if ( obj->IsButtonChecked( ID_VIDSEC ) )
                view = ID_VIDSEC;
              contextPanel->FillComboBoxImage(_T("GAYKA5915_VIEW"), _T("GAYKA5915_VIEW_GROUP"), _variant_t(), view );
              SArray<long> styles;
              styles.Add( ksHatchMetal );
              styles.Add( ksHatchTimber );
              styles.Add( ksHatchGlass );
              _variant_t stylesVar;
              CopySArrayToVariant( styles, stylesVar );
              contextPanel->FillComboBoxStyle( _T( "APP_Gaika1_Hatch" ), ksControlHatchStyle, stylesVar, ksHatchTimber );
              
              res = TRUE;
              break;
            }
          }
        }
      }
    }
  }
  return res;
}

int WINAPI ContextPanelStyleComboChanged( wchar_t* styleComboID, long styleType, long newValue )
{
  MessageT( _T("Здесь нужно изменить стиль штриховки у селектированных объектов.") );
  return 1;
}


//-------------------------------------------------------------------------------
// Состояние команды
// ---
int WINAPI LibCommandState( unsigned int comm, int * enable, int * checked )
{
  if ( enable )
  {
    int type = ksGetDocumentType( 0 ); 
    *enable = type == lt_DocSheetStandart || type == lt_DocFragment || type == lt_DocSheetUser;
    
    if ( *enable && checked )
    {
      switch ( comm )
      {
        case ID_VIEW    :
        case ID_TOPVID  :
        case ID_SIDEVID :
        case ID_VIDSEC  :
        case ID_SIMPLE  :
        case ID_AXIS    :
        {
          *enable = false;
          reference macro = GetFirstSelectedObj();
          if ( macro )
          {
            int cm = GetMacroCommand( macro );
            if ( cm )
            {
              // Создаем объект
              CPar * obj = NewCParObject( cm, macro );
              if ( obj ) 
              {
                *enable  = obj->IsButtonEnable ( comm );
                if ( *enable )
                  *checked = obj->IsButtonChecked( comm );
                delete obj;
              }
            }
          }
        }
      }
    }  
  }
  return 0;
}



//------------------------------------------------------------------------------
// Проверят принадлежит ли макрообъект этой библиотеке
// В случае успеха вернет номер команды
// ---
extern int IsGaykaObj( reference obj )
{
  int res = 0, cmd = 0;
  TCHAR curLibName      [MAX_PATH] = _T(""); // Имя текущей библиотеки
  TCHAR macroLibName    [MAX_PATH] = _T(""); // Имя библиотеки макро
  TCHAR macroLibFileName[MAX_PATH] = _T(""); // Имя файла библиотеки макро
  LoadString( g_hInstance, ID_LIBID, curLibName, MAX_PATH );
  if ( ksGetMacroEditParamT(obj, macroLibFileName, MAX_PATH, macroLibName, MAX_PATH, &cmd) &&
       !_tcscmp(macroLibName, curLibName) )
    res = cmd;
  return res;
}


