/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий в автоматизации
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxctl.h>
#include <afxpriv.h>
#include "ABaseEvent.h"

 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Список подписчиков
// ---
CObList& ABaseEvent::m_EventList = *new CObList();



/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для автоматизационных обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
// Конструктор 
// ---
ABaseEvent::ABaseEvent( LPUNKNOWN    pObject, 
                        IID          iidEvents,
                        LPDISPATCH   doc,      /*NULL*/
                        long         objType,  /*-1*/
                        LPDISPATCH   obj3D     /*NULL*/ ) 
  : CCmdTarget  (           ),  
    m_dwCookie  ( 0         ),
    m_pContainer( pObject   ),                 // Источник событий
    m_iidEvents ( iidEvents ),                 // IID
    m_pConnPt   ( NULL      ),
    m_doc       ( doc       ),                 // Документ
    m_objType   ( objType   ),                 // Тип объекта
    m_obj3D     ( obj3D     )                 // Объект для 3D
{
  if ( m_pContainer ) 
    m_pContainer->AddRef();
  
  if ( m_doc )
	  m_doc->AddRef();

  if ( m_obj3D )
	  m_obj3D->AddRef();

  ASSERT( !IsEqualIID(m_iidEvents, GUID_NULL) ); // Прислали тип событий
  m_EventList.AddTail( this ); 
}


//-------------------------------------------------------------------------------
// Деструктор
// ---
ABaseEvent::~ABaseEvent()
{
	RemoveThis();
  if ( m_pContainer ) 
  {
    m_pContainer->Release();
	  m_pContainer = NULL;     
  }
  
  if ( m_doc ) 
  {
	  m_doc->Release();
		m_doc = NULL;
	}

 if ( m_obj3D ) 
  {
	  m_obj3D->Release();
		m_obj3D = NULL;
	}
}


//-------------------------------------------------------------------------------
// Удалить себя из списка 
// ---
void ABaseEvent::RemoveThis() {
	// Удалим себя из списка обработчиков событий
	POSITION pos = m_EventList.Find(this);
  if ( pos ) { 
  	m_EventList.RemoveAt( pos );
    Unadvise();                           // Отпишемся от получения событий
  }
}


//-------------------------------------------------------------------------------
// Удалить список
// ---
void ABaseEvent::DestroyList() {
  if ( &m_EventList ) {
    delete &m_EventList;
  }
}


//-------------------------------------------------------------------------------
// 
// ---
void ABaseEvent::Clear() 
{
  if ( m_pContainer ) 
  {
    m_pContainer->Release();
	  m_pContainer = NULL;     
  }

  if ( m_doc ) 
  {
		m_doc->Release();
		m_doc = NULL;
	}
  
  if ( m_obj3D ) 
  {
		m_obj3D->Release();
		m_obj3D = NULL;
	}

  m_iidEvents = GUID_NULL;
}


//-------------------------------------------------------------------------------
// Рассоединиться
// ---
void ABaseEvent::Disconnect()      
{
  Unadvise();
  Clear();
  ExternalRelease();
}


//-------------------------------------------------------------------------------
// Подписаться на получение событий
// ---
int ABaseEvent::Advise() 
{
  ASSERT( m_dwCookie == 0 ); // Повторно подписываться нельзя

  // Подписаться на получение событий
	if ( m_pContainer ) 
  {
    LPCONNECTIONPOINTCONTAINER lpContainer = NULL;
	  if ( SUCCEEDED(m_pContainer->QueryInterface(IID_IConnectionPointContainer, (LPVOID*)&lpContainer)) ) 
    {
	    if ( lpContainer && SUCCEEDED(lpContainer->FindConnectionPoint(m_iidEvents, &m_pConnPt)) ) 
	    {
		    ASSERT( m_pConnPt != NULL );
		    m_pConnPt->Advise( &m_xEventHandler, &m_dwCookie ); 
	    }
	    lpContainer->Release();
    }
  }

	return m_dwCookie;
}


