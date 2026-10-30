/////////////////////////////////////////////////////////////////////////////
//
// BaseEvent.h
// Базовый класс для обработчиков событий (COM)
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#ifndef __LIBTOOL_H
#include <Libtool.h>
#endif

#include <kAPI2D5COM.h>

//---------------------------------------------------------------------------
// Класс счетчик
// ---
class EventListObject
{
protected:
  static TList * m_pEventList;

public:
  // Отписать все события
  // Вызывается по выходу из библиотеки
  static void TerminateEvents();

  EventListObject();
  virtual ~EventListObject();
};


class BaseEvent : public EventListObject {
protected:
  int                   m_Ref;    // Счетчик
  bool                  m_Advise; // Подписка ( true - сделан Advise )
  NotifyConnectionParam m_Params; // Параметры подписки
  reference             refDoc;
public:
                      BaseEvent( int ifType = 0, reference container = 0, reference doc = 0, reference objType = 0 );
  virtual            ~BaseEvent();
static    void        TerminateEvents( long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );
static    BaseEvent*  FindEvents( long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );

  virtual   LPUNKNOWN GetUnknown() { return NULL; }
            bool      Advise();     // Подписаться на получение событий
            void      Unadvise();   // Описаться от получения событий
  virtual   void      Clear();      // Очистка
            void      Disconnect(); // Отсоединиться

  ULONG   __AddRef(){ return ++m_Ref; };
  ULONG   __Release(){
    if ( !--m_Ref )
      delete this;
    return m_Ref;
  };

  int GetType() { return m_Params.ifType; }

};

//---------------------------------------------------------------------------
// BaseEvent базовый класс для обработчиков событий (преобразованный TEventsDispatcher)
// ---
template <class NotifyInteface, const IID * pNotifyIID>
class TBaseEvent : public BaseEvent, public NotifyInteface
{

public:
  TBaseEvent( int ifType = 0, reference container = 0, reference doc = 0, reference objType = 0 );
  virtual ~TBaseEvent(){}
  virtual   LPUNKNOWN GetUnknown();

  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void **ppvObject);

  ULONG   STDMETHODCALLTYPE AddRef()  { return __AddRef();   }
  ULONG   STDMETHODCALLTYPE Release() { return __Release(); }
  
};


//-------------------------------------------------------------------------------
// Конструктор с подключением к серверу сообщений
// ---
template <class NotifyInteface, const IID * pNotifyIID>
TBaseEvent<NotifyInteface, pNotifyIID>::TBaseEvent( int ifType, reference container, reference doc, reference objType  ) :
  BaseEvent( ifType, container, doc, objType )

{
}

//---------------------------------------------------------------------------
// Преобразование
// ---
template <class NotifyInteface, const IID * pNotifyIID>
HRESULT STDMETHODCALLTYPE TBaseEvent<NotifyInteface, pNotifyIID>::QueryInterface(REFIID iid, void **ppvObject)
{
  *ppvObject = 0;
  if ( iid == IID_IUnknown || iid == * pNotifyIID )
  {
    (this)->AddRef();
    *ppvObject = this;
  }
  else
    return E_NOINTERFACE;

  return S_OK;
}

//---------------------------------------------------------------------------
// Преобразование
// ---
template <class NotifyInteface, const IID * pNotifyIID>
LPUNKNOWN TBaseEvent<NotifyInteface, pNotifyIID>::GetUnknown() {
  AddRef();
  return this;
}


#endif

