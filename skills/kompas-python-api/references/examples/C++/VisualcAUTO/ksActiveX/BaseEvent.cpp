/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include <afxctl.h>
#include <afxpriv.h>
#include "ldefin2d.h"


#include "baseEvent.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CObList  CBaseEvent::m_EventList;

//-------------------------------------------------------------------------------
//
// ---
CBaseEvent::CBaseEvent( LPUNKNOWN pObject, const IID & iidEvents ) :
  CCmdTarget(), m_dwCookie(0), m_pContainer(pObject), m_iidEvents(iidEvents), m_pConnPt(NULL)
{
  m_EventList.AddTail(this);

  if ( m_pContainer ) 
    m_pContainer->AddRef();

  ASSERT( !IsEqualIID(m_iidEvents, GUID_NULL) ); // Прислали тип событий
}

//-------------------------------------------------------------------------------
//
// ---
CBaseEvent::~CBaseEvent()
{
  // Удалим себя из списка обработчиков событий
  POSITION pos = m_EventList.Find(this);
  if ( pos ) 
  {
    m_EventList.RemoveAt( pos );

    Unadvise(); // Отпишемся от получения событий

    if ( m_pContainer ) 
    {
      m_pContainer->Release();
      m_pContainer = NULL;     
    }
  }
}

//-------------------------------------------------------------------------------
// Подписаться на получение событий
// ---
int CBaseEvent::Advise() 
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

  // Неудачная подписка на события
  if( !m_dwCookie )
  {
    delete this;
    return 0;
  }

  return m_dwCookie;
}


//-------------------------------------------------------------------------------
// Отписаться от получения событий
// ---
void CBaseEvent::Unadvise()
{
  if ( m_pConnPt != NULL )              // Подписка была
  {
    try
    {
      m_pConnPt->Unadvise( m_dwCookie );  // Отписаться от получения событий
      m_pConnPt->Release();              // Освободить
    }
    catch ( _com_error & e )
    {
    }
    catch( CException *e )
    {
    }
    catch (...)
    {
    }
    m_pConnPt  = NULL;
  } 

  m_dwCookie = 0;
}

//-------------------------------------------------------------------------------
// Отписаться от получения событий
// ---
void CBaseEvent::Disconnect()
{
  Unadvise();
  if ( m_pContainer ) 
  {
    m_pContainer->Release();
    m_pContainer = NULL;     
  }
  Clear();
  ExternalRelease();
}

//-----------------------------------------------------------------------------
// Отписать все события
// ---
void CBaseEvent::TerminateEvents( void )
{
  int count = (int)m_EventList.GetCount();
  for ( int i = 0; i < count ; i++ )
  {
    CObject* headEvent = m_EventList.RemoveHead();
    ((CBaseEvent*)headEvent)->Disconnect(); // В деструкторе будет удален из списка RemoveAt(pos)
  }
}

//-----------------------------------------------------------------------------
// Отписать все события по GUID и документу
// ---
void CBaseEvent::TerminateEvents( const IID & iid, LPUNKNOWN pObject )
{
  int count = (int)m_EventList.GetCount();
  for ( int i = count - 1; i >= 0; i-- )
  {
    CObject* obj = m_EventList.GetAt( m_EventList.FindIndex( i ) );
    CBaseEvent* baseEvent = (CBaseEvent*) obj;  
    if ( baseEvent && 
       ( IsEqualIID( iid, GUID_NULL) ||
         IsEqualIID( baseEvent->m_iidEvents, iid ) ) &&
       ( !pObject      || baseEvent->m_pContainer == pObject ) )        
    {         
      baseEvent->Disconnect();  // В деструкторе будет удален из списка RemoveAt(pos)
    }
  }
}


//-----------------------------------------------------------------------------
//
// ---
CBaseEvent * CBaseEvent::FindEvent( const IID & iid, LPUNKNOWN pObject ) 
{
  CBaseEvent * res = NULL;
  int count = (int)m_EventList.GetCount();
  for ( int i = count - 1; i >= 0; i-- )
  {
    CObject* obj = m_EventList.GetAt(  m_EventList.FindIndex( i ) );
    CBaseEvent* baseEvent = (CBaseEvent*) obj;  
    if ( baseEvent && 
         ( IsEqualIID( iid, GUID_NULL) || 
           IsEqualIID( baseEvent->m_iidEvents, iid ) ) &&
         ( !pObject      || baseEvent->m_pContainer == pObject ) )           
    {
      res = baseEvent;
      break;
    }   
  }
  return res;
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_INTERFACE_MAP(CBaseEvent, CCmdTarget)
END_INTERFACE_MAP()


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(CBaseEvent, CCmdTarget)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) CBaseEvent::XEventHandler::AddRef()
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  return (ULONG)pThis->ExternalAddRef();
}


//-------------------------------------------------------------------------------
//
// ---
STDMETHODIMP CBaseEvent::XEventHandler::GetIDsOfNames( REFIID riid, LPOLESTR* rgszNames, 
                                                      unsigned int cNames, LCID lcid, 
                                                      DISPID* rgdispid )
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  ASSERT_VALID( pThis );

  return ResultFromScode( E_NOTIMPL );
}


//-------------------------------------------------------------------------------
//
// ---
STDMETHODIMP CBaseEvent::XEventHandler::GetTypeInfo( unsigned int itinfo, LCID lcid, 
                                                    ITypeInfo** pptinfo )
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  ASSERT_VALID( pThis );

  return ResultFromScode( E_NOTIMPL );
}


