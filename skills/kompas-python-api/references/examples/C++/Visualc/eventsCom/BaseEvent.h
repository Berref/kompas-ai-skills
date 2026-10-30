#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
class BaseEvent : public CCmdTarget
{
public:
  static  CObList&          m_EventList;  // список обработчиков событий
protected:
  bool                      m_advise;     // true - сделан Advise
  NotifyConnectionParam     m_params;     // параметры подписки
	reference                 refDoc;       // референс документа для отписки   
//	bool                      showEventName;
//	bool                      showEventParam;
	
// Operations
public:
	          BaseEvent( int ifType = 0,  reference p = 0, long objType = 0,                        reference doc = 0 );
	          BaseEvent( int ifType, LPUNKNOWN iContainer, long objType = 0, LPUNKNOWN iObj = NULL, reference doc = 0 );
  virtual ~ BaseEvent();

virtual   bool      Advise(); // подписаться на получение событий
virtual   void      Unadvise();                                   // отписаться от получения событий
          int       GetType() { return m_params.ifType; } 

static    void      TerminateEvents( void );                      // отписать все события
static    void      TerminateEvents( long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );  
static    BaseEvent*FindEvents(      long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );  
static    void      ListEvents();
virtual   CString   EventCaption() { return ""; }              
          long      GetDocReference() { return refDoc; } 
virtual   LPUNKNOWN GetUnknown() = 0;

          void      ShowGroupParam( reference gr );  
virtual   void      ShowObjParam( long obj );
virtual   void      ShowObjParam( LPUNKNOWN obj );
          void      ShowEventName( LPTSTR eventName );
					void      Disconnect(); 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BaseEvent)
	//}}AFX_VIRTUAL

// Implementation
protected:

  virtual void      Clear();  // Освободить все захваченные интерфейсы
                              // Вызывать после Unadvise в TerminateEvents и в диструкторе   
	
	// Generated message map functions
	//{{AFX_MSG(BaseEvent)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG



};

void  _ShowEventName( LPCTSTR eventName );

// Подписка на события документа
void AdviseDoc( long pDoc = 0 );
CString GetDocumentParam( reference doc );


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
