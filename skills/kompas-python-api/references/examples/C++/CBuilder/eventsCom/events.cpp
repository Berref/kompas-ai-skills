#include <vcl.h>
#pragma hdrstop
/////////////////////////////////////////////////////////////////////////////
//
// Пример 3 обработки сообщений Builder C++ (COM)
//
/////////////////////////////////////////////////////////////////////////////

#include <objbase.h>
#include <initguid.h> // Definitions for controlling GUID initialization
// Include after compobj.h to enable GUID initialization.  This
// must be done once per exe/dll.
// After this file, include one or more of the GUID definition files.
//

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#include <ksConstants.h>

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

extern BaseEvent* NewDocumentEvent( reference doc );

//------------------------------------------------------------------------------
//
// ---
int WINAPI DllEntryPoint(HINSTANCE , unsigned long reason, void* )
{
  if( reason == DLL_PROCESS_DETACH ) {
    EventListObject::TerminateEvents();
    Application->Handle = NULL;
  }
  if( reason == DLL_PROCESS_ATTACH )
    Application->Handle = (HWND)::GetHWindow();

  return 1;
}


//------------------------------------------------------------------------------
//
// ---
extern "C" int far __export __stdcall LIBRARYID()
{
  return 100;
}

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( char* str, int flags = MB_OK ) {
  int res = 0;

  if ( str && str[0] ) {                  // строка передана
    bool enabse = ::IsEnableTaskAccess(); // проверка доступа
    if ( enabse )                         // если доступ к задаче разрешен
      ::EnableTaskAccess(0);              // запрещаем доступ

    //                             текст сообщения  заголовок                    параметры
#if !defined( _UNICODE ) && !defined( _DELPHI_STRING_UNICODE )
    res = Application->MessageBox( str,   LoadStr(LibraryID()).c_str(), flags );
#else
    res = Application->MessageBox( WideString(str).c_bstr(),   LoadStr(LIBRARYID()).c_str(), flags );
#endif
    if ( enabse )                         // если доступ к задаче был запрещен
      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  }

  return res;
}

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall LIBRARYENTRY( int comm )
{

  switch ( comm ) {

    // Подписаться на события приложения Компас
    case 10 : {
      if ( !BaseEvent::FindEvents( ntKompasObjectNotify ) ) {
        ApplicationEvent * aplEvent = new ApplicationEvent();  // обработчик событий приложения КОМПАС
        if ( aplEvent->Advise() )            // подписка на события приложения КОМПАС
          ::LibMessage( "Подписались на события приложения КОМПАС" );
        else {
          ::LibMessage( "Подписаться не удалось", MB_OK | MB_ICONERROR );
          delete aplEvent;
          aplEvent = 0;
        }
      }
      else
        ::LibMessage( "Уже подписались" );
      break;
    }

    // Отписаться от событий приложения Компас
    case 11 : {
      if ( BaseEvent::FindEvents( ntKompasObjectNotify ) ) {
        EventListObject::TerminateEvents();
        ::LibMessage( "Отписались" );
      }
      else
        ::LibMessage( "Подписка не найдена" );
      break;
    }

    // Подписаться на события документа
    case 20: {
      reference doc = ::ksGetCurrentDocument( 0 );
      if ( doc ) {
        if ( !BaseEvent::FindEvents( ntDocumentFileNotify, doc ) ) {
          if ( NewDocumentEvent( doc ) )
            ::LibMessage( "Подписались на события документа" );
          else
            ::LibMessage( "Подписаться не удалось" );
        }
        else
          ::LibMessage( "Уже подписались" );
      }
      else
        ::LibMessage( "Нет активного документа" );
      break;
    }

    // Отписаться от событий текущего документа документа
    case 21: {
      reference doc = ::ksGetCurrentDocument( 0 );
      if ( doc ) {
        BaseEvent::TerminateEvents( 0, doc );
        if ( !BaseEvent::FindEvents( 0, doc ) )
          ::LibMessage( "Отписались от всех событий для текущего документа" );
        else
          ::LibMessage( "Отписаться от всех событий для текущего документа не удалось" );
      }
      else
        ::LibMessage( "Нет активного документа" );

      break;
    }

  }

}


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
extern "C" bool far __export WINAPI LibInterfaceNotifyEntry( IDispatch * )
{
  new ApplicationEvent(); // Обработчик событий приложения КОМПАС
  return false;
}