//-------------------------------------------------------------------------------
//
// ---
STDMETHODIMP CBaseEvent::XEventHandler::GetTypeInfoCount( unsigned int* pctinfo )
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  *pctinfo = 0;
  return NOERROR;
}


//-------------------------------------------------------------------------------
// Пересылка событий
// ---
STDMETHODIMP CBaseEvent::XEventHandler::Invoke( DISPID           dispidMember, 
                                                REFIID           riid, 
                                                LCID             lcid, 
                                                unsigned short   wFlags, 
                                                DISPPARAMS     * lpDispparams, 
                                                VARIANT        * pvarResult, 
                                                EXCEPINFO      * pexcepinfo, 
                                                unsigned int   * puArgErr )
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  ASSERT_VALID( pThis );

  AFX_EVENT event( AFX_EVENT::event, dispidMember, lpDispparams, pexcepinfo, puArgErr );

  // Событие не обрабатывается, необходимо вернуть TRUE
  BOOL eventHandled = TRUE;
  if (pThis->GetEventSinkEntry(1, &event) != NULL)
    eventHandled = pThis->OnEvent( 1, &event, NULL );

  if ( pvarResult != NULL ) {
    VariantClear( pvarResult );
  
  V_VT  (pvarResult) = VT_BOOL;
  V_BOOL(pvarResult) = eventHandled;
  
  }
  return event.m_hResult;
}


//-------------------------------------------------------------------------------
//
// ---
STDMETHODIMP CBaseEvent::XEventHandler::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )

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
//
// ---
STDMETHODIMP_(ULONG) CBaseEvent::XEventHandler::Release()
{
  METHOD_PROLOGUE( CBaseEvent, EventHandler )
  return (ULONG)pThis->ExternalRelease();
}


/////////////////////////////////////////////////////////////////////////////
//
// Базовый клас для обработчиков событий Компаса
//
/////////////////////////////////////////////////////////////////////////////
KSBaseEvent::KSBaseEvent(LPUNKNOWN pObject, IID iidEvents, LPDISPATCH doc ) :
  CBaseEvent( pObject, iidEvents ),
  m_doc(doc)
{
  if ( m_doc )
    m_doc->AddRef();
}


//-------------------------------------------------------------------------------
//
// ---
KSBaseEvent::~KSBaseEvent()
{
  if ( m_doc ) 
  {
    m_doc->Release();
    m_doc = NULL;
  }
  kompas = NULL;
}


//-------------------------------------------------------------------------------
//
// ---
void KSBaseEvent::Clear()
{
  if ( m_doc ) 
  {
    m_doc->Release();
    m_doc = NULL;
  }
  kompas = NULL;
}


//-----------------------------------------------------------------------------
// Отписать все события по GUID и документу
// ---
void KSBaseEvent::TerminateEvents( IID iid, LPUNKNOWN pObject, LPDISPATCH doc )
{
  if ( !doc )
  {
    CBaseEvent::TerminateEvents( iid, pObject );
  }
  else
  {
    int count = (int)m_EventList.GetCount();
    for ( int i = count - 1; i >= 0; i-- )
    {
      CObject* obj = m_EventList.GetAt( m_EventList.FindIndex( i ) );
      KSBaseEvent* event = ((CBaseEvent*)obj)->EventID() == ksEvent ? (KSBaseEvent*)obj : NULL;  
      if ( event && 
          ( IsEqualIID( iid, GUID_NULL) ||
            IsEqualIID( event->m_iidEvents, iid ) ) &&
          ( !pObject      || event->m_pContainer == pObject ) &&
          ( !doc          || event->m_doc == doc || event->m_pContainer == doc )  )        
      {         
        event->Disconnect();;  // В деструкторе будет удален из списка RemoveAt(pos)
      }
    }
  }
}

//-----------------------------------------------------------------------------
//
// ---
CBaseEvent * KSBaseEvent::FindEvent( IID iid, LPUNKNOWN pObject, LPDISPATCH doc ) 
{
  if ( !doc )
    return CBaseEvent::FindEvent( iid, pObject ); 

  CBaseEvent * res = NULL;
  int count = (int)m_EventList.GetCount();
  for ( int i = count - 1; i >= 0; i-- )
  {
    CObject* obj = m_EventList.GetAt(  m_EventList.FindIndex( i ) );
    KSBaseEvent* event = ((CBaseEvent*)obj)->EventID() == ksEvent ? (KSBaseEvent*)obj : NULL;  
    if ( event && 
       ( IsEqualIID( iid, GUID_NULL) || 
         IsEqualIID( event->m_iidEvents, iid ) ) &&
       ( !pObject      || event->m_pContainer == pObject ) &&          
       ( !doc          || event->m_doc == doc || event->m_pContainer == doc )  )
    {
      res = event;
      break;
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// Отписать все события
// ---
void KSBaseEvent::TerminateAllKompasEvents( void )
{
  int count = (int)m_EventList.GetCount();
  for ( int i = count - 1; i >= 0; i-- )
  {
    POSITION pos = m_EventList.FindIndex(i);
    if ( pos )
    {
      CObject* obj = m_EventList.GetAt( pos );
      KSBaseEvent* event = obj && ((CBaseEvent*)obj)->EventID() == ksEvent ? (KSBaseEvent*)obj : NULL;  
      if ( event )        
      {         
        event->Disconnect();;  // В деструкторе будет удален из списка RemoveAt(pos)
      }
    }
  }
}