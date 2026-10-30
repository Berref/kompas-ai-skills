#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
class CBaseEvent : public CCmdTarget
{
protected:
  static CObList m_EventList; // Список обработчиков событий

  DWORD m_dwCookie;      // Уникальный идентификатор соединения
  IID m_iidEvents;
  LPCONNECTIONPOINT m_pConnPt;
  LPUNKNOWN m_pContainer;    // Источник событий
    
public:
  CBaseEvent( LPUNKNOWN pContainer, const IID & iidEvents );
  virtual ~CBaseEvent();
  

  virtual int  Advise();    // Подписаться на получение событий
  virtual void Unadvise();  // Отписаться от получения событий
          void Disconnect();
  virtual void Clear(){}
  virtual int  EventID() { return 0; } 
  static void CBaseEvent::TerminateEvents(void);  // Отписать все события
  // Отписать заданные события
  static void CBaseEvent::TerminateEvents( const IID & iid, LPUNKNOWN m_pContainer );  

  // Поиск подписки
  static CBaseEvent * CBaseEvent::FindEvent( const IID & iid, LPUNKNOWN m_pContainer );

protected: 
  BEGIN_INTERFACE_PART(EventHandler, IDispatch)
    INIT_INTERFACE_PART(BaseEvent, EventHandler)
    STDMETHOD(GetTypeInfoCount)(unsigned int*);
    STDMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**);
    STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, unsigned int, LCID, DISPID*);
    STDMETHOD(Invoke)(DISPID, REFIID, LCID, unsigned short, DISPPARAMS*, VARIANT*, EXCEPINFO*, unsigned int*);
  END_INTERFACE_PART(EventHandler)

  DECLARE_INTERFACE_MAP()
  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий Компаса
//
/////////////////////////////////////////////////////////////////////////////
class KSBaseEvent : public CBaseEvent
{
  enum
  {
    ksEvent = 1,
  };
protected:

  // Идентификационные данные
  LPDISPATCH m_doc;     
  KompasObjectPtr kompas;

public:
  KSBaseEvent( LPUNKNOWN pObject, IID iidEvents, LPDISPATCH doc = NULL );
  virtual ~KSBaseEvent();
  
  void SetKompas(KompasObjectPtr & _kompas) { kompas = _kompas; }

  virtual void Clear();
  virtual int  EventID() { return ksEvent; }  

  static void KSBaseEvent::TerminateAllKompasEvents(void);  // Отписать все события
  
  // Отписать заданные события
  static void KSBaseEvent::TerminateEvents(IID iid, LPUNKNOWN m_pContainer, LPDISPATCH doc );  

  // Поиск подписки
  static CBaseEvent * KSBaseEvent::FindEvent(IID iid, LPUNKNOWN m_pContainer, LPDISPATCH doc );

};

#endif 
