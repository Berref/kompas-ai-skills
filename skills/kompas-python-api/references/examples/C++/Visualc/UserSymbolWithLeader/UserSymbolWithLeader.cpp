////////////////////////////////////////////////////////////////////////////////
//
// UserSymbolWithLeader.cpp - Библиотека на Visual C++
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "UserSymbolWithLeader.h"
#include "events\ABaseEvent.h"
#include "PropManager\CPropMen.h"
#include "UserSymbol.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE UserSymbolWithLeaderDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
// KompasObjectPtr kompas( NULL );
IApplicationPtr newKompasAPI( NULL );               

void OnProcessDetach();                            // Отключение библиотеки



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
		TRACE0("USERSYMBOLWITHLEADER.AWX Initializing!\n");

		AfxInitExtensionModule(UserSymbolWithLeaderDLL, hInstance);

		new CDynLinkLibrary(UserSymbolWithLeaderDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("USERSYMBOLWITHLEADER.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(UserSymbolWithLeaderDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
  if ( !( IApplication * )newKompasAPI ) 
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
          newKompasAPI = IDispatchPtr ( pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
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


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
    case 1: 
    {
      // Выдача сообщения пользователю
      GetNewKompasAPI();
      if ( newKompasAPI )
      {
        UserSymbol * obj = new UserSymbol;
        obj->Draw();
      }
      break;
    }
  }
}


//-----------------------------------------------------------------------------
// Получить начало диапазона иконок для команд библиотеки
// ---
int WINAPI LibraryBmpBeginID( unsigned int bmpSizeType )
{
  int res = 0;
  switch ( bmpSizeType )
  {
    case ksBmp1616: res = 1000; break;
    case ksBmp2424: res = 1000; break;
    case ksBmp3232: res = 1000; break;
    case ksBmp4848: res = 1000; break;
  }
  return res;
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  ABaseEvent::TerminateEvents();
  ABaseEvent::DestroyList();

  newKompasAPI = NULL;
}

 
//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
int WINAPI LibInterfaceNotifyEntry( IDispatch * application ) 
{
  if ( !newKompasAPI )
    newKompasAPI = application;

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
	LoadString( UserSymbolWithLeaderDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


