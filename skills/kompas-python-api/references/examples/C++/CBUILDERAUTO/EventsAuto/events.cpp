/////////////////////////////////////////////////////////////////////////////
//
// Пример 2 обработки сообщений Builder C++ (Auto)
//
/////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

#ifndef _OBJECT2DEVENT_H
#include "Object2DEvent.h"
#endif

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif

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
  inline wchar_t * TO_OLE(wchar_t *x) { return x; }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).c_bstr(); }
#else
//#pragma message(  __TODO__ "Рекомендуется добавить в настройки проекта определение VARIANT_COPIES_BSTR\n" )
// подробнее см http://sites.google.com/site/akxsolutions/articles/borland-c-dicom
  inline wchar_t * TO_OLE(wchar_t *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
#endif

//------------------------------------------------------------------------------
//
// ---
ApplicationEvent * aplEvent = NULL;
KompasObjectPtr kompasPtr;

//------------------------------------------------------------------------------
//
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( const TCHAR* str, int flags ) {
  int res = 0;
  if ( str && str[0] ) {                  // строка передана
    if ( kompasPtr ) {
      bool enabse = kompasPtr->ksIsEnableTaskAccess(); // проверка доступа
      if ( enabse )                                    // если доступ к задаче разрешен
        kompasPtr->ksEnableTaskAccess(0);                // запрещаем доступ

      //                             текст сообщения  заголовок                    параметры
#ifdef _DELPHI_STRING_UNICODE
      res = Application->MessageBox( WideString(str).c_bstr(),   LoadStr(LIBRARYID()).c_str(), flags );
#else
			res = Application->MessageBox( str,   LoadStr(LIBRARYID()).c_str(), flags );
#endif
      if ( enabse )                         // если доступ к задаче был запрещен
        kompasPtr->ksEnableTaskAccess(1);              // разрешаем доступ к задаче
    }
  }

  return res;
}

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch * __export WINAPI CreateKompasObject();


//-------------------------------------------------------------------------------
//
// ---
void AdviseDoc( IUnknownPtr docPtr, long docType )
{
  if ( kompasPtr )
  {
    if( docPtr )
    {
      NewDocumentEvent( docPtr );
      switch ( docType )
      {
        case lt_DocSheetStandart : // 1 - чертеж стандартный
        case lt_DocSheetUser     : // 2 - чертеж нестандартный
        case lt_DocFragment      : // 3 - фрагмент
        {
          ksDocument2DPtr doc2DPtr( docPtr ); // Интерфейс документа
          long type = ALL_OBJ;
          new Object2DEvent( doc2DPtr->GetObject2DNotify( type ) ); // Обработчик событий от документа
          break;
        }
        case lt_DocPart3D     : // 5 - 3d-документ модель
        case lt_DocAssemble3D : // 6 - 3d-документ сборка
        {
          // ksDocument3DPtr doc( pDoc ); // Интерфейс документа
          break;
        }
        case lt_DocTxtStandart : // 7- текстовый документ стандартный
        case lt_DocTxtUser     : // 8- текстовый документ нестандартный
        {
          // ksDocumentTxtPtr doc( pDoc ); // Интерфейс документа
          break;
        }
        case lt_DocSpcUser : // 9- спецификация нестандартный формат
        case lt_DocSpc     : // 4- спецификация
        {
          // ksSpcDocumentPtr doc( pDoc ); // Интерфейс документа
          break;
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
//
// ---
void AdviseDoc( reference refDocument )
{
  if( kompasPtr )
    AdviseDoc( kompasPtr->ksGetDocumentByReference( refDocument ),
               kompasPtr->ksGetDocumentType( refDocument ) );
}


//------------------------------------------------------------------------------
//
// ---
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  if( reason == DLL_PROCESS_DETACH && aplEvent ) {
    EventListObject::TerminateEvents();
    Application->Handle = NULL;
  }
  return 1;
}



//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  if ( !kompasPtr ) {
   kompasPtr = IDispatchPtr( CreateKompasObject(), false/*AddRef*/ );
   if ( kompasPtr )
     Application->Handle = (HWND)(kompasPtr->ksGetHWindow());
  }  
  if ( kompasPtr ) {
    switch ( comm ) {

      case 10: {
        if ( !aplEvent ) {
          aplEvent = new ApplicationEvent( kompasPtr );
          if ( !aplEvent->Advise() ) {
            delete aplEvent;
            aplEvent = NULL;
            LibMessage( _T("Не подписались") );
          }
          else
            LibMessage( _T("Подписались") );
        }
        else
          LibMessage( _T("Уже подписались") );
        break;
      }

      case 11: {
        if ( aplEvent ) {
          delete aplEvent;
          aplEvent = NULL;
          LibMessage( _T("Описались") );
        }
        else
          LibMessage( _T("Подписка не найдена") );
        break;
      }

      case 20: {
        IDispatchPtr doc( kompasPtr->ksGetDocumentByReference(0), false/*AddRef*/ );
//        long docType = kompasPtr->ksGetDocumentType( 0 );
        if ( doc ) {
          if ( !BaseEvent::FindEvent( DIID_ksDocumentFileNotify, (IDispatch*)doc ) ) {
            if ( NewDocumentEvent( doc ) )
              LibMessage( _T("Подписались на события документа") );
            else
              LibMessage( _T("Подписаться не удалось") );
          }
          else
            LibMessage( _T("Уже подписались") );
        }
        else
          LibMessage( _T("Нет активного документа") );
      }

      case 21: {
        IDispatchPtr doc( kompasPtr->ksGetDocumentByReference( 0 ), false/*AddRef*/ );
        if ( doc ) {
          BaseEvent::TerminateEvents( GUID_NULL, (IDispatch*) doc );
          if ( !BaseEvent::FindEvent( GUID_NULL, (IDispatch*) doc ) )
            LibMessage( _T("Отписались от всех событий для текущего документа") );
          else
            LibMessage( _T("Отписаться от всех событий для текущего документа не удалось") );
        }
        else
          LibMessage( _T("Нет активного документа") );
        break;
      }
    }
  }
}


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
extern "C" bool far __export WINAPI LibInterfaceNotifyEntry( IDispatch *application )
{
  kompasPtr.Bind( (KompasObject*)application, true/*Addref*/);

  if( kompasPtr )
  {
    Application->Handle = (HWND)kompasPtr->ksGetHWindow();
    aplEvent = new ApplicationEvent( kompasPtr ); // Обработчик событий приложения КОМПАС

    ksIteratorPtr iIterator = kompasPtr->GetIterator(); // Интерфейс итератора

    // Ссоздаем итератор для хождения по документам
    if ( iIterator->ksCreateIterator( ALL_DOCUMENTS, 0 ) )
    {
      reference rDocument = iIterator->ksMoveIterator( TO_OLE(L"F") ); // Первый документ

      while ( rDocument )
      {
        // Подписка на события документа
        AdviseDoc( rDocument );
        rDocument = iIterator->ksMoveIterator( TO_OLE(L"N") ); // Следующий документ
      }

      iIterator->ksDeleteIterator(); // Удалить итератор
    }
  }

  return false;
}