//-------------------------------------------------------------------------------
// Отписаться от получения событий
// ---
void ABaseEvent::Unadvise()
{
  if ( m_pConnPt != NULL )              // Подписка была
  {
    m_pConnPt->Unadvise( m_dwCookie );  // Отписаться от получения событий
    m_pConnPt->Release();	              // Освободить 
    m_pConnPt  = NULL;
  } 
  m_dwCookie = 0;

}


//-----------------------------------------------------------------------------
// Отписать все события
// ---
void ABaseEvent::TerminateEvents( LPUNKNOWN container )
{
  if ( container ) {
    INT_PTR count = m_EventList.GetCount();
	  for ( INT_PTR i = count - 1; i>= 0 ; i-- )
    {
		  CObject* obj = m_EventList.GetAt( m_EventList.FindIndex(i) );
      ABaseEvent* event = (ABaseEvent*) obj;  
      if ( event && event->m_pContainer == container)
        event->Disconnect();			// в деструкторе будет удален из списка RemoveAt(pos)
    }
  }
}


//-----------------------------------------------------------------------------
// Отписать все события по GUID и документу
// ---
void ABaseEvent::TerminateEvents( IID iid, LPDISPATCH doc/*NULL*/,
                                           long objType/*-1*/,
                                           LPDISPATCH obj3D /*NULL*/)
{
  INT_PTR count = m_EventList.GetCount();
	for ( INT_PTR i = count - 1; i >= 0; i-- )
	{
		CObject* obj = m_EventList.GetAt( m_EventList.FindIndex( i ) );
    ABaseEvent* event = (ABaseEvent*) obj;  
    if ( event && 
         ( IsEqualIID( iid, GUID_NULL) ||
           IsEqualIID( event->m_iidEvents, iid ) ) &&
         ( !doc          || event->m_doc == doc ) &&
         ( objType == -1 || event->m_objType == objType ) &&
         ( !obj3D        || obj3D      == event->m_obj3D) ) 
    {         
			event->Disconnect();	// В деструкторе будет удален из списка RemoveAt(pos)
    }
	}
}



//-----------------------------------------------------------------------------
// отписать все события
// ---
void ABaseEvent::TerminateEvents( void )
{
  while ( !m_EventList.IsEmpty() ) {
	  ABaseEvent* headEvent = (ABaseEvent*)m_EventList.RemoveHead();
		headEvent->Disconnect();		
  }
}


//-----------------------------------------------------------------------------
//
// ---
ABaseEvent * ABaseEvent::FindEvent( IID iid, LPDISPATCH doc/*NULL*/, 
                                     long objType/*-1*/, LPDISPATCH obj3D ) 
{
  INT_PTR count = m_EventList.GetCount();
	for ( INT_PTR i = count - 1; i >= 0; i-- )
	{
		CObject* obj = m_EventList.GetAt(  m_EventList.FindIndex( i ) );
    ABaseEvent* event = (ABaseEvent*) obj;  
	  if ( event && 
         ( IsEqualIID( iid, GUID_NULL) || 
           IsEqualIID( event->m_iidEvents, iid ) ) &&
         ( !doc          || event->m_doc == doc ) &&
         ( ( objType == -1 && !event->m_objType ) || (event->m_objType == objType) ) && 
         ( ( !obj3D && !event->m_obj3D) || ( obj3D == event->m_obj3D ) ) )         
      return event;
  }
  return NULL;
}


//-----------------------------------------------------------------------------
//
// ---
ABaseEvent * ABaseEvent::FindEventByContainer( IID iid, LPUNKNOWN pObject ) 
{
  INT_PTR count = m_EventList.GetCount();
	for ( INT_PTR i = count - 1; i >= 0; i-- )
	{
		CObject* obj = m_EventList.GetAt(  m_EventList.FindIndex( i ) );
    ABaseEvent* event = (ABaseEvent*) obj;  
	  if ( event && 
         ( IsEqualIID( iid, GUID_NULL) || 
           IsEqualIID( event->m_iidEvents, iid ) ) &&
         ( ( pObject == event->m_pContainer)  ) )         
      return event;
  }
  return NULL;
}


