/////////////////////////////////////////////////////////////////////////////
//
// EventsList - Список подписчиков
// ABaseEvent - Базовый клас для обработчиков событий в автоматизации
// 
////////////////////////////////////////////////////////////////////////////
#ifndef _ABASEEVENT_H
#define _ABASEEVENT_H


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
  LPDISPATCH        m_doc;        // Документ
  long              m_objType;    // Тип объекта
  LPDISPATCH        m_obj3D;
					
public:
           // Конструктор
	         ABaseEvent( LPUNKNOWN    pObject,
                       IID          iidEvents,
                       LPDISPATCH   doc       = NULL,
                       long         objType   = -1,
                       LPDISPATCH   obj3D     = NULL );

           // Деструктор
  virtual ~ABaseEvent();
  
  int          Advise    ();      // Подписаться на получение событий
  void         Unadvise  ();      // Отписаться от получения событий
  void         RemoveThis();      // Удалить себя из списка   
  
  void         Disconnect();      // Рассоединиться
  virtual void Clear     ();  

  static  void DestroyList    ();                             // Удалить список      
  static  void TerminateEvents( void );                       // Отписать все события
  static  void TerminateEvents( LPUNKNOWN  container );
  static  void TerminateEvents( IID        iid,               // Отписать заданные события
                                LPDISPATCH doc     = NULL, 
                                long       objType = -1,
                                LPDISPATCH obj3D   = NULL );  
  static  ABaseEvent * FindEvent( IID        iid,               // Поиск подписки
                                  LPDISPATCH doc     = NULL, 
                                  long       objType = -1,
                                  LPDISPATCH obj3D   = NULL );
  
  static  ABaseEvent * FindEventByContainer( IID iid, LPUNKNOWN pObject ); 
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
