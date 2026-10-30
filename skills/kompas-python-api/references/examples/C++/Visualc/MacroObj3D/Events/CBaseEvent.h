/////////////////////////////////////////////////////////////////////////////
//
// EventsList - Список подписчиков
// CBaseEvent - Базовый клас для обработчиков событий в автоматизации
// 
////////////////////////////////////////////////////////////////////////////
#ifndef _CBaseEvent_H
#define _CBaseEvent_H


/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий компаса 
//
/////////////////////////////////////////////////////////////////////////////
class CBaseEvent : public CCmdTarget
{
protected:
  static CObList&           m_EventList;  // Список обработчиков событий
  DWORD                     m_dwCookie;   // Идентификатор соединения
  NotifyConnectionParam     m_params;     // параметры подписки
	reference                 refDoc;       // референс документа для отписки   
	
public:
	          CBaseEvent( int       ifType     = 0, 
                        reference p          = 0, 
                        long      objType    = 0, 
                        reference doc        = 0 );
	          
            CBaseEvent( int       ifType, 
                        LPUNKNOWN iContainer = NULL,
                        long      objType    = 0, 
                        LPUNKNOWN iObj       = NULL, 
                        reference doc        = 0 );
  virtual  ~CBaseEvent();

            bool Advise         ();                            // Подписаться на получение событий
            void Unadvise       ();                            // Отписаться от получения событий
            void Disconnect     ();                            // Отсоединение     

  static    void TerminateEvents( void );                      // Отписать все события
  static    void DestroyList    ();                            // Удалить список      
            int  GetType        () { return m_params.ifType; } // Тип события

  static    void         TerminateEvents( long      eventType, 
                                          reference doc = 0, 
                                          int       objType = -1, 
                                          LPUNKNOWN iObj = NULL );  
  static    CBaseEvent * FindEvents     ( long      eventType, 
                                          reference doc = 0, 
                                          int       objType = -1, 
                                          LPUNKNOWN iObj = NULL );  
          
            long      GetDocReference() { return refDoc; }
  virtual   LPUNKNOWN GetUnknown     () = 0;

protected:
            void RemoveThis();                                 // Удалить себя из списка   
  virtual   void Clear     ();                                 // Освободить все захваченные интерфейсы 
};

// Подписка на события документа
void AdviseDoc       ( long pDoc );
// Подписка на события всех открытых документов
void AdviseDocuments();

////////////////////////////////////////////////////////////////////////////////
#endif 
