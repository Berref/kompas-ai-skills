/////////////////////////////////////////////////////////////////////////////
//
// EventsList - Список подписчиков
// ABaseEvent - Базовый клас для обработчиков событий в автоматизации
// 
////////////////////////////////////////////////////////////////////////////
#ifndef _ABASEEVENT_H
#define _ABASEEVENT_H

#include "Ltdefine.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для автаматизационных обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
class ABaseEvent : public CCmdTarget
{
protected:
  static CObList&   m_EventList;  // Список обработчиков событий
  DWORD             m_dwCookie;   // Идентификатор соединения
  IID		            m_iidEvents;  // IID интерфейса событий
	LPCONNECTIONPOINT	m_pConnPt;    // Соединение 
  LPUNKNOWN         m_pContainer; // Источник событий
					
public:
           // Конструктор
	         ABaseEvent( LPUNKNOWN pObject,
                             IID iidEvents );
           // Диструктор
  virtual ~ABaseEvent();
  
  int          Advise();        // Подписаться на получение событий
  void         Unadvise();      // Отписаться от получения событий
  void         RemoveThis();    // Удалить себя из списка   
  virtual void Clear();         // Освободить интерфейсы
  void         Disconnect();    // Отсоединится

  static void TerminateEvents( void );                                // Отписать все события
  static void DestroyList();                                          // Удалить список событий     
  static void TerminateEvents( IID iid, LPUNKNOWN container = NULL ); // Отписаться по указателю на контейнер или типу
  static bool FindEvent( IID iid, LPUNKNOWN container = NULL );       // Найти подписку 

protected:
	BEGIN_INTERFACE_PART(EventHandler, IDispatch)
		INIT_INTERFACE_PART(BaseEvent, EventHandler)
		STDMETHOD(GetTypeInfoCount)(unsigned int*);
		STDMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**);
		STDMETHOD(GetIDsOfNames)( REFIID, LPOLESTR*, unsigned int, LCID, DISPID*);
		STDMETHOD(Invoke)(DISPID, REFIID, LCID, unsigned short, DISPPARAMS*,
 						  VARIANT*, EXCEPINFO*, unsigned int*);
	END_INTERFACE_PART(EventHandler)

  DECLARE_INTERFACE_MAP()
  DECLARE_EVENTSINK_MAP()
};




////////////////////////////////////////////////////////////////////////////////
#endif 
