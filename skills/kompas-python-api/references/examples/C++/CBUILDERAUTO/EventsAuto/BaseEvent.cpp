////////////////////////////////////////////////////////////////////////////////
//
// BaseEvent.cpp
// Базовый класс для обработчиков событий (Auto)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif


//---------------------------------------------------------------------------
// Список обработчиков событий
// ---
TList * EventListObject::m_pEventList = NULL;


//---------------------------------------------------------------------------
// Отписать все события
// Вызывается по выходу из библиотеки
// ---
void EventListObject::TerminateEvents()
{
  while( m_pEventList )
  {
    EventListObject * pEventListing = (EventListObject*)m_pEventList->First();
    delete pEventListing; // В деструкторе будет удален из списка и будет удален сам список
 	}
}


//-------------------------------------------------------------------------------
// Класс счетчик - добавить себя в список, если списка не было,
// то нада его создать
// ---
EventListObject::EventListObject()
{
  if( !m_pEventList )
    m_pEventList = new TList();
  if( m_pEventList )
    m_pEventList->Add( this );
}


//-------------------------------------------------------------------------------
// Класс счетчик - удалить себя из списока, если элемент последний,
// то удалить сам список
// ---
EventListObject::~EventListObject()
{
  if( m_pEventList )
  {
    m_pEventList->Remove( this );
    if( !m_pEventList->Count )
    {
      delete m_pEventList;
      m_pEventList = NULL;
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктор с подключением к серверу сообщений
// ---
BaseEvent::BaseEvent( LPUNKNOWN  pContainer,
                      REFIID     refIID,
                      LPDISPATCH doc,
                      long       objType,
                      LPDISPATCH obj3D ) :
  m_Ref(1),
  m_EventCookie(0),
  m_pContainer(pContainer),
  m_pDoc( doc),
  m_refIID(refIID),
  m_objType(objType)
{
  if ( m_pContainer )
    m_pContainer->AddRef();

}


//-------------------------------------------------------------------------------
// Деструктор с отключением от сервера сообщений
// ---
BaseEvent::~BaseEvent()
{
  Unadvise();
  if ( m_pContainer )
    m_pContainer->Release();
}


//-------------------------------------------------------------------------------
// Подключение к серверу сообщений
// ---
bool BaseEvent::Advise()
{
  if ( m_pContainer )
  {
    COMHlpr_ConnectEvents(m_refIID, m_pContainer, static_cast<IUnknown*>(this), m_EventCookie);
  }
  return m_EventCookie;
}


//-------------------------------------------------------------------------------
// Отключение от сервера сообщений
// ---
void BaseEvent::Unadvise()
{
  if ( m_pContainer && m_EventCookie )
  {
    COMHlpr_DisconnectEvents(m_refIID, m_pContainer, m_EventCookie);
    m_EventCookie = 0;
  }
}

//-----------------------------------------------------------------------------
// Отписаться
// ---
void BaseEvent::Disconnect()
{
  Unadvise();
  Clear();
}

void BaseEvent::Clear()
{
  if ( m_pContainer )
  {
    m_pContainer->Release();
    m_pContainer = NULL;
  }
}

//-----------------------------------------------------------------------------
// Отписать все события по GUID и документу
// ---
void BaseEvent::TerminateEvents( IID iid, LPDISPATCH doc/*NULL*/,
                                          long objType/*-1*/,
                                          LPDISPATCH obj3D/*NULL*/ )
{
	for ( int i = m_pEventList->Count - 1; i >= 0; i-- )
	{

		BaseEvent* event = (BaseEvent*) m_pEventList->Items[i];
    if ( event &&
         ( IsEqualIID( iid, GUID_NULL) || IsEqualIID( event->m_refIID, iid ) ) &&
         ( !doc          || event->m_pDoc == doc ) &&
         ( objType == -1 || event->m_objType == objType ) &&
         ( !obj3D        || event->m_obj3D == obj3D ) )
    {
			event->Disconnect();	// В деструкторе будет удален из списка RemoveAt(pos)
    }
	}
}


//-----------------------------------------------------------------------------
//
// ---
BaseEvent* BaseEvent::FindEvent( IID iid, LPDISPATCH doc/*NULL*/,
                                    long objType/*-1*/,
                                    LPDISPATCH obj3D/*NULL*/ )
{
	for ( int i = m_pEventList->Count - 1; i >= 0; i-- )
	{
		BaseEvent* event = (BaseEvent*) m_pEventList->Items[i];
	  if ( event &&
         ( IsEqualIID( iid, GUID_NULL)            || IsEqualIID( event->m_refIID, iid ) ) &&
         ( !doc                                   ||   event->m_pDoc == doc             ) &&
         ( ( objType == -1 && !event->m_objType ) || ( event->m_objType == objType    ) ) &&
         ( ( !obj3D        && !event->m_obj3D   ) || ( event->m_obj3D   == obj3D      ) ) )
      event->Disconnect();
  }
  return NULL;
}


//---------------------------------------------------------------------------
// Преобразование
// ---
HRESULT STDMETHODCALLTYPE BaseEvent::QueryInterface(REFIID iid, void **ppvObject)
{
  *ppvObject = 0;
  if ((iid == IID_IDispatch) || (iid == m_refIID))
  {
    (this)->AddRef();
    *ppvObject = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IUnknown)
  {
    (this)->AddRef();
    *ppvObject = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;
  return S_OK;
}


//---------------------------------------------------------------------------
// Формируем параметры и возвращаемый результат
// ---
HRESULT STDMETHODCALLTYPE BaseEvent::Invoke( DISPID dispid, REFIID iid, LCID lcid,
                                             WORD wFlags, DISPPARAMS* pDispParams,
                                             VARIANT* pVarResult, EXCEPINFO* pExcepInfo,
                                             UINT* puArgError )
{
  TAPtr<TVariant> pParamArray;
  TVariant *pArrayPtr = 0;

  if ( pDispParams->cArgs )
  {
    int count = pDispParams->cArgs;
    pParamArray = new TVariant[count];
    for ( UINT i=0; i<pDispParams->cArgs; i++ )
      pParamArray[count-(i+1)] = pDispParams->rgvarg[i];
    pArrayPtr = pParamArray;
  }

  BOOL resEvent = true;

  HRESULT hr = InvokeEvent( dispid, resEvent, pArrayPtr );

  if ( hr != S_OK)                         // если метод не найден то возвращаем true - действие разрешено
    resEvent = true;

	if ( pVarResult != NULL ) {
		VariantClear( pVarResult );
  	V_VT  (pVarResult) = VT_BOOL;
	  V_BOOL(pVarResult) = resEvent;
  }

	return hr;
}


//-------------------------------------------------------------------------------
//
// ---
HRESULT STDMETHODCALLTYPE BaseEvent::GetTypeInfoCount(UINT* pctInfo)
{
  *pctInfo = 0;
  return S_OK;
}


//-------------------------------------------------------------------------------
//
// ---
HRESULT STDMETHODCALLTYPE BaseEvent::GetTypeInfo(UINT, LCID, ITypeInfo** ppTypeInfo)
{
  *ppTypeInfo = 0;
  return E_NOTIMPL;
}


//-------------------------------------------------------------------------------
//
// ---
HRESULT STDMETHODCALLTYPE BaseEvent::GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*)
{
  return E_NOTIMPL;
}

