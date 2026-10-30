/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий в автоматизации
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxpriv.h>

#ifndef _ABASEEVENT_H
#include "abaseEvent.h"
#endif
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Список подписчиков
// ---
CObList& cBaseEvent::m_EventList = *new CObList();


/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий 
//
/////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
cBaseEvent::cBaseEvent( int ifType, reference p, long objType, reference doc ) 
  : CCmdTarget(   ),  
    m_dwCookie( 0 ),
    refDoc    ( doc )
{
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
  m_params.pContainer = p;
  m_params.ifType     = ifType;
  m_params.objType    = objType;
  m_EventList.AddTail( this ); 
}

//-------------------------------------------------------------------------------
// Конструктор
// ---
cBaseEvent::cBaseEvent( int ifType, LPUNKNOWN iContainer, long objType, LPUNKNOWN iObj, reference doc )
  : CCmdTarget(   ),  
    m_dwCookie( 0 ),
    refDoc( doc )
{
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
  m_params.ifType     = ifType;
  m_params.objType    = objType;

  m_params.iContainer = iContainer;
  if ( m_params.iContainer )
    m_params.iContainer->AddRef();
  
  m_params.iObj       = iObj;
  if ( m_params.iObj )
    m_params.iObj->AddRef();
  
  m_EventList.AddTail( this ); 
}

//-------------------------------------------------------------------------------
// Деструктор
// ---
cBaseEvent::~cBaseEvent()
{
  RemoveThis();  // Удалим себя из списка обработчиков событий
}

//-------------------------------------------------------------------------------
// Подписаться на получение событий
// ---
bool cBaseEvent::Advise() 
{
  ASSERT(!m_dwCookie);
  if( !m_dwCookie && m_params.ifType ){
		if ( ReturnResult() ) {
      #ifdef _DEBUG
      MessageBoxResult();
      #endif
      ResultNULL();
		}
    LPUNKNOWN obj = GetUnknown();
    m_dwCookie = ::ksConnectionAdvise ( &m_params, obj );
    obj->Release();
    ASSERT(m_dwCookie);
  }
	return !!m_dwCookie;
}

//-----------------------------------------------------------------------------
// Отписаться
// ---
void cBaseEvent::Unadvise()
{
  if( m_dwCookie )
  {
    VERIFY( ::ksConnectionUnadvise( &m_params ) ); 
    m_dwCookie = 0; 
  }
}

//-----------------------------------------------------------------------------
// отписаться от событий
// ---
void cBaseEvent::TerminateEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
	for ( INT_PTR i = m_EventList.GetCount() - 1; i >= 0; i-- ) {
  	cBaseEvent* evnt = (cBaseEvent*)m_EventList.GetAt( m_EventList.FindIndex(i) );
		if ( evnt && ( !eventType    || eventType == evnt->GetType()        ) 
			        && ( !doc          || doc       == evnt->refDoc           ) 
							&& ( objType == -1 || objType   == evnt->m_params.objType ) 
							&& ( !iObj         || iObj      == evnt->m_params.iObj    ) ) {
								
		  evnt->Disconnect();			
		}
	}
}

//-----------------------------------------------------------------------------
// отписаться от событий
// ---
cBaseEvent * cBaseEvent::FindEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
  cBaseEvent * res = NULL;
  for ( INT_PTR i = m_EventList.GetCount() - 1; i >= 0; i-- ) {
	  cBaseEvent* evnt = (cBaseEvent*) m_EventList.GetAt( m_EventList.FindIndex(i) );
		if (    (   !eventType                                 ||   eventType == evnt->GetType()        ) 
			   && ( ( !doc          && !evnt->refDoc           ) || ( doc       == evnt->refDoc           ) )
			   && ( ( objType == -1 && !evnt->m_params.objType ) || ( objType   == evnt->m_params.objType ) ) 
			   && ( ( !iObj         && !evnt->m_params.iObj    ) || ( iObj      == evnt->m_params.iObj    ) ) ) {
		  res = evnt;			
      break;
		}
	}
	return res;
}

//-----------------------------------------------------------------------------
// отписать все события
// ---
void cBaseEvent::TerminateEvents( void )
{
  while ( !m_EventList.IsEmpty() ) {
	  cBaseEvent* headEvent = (cBaseEvent*)m_EventList.RemoveHead();
		headEvent->Disconnect();			
  }
}

//-------------------------------------------------------------------------------
// Удалить список
// ---
void cBaseEvent::DestroyList() {
  if ( &m_EventList ) {
    delete &m_EventList;
  }
}

//-------------------------------------------------------------------------------
// Удалить себя из списка 
// ---
void cBaseEvent::RemoveThis() {
	// Удалим себя из списка обработчиков событий
	POSITION pos = m_EventList.Find(this);
  if ( pos ) { 
  	m_EventList.RemoveAt( pos );
    Unadvise();                           // Отпишемся от получения событий
  }
}

//-------------------------------------------------------------------------------
// 
// ---
void cBaseEvent::Clear() 
{
  if ( m_params.iContainer ) {
    m_params.iContainer->Release();
    m_params.iContainer = NULL;
  }

  if ( m_params.iObj ) {
    m_params.iObj->Release();
    m_params.iObj = NULL;
  }
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
}

//-------------------------------------------------------------------------------
// Отсоединиться
// ---
void cBaseEvent::Disconnect()      
{
  Unadvise();
  Clear();
  ExternalRelease();
}
