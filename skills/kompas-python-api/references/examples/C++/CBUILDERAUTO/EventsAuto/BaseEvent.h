/////////////////////////////////////////////////////////////////////////////
//
// BaseEvent.h
// Базовый класс для обработчиков событий (Auto)
//
/////////////////////////////////////////////////////////////////////////////

#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#ifndef __UTILCLS_H
#include <utilcls.h>
#endif

#ifndef __LIBHPPAR_H
#include <libhppar.h>
#endif


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


//---------------------------------------------------------------------------
// BaseEvent базовый класс для обработчиков событий (преобразованный TEventsDispatcher)
// ---
class BaseEvent : public EventListObject, public IDispatch
{
  int       m_Ref;         // Счетчик
  DWORD     m_EventCookie; // Индекс подключения
  REFIID    m_refIID;      // IID события
protected:
  LPUNKNOWN m_pContainer;  // Источник событий
  long      m_objType;     // Тип объекта
  LPDISPATCH m_obj3D;      // Объект для 3D
  LPDISPATCH m_pDoc;       // Документ

public:
  BaseEvent( LPUNKNOWN  pContainer,
             REFIID     refIID,
             LPDISPATCH doc       =      NULL,
             long       objType   =         0,
             LPDISPATCH obj3D     =      NULL );
  virtual ~BaseEvent();

	static  void TerminateEvents( IID iid, // Отписать заданные события
																					 LPDISPATCH doc = NULL,
																					 long objType = -1,
																					 LPDISPATCH obj3D = NULL );
	static  BaseEvent* FindEvent( IID iid,       // Поиск подписки
                                     LPDISPATCH doc = NULL,
                                     long objType = -1,
                                     LPDISPATCH obj3D = NULL );

protected:
  virtual HRESULT InvokeEvent(DISPID id, BOOL & resEvent, TVariant * params = 0 ) = 0;

public:
  bool Advise();                    // Подписаться на получение событий
  void Unadvise();                  // Описаться от получения событий
  virtual   void      Clear();      // Очистка
            void      Disconnect(); // Отсоединиться

  // IUnknown
  HRESULT STDMETHODCALLTYPE QueryInterface( REFIID iid, void **ppvObject );
  ULONG   STDMETHODCALLTYPE AddRef(){ return ++m_Ref; };
  ULONG   STDMETHODCALLTYPE Release()
  {
    if ( !--m_Ref )
      delete this;
    return m_Ref;
  };


  // IDispatch
  HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctInfo);
  HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT, LCID, ITypeInfo** ppTypeInfo);
  HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*);
  HRESULT STDMETHODCALLTYPE Invoke( DISPID dispid, REFIID iid, LCID lcid,
                                    WORD wFlags, DISPPARAMS *pDispParams,
                                    VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
                                    UINT *puArgError);
};

int LibMessage( const TCHAR* str, int flags = MB_OK );
#endif



