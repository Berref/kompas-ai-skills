////////////////////////////////////////////////////////////////////////////////
//
// MacroObj.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "MacroObj.h"
#include "events\CBaseEvent.h"
#include "events\ABaseEvent.h"
#include <afxdllx.h>
#include <objbase.h>
#include <initguid.h> //  -  Definitions for controlling GUID initialization
// Include after compobj.h to enable GUID initialization.  This
//              must be done once per exe/dll.
// After this file, include one or more of the GUID definition files.
//
#include <libhppar.h>

#include "PropManager\cPropMen.h"
#include "events\ApplicationEvent.h"
#include "Orifice.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE MacroObjDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
ksAPI7::IApplicationPtr appl( NULL );

void OnProcessDetach();                                      // Отключение библиотеки


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  g_hInstance = hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("MACROOBJ.AWX Initializing!\n");

		AfxInitExtensionModule(MacroObjDLL, hInstance);

		new CDynLinkLibrary(MacroObjDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("MACROOBJ.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(MacroObjDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
	if ( !(ksAPI7::IApplication* )appl )
  {
		CString filename;
	
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
			filename.ReleaseBuffer( 255 );
			CString libname;

      libname = LoadStr( IDR_API7 );    // kAPI7.dll
			filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind(_T('\\')) + 1)), 
												libname );

			HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
		
      if(  hAppAuto ) 
      {
				// Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI * FCreateKompasApplication )(); 
				 
        FCreateKompasApplication pCreateKompasApplication = 
					(FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
				
        if ( pCreateKompasApplication )
					appl = IDispatchPtr ( pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
				FreeLibrary( hAppAuto );  
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}

extern long choiceID;
//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
     case 1: 
    {
      GetNewKompasAPI();
      
       Orifice * macroObj = new Orifice();
      if ( macroObj->InitProcessParam( ))
      {   
        macroObj->ChoiceFaces();
      }  
      
      break;
    }
  }
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  //Отписываемся от всех событий
  ABaseEvent::TerminateEvents();
  cBaseEvent::TerminateEvents();
  ABaseEvent::DestroyList();
  cBaseEvent::DestroyList();
  appl = NULL;
}

 
//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
int WINAPI LibInterfaceNotifyEntry( IDispatch * application ) 
{
  if ( !(bool)appl )
    appl = application; // Получаем интерфейс Компаса
  return 0;
}


//-------------------------------------------------------------------------------
// Использовать новое API
// ---
int WINAPI LibIsOnApplication7() 
{
  return 1;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[_MAX_PATH];
	LoadString( MacroObjDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


