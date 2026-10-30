/////////////////////////////////////////////////////////////////////////////
//
// EventsList - Список подписчиков
// ABaseEvent - Базовый класс для обработчиков событий в автоматизации
// 
////////////////////////////////////////////////////////////////////////////
#ifndef _ABASEEVENT_H
#define _ABASEEVENT_H

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif       
   
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий компаса 
//
/////////////////////////////////////////////////////////////////////////////
class cBaseEvent : public CCmdTarget
{
protected:
  static CObList&           m_EventList;  // Список обработчиков событий
  DWORD                     m_dwCookie;   // Идентификатор соединения
  NotifyConnectionParam     m_params;     // параметры подписки
	reference                 refDoc;       // референс документа для отписки   
	
// Operations
public:
	          cBaseEvent( int ifType, reference p = 0, long objType = 0, reference doc = 0 );
	          cBaseEvent( int ifType, LPUNKNOWN iContainer = NULL, long objType = 0, LPUNKNOWN iObj = NULL, reference doc = 0 );
  virtual  ~cBaseEvent();

  bool         Advise();                   // Подписаться на получение событий
  void         Unadvise();                 // Отписаться от получения событий
  void         RemoveThis();               // Удалить себя из списка   
  void         Disconnect();               // Отсоединиться   
  virtual void Clear();                    // Освободить ссылки   

  static void  TerminateEvents( void );    // Отписать все события
  static void  DestroyList();              // Удалить список      
         int   GetType() { return m_params.ifType; } // Тип события

  static void        TerminateEvents( long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );  
  static cBaseEvent* FindEvents(      long eventType, reference doc = 0, int objType = -1, LPUNKNOWN iObj = NULL );  

  virtual LPUNKNOWN  GetUnknown() = 0;
   
};


////////////////////////////////////////////////////////////////////////////////
#endif 
