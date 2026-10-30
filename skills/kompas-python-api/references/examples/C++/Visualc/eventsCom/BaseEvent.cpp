////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxctl.h>
#include <afxpriv.h>

#include "eventCom.h"

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CObList & BaseEvent::m_EventList = *new CObList();
/////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обработчиков событий
//
/////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
BaseEvent::BaseEvent( int ifType, reference p, long objType, reference doc ) :
  m_advise   ( false  ), refDoc( doc )
{
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
  m_params.pContainer = p;
  m_params.ifType     = ifType;
  m_params.objType    = objType;
  m_EventList.AddTail( this );
}

//-------------------------------------------------------------------------------
//
// ---
BaseEvent::BaseEvent( int ifType, LPUNKNOWN iContainer, long objType, LPUNKNOWN iObj, reference doc )
  : m_advise   ( false  ), refDoc( doc )
{
  ::memset( &m_params, 0, sizeof(NotifyConnectionParam) );
  m_params.ifType     = ifType;
  m_params.iContainer = iContainer;
  
  m_params.objType    = objType;
  m_params.iObj       = iObj;
  
  m_params.pContainer = doc;
  
  if ( m_params.iContainer )
    m_params.iContainer->AddRef();

  if ( m_params.iObj )
    m_params.iObj->AddRef(); 

  m_EventList.AddTail( this );
}

//-------------------------------------------------------------------------------
//
// ---
BaseEvent::~BaseEvent()
{
	// удалим себя из списка обработчиков событий
	POSITION pos = m_EventList.Find( this );
  if ( pos ) {
  	m_EventList.RemoveAt( pos );
    Unadvise();              // отпишемся от получения событий
  }
}

//-------------------------------------------------------------------------------
// подписаться на получение событий
// ---
bool BaseEvent::Advise() 
{
  ASSERT(!m_advise);
  if( !m_advise && m_params.ifType ){
		if ( ReturnResult() ) {
			MessageBoxResult();
			ResultNULL();
		}
    LPUNKNOWN obj = GetUnknown();
    m_advise = !!::ksConnectionAdvise ( &m_params, obj );
    obj->Release();
    ASSERT(m_advise);
  }
	return m_advise;
}

//-----------------------------------------------------------------------------
//
// ---
void BaseEvent::Unadvise()
{
  if( m_advise )
  {
    VERIFY( ::ksConnectionUnadvise( &m_params ) ); 
    m_advise = 0; 
  }
}

//-----------------------------------------------------------------------------
// отписать все события
// ---
void BaseEvent::Clear() {

  m_params.objType    = 0;
  m_params.ifType     = 0;
  m_params.pContainer = 0;
  
  if ( m_params.iContainer ) {
    m_params.iContainer->Release(); 
    m_params.iContainer = NULL;
  }

  if ( m_params.iObj ) {
    m_params.iObj->Release();
    m_params.iObj = NULL;  
  }
}

//-----------------------------------------------------------------------------
// Отсоединиться
// ---
void BaseEvent::Disconnect() 
{
  Unadvise();
  Clear();
  ExternalRelease();
}

//-----------------------------------------------------------------------------
// отписать все события
// ---
void BaseEvent::TerminateEvents( void )
{
  while ( !m_EventList.IsEmpty() ) {
	  BaseEvent* headEvent = (BaseEvent*)m_EventList.RemoveHead();
    headEvent->Disconnect();
  }
}

//-----------------------------------------------------------------------------
// отписаться от событий
// ---
void BaseEvent::TerminateEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
  if ( !eventType && !doc )
		TerminateEvents();
	else {
  	for ( INT_PTR i = m_EventList.GetCount() - 1; i >= 0; i-- ) {
	  	BaseEvent* evnt = (BaseEvent*)m_EventList.GetAt( m_EventList.FindIndex(i) );
			if ( evnt && ( !eventType    || eventType == evnt->GetType()        ) 
				        && ( !doc          || doc       == evnt->refDoc           ) 
								&& ( objType == -1 || objType   == evnt->m_params.objType ) 
								&& ( !iObj         || iObj      == evnt->m_params.iObj    ) ) {
        evnt->Disconnect();
      }
		}
	}
}

//-----------------------------------------------------------------------------
// отписаться от событий
// ---
BaseEvent* BaseEvent::FindEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj )
{
  BaseEvent* res = NULL;
  for ( INT_PTR i = m_EventList.GetCount() - 1; i >= 0; i-- ) {
	  BaseEvent* evnt = (BaseEvent*) m_EventList.GetAt( m_EventList.FindIndex(i) );
		if (    (   !eventType                                 ||   eventType == evnt->GetType()        ) 
			   && ( ( !doc          && !evnt->refDoc           ) || ( doc       == evnt->refDoc           ) )
			   && ( ( objType == -1 && !evnt->m_params.objType ) || ( objType   == evnt->m_params.objType ) ) 
			   && ( ( !iObj         && !evnt->m_params.iObj    ) || ( iObj      == evnt->m_params.iObj    ) ) ) {
		  res = evnt;			// в деструкторе будет удален из списка RemoveAt(pos)
      break;
		}
	}
	return res;
}