//-------------------------------------------------------------------------------
// Карта интерфейса
// ---
BEGIN_INTERFACE_MAP(ABaseEvent, CCmdTarget)
END_INTERFACE_MAP()


//-------------------------------------------------------------------------------
// Карта сообщений интерфейса
// ---
BEGIN_EVENTSINK_MAP(ABaseEvent, CCmdTarget)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// AddRef
// ---
STDMETHODIMP_(ULONG) ABaseEvent::XEventHandler::AddRef()
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	return (ULONG)pThis->ExternalAddRef();
}


//-------------------------------------------------------------------------------
// GetIDsOfNames
// ---
STDMETHODIMP ABaseEvent::XEventHandler::GetIDsOfNames( REFIID riid, LPOLESTR* rgszNames, 
                                                      unsigned int cNames, LCID lcid, 
                                                      DISPID* rgdispid )
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	ASSERT_VALID( pThis );

	return ResultFromScode( E_NOTIMPL );
}


//-------------------------------------------------------------------------------
// GetTypeInfo
// ---
STDMETHODIMP ABaseEvent::XEventHandler::GetTypeInfo( unsigned int itinfo, LCID lcid, 
                                                    ITypeInfo** pptinfo )
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	ASSERT_VALID( pThis );

	return ResultFromScode( E_NOTIMPL );
}


//-------------------------------------------------------------------------------
// GetTypeInfoCount
// ---
STDMETHODIMP ABaseEvent::XEventHandler::GetTypeInfoCount( unsigned int* pctinfo )
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	*pctinfo = 0;
	return NOERROR;
}


//-------------------------------------------------------------------------------
// Пересылка событий
// ---
STDMETHODIMP ABaseEvent::XEventHandler::Invoke( DISPID           dispidMember, 
                                               REFIID           riid, 
                                               LCID             lcid, 
                                               unsigned short   wFlags, 
                                               DISPPARAMS     * lpDispparams, 
                                               VARIANT        * pvarResult, 
                                               EXCEPINFO      * pexcepinfo, 
                                               unsigned int   * puArgErr )
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	ASSERT_VALID( pThis );

  // Класс параметров сообщения 
	AFX_EVENT event( AFX_EVENT::event, dispidMember, lpDispparams, pexcepinfo, puArgErr );

  
  // Примечание: OnEvent в отсутствии обработчика возвращает FALSE, для правильной работы,
  //             необходимо возвращать TRUE, чтобы не блокировать действия Компас, поэтому 
  //             перед OnEvent включена проверка GetEventSinkEntry           
            
  BOOL eventHandled = TRUE; // Событие не обрабатывается, необходимо вернуть TRUE
  if (pThis->GetEventSinkEntry( 1, &event ) != NULL )      
    eventHandled = pThis->OnEvent( 1, &event, NULL ); // Передача сообщения дальше

  if ( pvarResult != NULL ) {
		VariantClear( pvarResult );                       // Результат 
	                                  
	  V_VT  (pvarResult) = VT_BOOL;
	  V_BOOL(pvarResult) = eventHandled;
  
  }
  return event.m_hResult;
}


//-------------------------------------------------------------------------------
// QueryInterface
// ---
STDMETHODIMP ABaseEvent::XEventHandler::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )

	*ppvObj = NULL;
	if ( IID_IUnknown == iid || IID_IDispatch == iid || iid == pThis->m_iidEvents )
		*ppvObj = this;

	if ( NULL != *ppvObj )
	{
		((LPUNKNOWN)*ppvObj)->AddRef();
		return NOERROR;
	}

  return (HRESULT)pThis->ExternalQueryInterface( &iid, ppvObj );
}


//-------------------------------------------------------------------------------
// Release
// ---
STDMETHODIMP_(ULONG) ABaseEvent::XEventHandler::Release()
{
	METHOD_PROLOGUE( ABaseEvent, EventHandler )
	return (ULONG)pThis->ExternalRelease();
}

