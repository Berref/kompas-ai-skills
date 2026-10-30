/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий в автоматизации
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include <afxpriv.h>

#include "CBaseEvent.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Список подписчиков
// ---
CObList & CBaseEvent::m_EventList = * new CObList();



/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий 
//
/////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
CBaseEvent::CBaseEvent( int ifType, reference p, long objType, reference doc ) 
  : CCmdTarget(   ),  
    m_dwCookie( 0 ),
    refDoc( doc )
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
CBaseEvent::CBaseEvent( int ifType, LPUNKNOWN iContainer, long objType, LPUNKNOWN iObj, reference doc )
  : CCmdTarget(   ),  
    m_dwCookie( 0 ),
    refDoc( doc )
{
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
  m_params.pContainer = doc;
  m_params.ifType     = ifType;
  m_params.iContainer = iContainer;
  m_params.objType    = objType;
  m_params.iObj       = iObj;

  if ( m_params.iContainer )
    m_params.iContainer->AddRef();

  if ( m_params.iObj )
    m_params.iObj->AddRef(); 

  m_EventList.AddTail( this ); 
}


//-------------------------------------------------------------------------------
// Деструктор
// ---
CBaseEvent::~CBaseEvent()
{
  RemoveThis();  // Удалим себя из списка обработчиков событий
}


//-------------------------------------------------------------------------------
// Подписаться на получение событий
// ---
bool CBaseEvent::Advise() 
{
  ASSERT(!m_dwCookie);
  if( !m_dwCookie && m_params.ifType )
  {
		if ( ReturnResult() ) 
    {
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
void CBaseEvent::Unadvise()
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
void CBaseEvent::TerminateEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
	for ( int i = m_EventList.GetCount() - 1; i >= 0; i-- ) 
  {
  	CBaseEvent * evnt = (CBaseEvent *)m_EventList.GetAt( m_EventList.FindIndex(i) );
		if ( evnt && ( !eventType    || eventType == evnt->GetType()        ) 
			        && ( !doc          || doc       == evnt->refDoc           ) 
							&& ( objType == -1 || objType   == evnt->m_params.objType ) 
							&& ( !iObj         || iObj      == evnt->m_params.iObj    ) ) 
    {
								
		    evnt->Disconnect();			// в деструкторе будет удален из списка RemoveAt(pos)
		}
	}
}


//-----------------------------------------------------------------------------
// отписаться от событий
// ---
CBaseEvent * CBaseEvent::FindEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
  CBaseEvent * res = NULL;
  for ( int i = m_EventList.GetCount() - 1; i >= 0; i-- ) 
  {
	  CBaseEvent * evnt = (CBaseEvent *) m_EventList.GetAt( m_EventList.FindIndex(i) );
	  if (    ( !eventType                                   ||   eventType == evnt->GetType()        ) 
		     && ( ( !doc          && !evnt->refDoc           ) || ( doc       == evnt->refDoc           ) )
			   && ( ( objType == -1 && !evnt->m_params.objType ) || ( objType   == evnt->m_params.objType ) ) 
			   && ( ( !iObj         && !evnt->m_params.iObj    ) || ( iObj      == evnt->m_params.iObj    ) ) ) 
    {
		  res = evnt;			// в деструкторе будет удален из списка RemoveAt(pos)
      break;
		}
	}
	return res;
}


//-----------------------------------------------------------------------------
// отписать все события
// ---
void CBaseEvent::TerminateEvents( void )
{
  while ( !m_EventList.IsEmpty() ) 
  {
	  CBaseEvent * headEvent = (CBaseEvent *)m_EventList.RemoveHead();
		headEvent->Disconnect();				// в деструкторе будет удален из списка RemoveAt(pos)
  }
}


//-------------------------------------------------------------------------------
// Удалить список
// ---
void CBaseEvent::DestroyList() 
{
  if ( &m_EventList ) 
  {
    delete &m_EventList;
  }
}


//-------------------------------------------------------------------------------
// Удалить себя из списка 
// ---
void CBaseEvent::RemoveThis() 
{
	// Удалим себя из списка обработчиков событий
	POSITION pos = m_EventList.Find(this);
  if ( pos ) 
  { 
  	m_EventList.RemoveAt( pos );
    Unadvise();                           // Отпишемся от получения событий
  }
}


//-------------------------------------------------------------------------------
// Очиститка
// ---
void CBaseEvent::Clear() 
{
 if ( m_params.iContainer ) 
 {
    m_params.iContainer->Release();
    m_params.iContainer = NULL;
  }

  if ( m_params.iObj ) 
  {
    m_params.iObj->Release();
    m_params.iObj = NULL;
  }
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );  
}


//-------------------------------------------------------------------------------
// Отсоединение
// ---
void CBaseEvent::Disconnect()                    
{
  Unadvise();
  Clear();
  ExternalRelease();
}


//-------------------------------------------------------------------------------
// Подписка на события документа
// ---
void AdviseDoc( long pDoc )
{
	if ( !pDoc )
		pDoc = ::ksGetCurrentDocument( 0 );
	else
    ::SetObjParam(pDoc, NULL, 0, DOCUMENT_STATE);
	if ( pDoc ) 
  {
		int docType = ::ksGetDocumentType( pDoc );
	}
}


//-------------------------------------------------------------------------------
// Подписка на события документа
// ---
void AdviseDocuments()
{
  // Cоздаем итератор для хождения по документам
  reference iter = ::CreateIterator( ALL_DOCUMENTS, 0 );
  
  if ( iter ) 
  {
    reference pDoc = ::MoveIterator( iter, 'F' );

    while ( pDoc )
    {
	    AdviseDoc( pDoc );
	    pDoc = ::MoveIterator( iter, 'N' );
    } 
    ::DeleteIterator( iter );
  }
}