//-----------------------------------------------------------------------------
// Вывести параметры объектов группы
// ---
void BaseEvent::ShowGroupParam( reference gr ) {
	if ( /*theApp.m_param &&*/ gr ) {
		reference it = CreateIterator( ALL_OBJ, gr );
		if ( it ) {
			reference itObj = MoveIterator( it, _T('F') );
			while ( itObj ){
        ShowObjParam( itObj );
				itObj = MoveIterator( it, _T('N') );
			}
			DeleteIterator( it );
		}
	}
}

//-----------------------------------------------------------------------------
// Вывести параметры объекта
// ---
void BaseEvent::ShowObjParam( reference obj ) {
	if ( /*theApp.m_param &&*/ obj && ExistObj( obj ) ) {
    int type = GetObjParam( obj, 0, 0, ALLPARAM_T );
		switch ( type ) {
  		case 0: break;
//		  case WORK_GROUP_OBJ:
//        ShowGroupParam( obj );
//		  	break;
			default: {
			  TCHAR buf[255];
				::LightObj( obj, 1 );
				_stprintf_s( buf, _T("Объект: %i   Тип: %i"), obj, type );
				MessageT( buf );
				::LightObj( obj, 0 );
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Вывести параметры объекта
// ---
void BaseEvent::ShowObjParam( LPUNKNOWN obj )  {
	if ( obj ) {
		TCHAR buf[255];
		buf[0] = 0;
		IEntityPtr iEntity( obj );
		if ( iEntity ) {
			int type = iEntity->GetType();
			_bstr_t name = iEntity->GetName();
      _stprintf_s( buf, _T("type=%i name=%s"), type, (TCHAR*) name );
			
		}
		else {
  		IPartPtr iPart( obj );
      if ( iPart ) {
				_bstr_t name = iPart->GetName();
				_bstr_t mark = iPart->GetMarking();
        _stprintf_s( buf, _T("name=%s mark=%s"), (TCHAR*)name, (TCHAR*) mark );
			}
			else {
				IFeaturePtr iFeature( obj );
				if ( iFeature ) {
    			int type = iFeature->GetType();
		     	_bstr_t name = iFeature->GetName();
          _stprintf_s( buf, _T("type=%i name=%s"), type, (TCHAR*) name );
				}
			}
		}
		if ( buf[0] )
			MessageT( buf );
	}
}

//-----------------------------------------------------------------------------
// Вывести имя события
// ---
void _ShowEventName( LPCTSTR eventName ) {
  CString mess = _T("EventCom::");
	mess += eventName;
	MessageT( (LPTSTR)(LPCTSTR)mess );
}

//-----------------------------------------------------------------------------
// Вывести имя события
// ---
void BaseEvent::ShowEventName( LPTSTR eventName ) {
	::_ShowEventName( eventName );
}

//-----------------------------------------------------------------------------
//
// ---
void BaseEvent::ListEvents()
{
  CString str( _T("Подписанные события:") );
  INT_PTR count = m_EventList.GetCount();
	for ( INT_PTR i = count - 1; i >= 0; i-- )
	{
		BaseEvent* event = (BaseEvent*) m_EventList.GetAt( m_EventList.FindIndex(i) );
    if ( event && event->m_advise ) {     
      str += _T("\n");
			str += event->EventCaption();
		}
	}
  MessageT( (LPTSTR)(LPCTSTR)str );
}


//-----------------------------------------------------------------------------
//
// ---
CString GetDocumentParam( reference doc ) {
  CString res;
	int type = ksGetDocumentType( doc );
	if ( type ) {
  	switch ( type ) {
		  case lt_DocTxtStandart:
			case lt_DocTxtUser: {
				TextDocumentParamT docParam;
				memset( &docParam, 0, sizeof( docParam) );
				if ( GetObjParam( doc, &docParam, sizeof(docParam), ALLPARAM_T ) ) {
	  			res += docParam.fileName;
					TCHAR buf[255];
					_stprintf_s( buf, _T("\nтип %i"), docParam.type );
					res += buf; 
				}
				break;
			}
			default: {
				DocumentParamT docParam;
				memset( &docParam, 0, sizeof( docParam) );
				if ( GetObjParam( doc, &docParam, sizeof(docParam), ALLPARAM_T ) ) {
					res += _T("\n");
	  			res += docParam.fileName;
					TCHAR buf[255];
					_stprintf_s( buf, _T("\nтип %i"), docParam.type );
					res += buf; 
				}
			}
		}
		if ( ReturnResult() ) {
			MessageBoxResult();
			ResultNULL();
		}
	}
	return res;
}	