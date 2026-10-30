// SelectMngEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _SELECTMNGEVENT_H
#include "SelectMngEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );
//-------------------------------------------------------------------------------
// Новое событие селектирования
// ---
BaseEvent* NewSelectMngEvent( reference doc ) {
	SelectMngEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntSelectionMngNotify, doc ) ) {
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			res = new SelectMngEvent( doc );
			if ( !res->Advise() ) { 
				delete res;
				res = NULL;
			}
		}
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обработчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
SelectMngEvent::SelectMngEvent( reference doc )
: BaseEvent( ntSelectionMngNotify, doc, 0, doc )
{
	docType = ksGetDocumentType( doc );
}


//-------------------------------------------------------------------------------
//
// ---
SelectMngEvent::~SelectMngEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN SelectMngEvent::GetUnknown(){
  m_xSelectionMngNotify.AddRef();
  return &m_xSelectionMngNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SelectMngEvent::XSelectionMngNotify::Release()
{
	METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SelectMngEvent::XSelectionMngNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify )
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP SelectMngEvent::XSelectionMngNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_ISelectionMngNotify) )
	{
		*ppvObj = this;
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) SelectMngEvent::XSelectionMngNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify)
	return  notifyType >= ksmSelect && notifyType <= ksmUnselectAll;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void SelectMngEvent::ShowEventName( LPCTSTR eventName, VARIANT & obj ) {
	if ( theApp.m_mes_SELECT ) {
		::_ShowEventName(eventName);
	  if ( obj.vt != VT_EMPTY ) {
		  switch( obj.vt ) {
			  case VT_NULL:
			    break;
			  case VT_I4: {
				  if ( docType > 0 && docType <= lt_DocFragment )
					  if ( ExistObj( obj.intVal ) )
				      ShowObjParam( obj.intVal );
			    break;
				}
        case VT_UNKNOWN: {
				  if ( docType == lt_DocPart3D || docType == lt_DocAssemble3D ) {
            ShowObjParam( obj.punkVal );
					}
				  break;
				}

			  default: {}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString SelectMngEvent::EventCaption() {
	CString res = _T("SelectMngEvent");
	res += GetDocumentParam( refDoc );
	return res;
}


/////////////////////////////////////////////////////////////////////////////
// SelectMngEvent message handlers
//-------------------------------------------------------------------------------
// ksmSelect      - Объект селектирован
// ---
VARIANT_BOOL SelectMngEvent::XSelectionMngNotify::Select( VARIANT obj ) {
  METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify )
  pThis->ShowEventName(_T("SelectMngEvent::Select"), obj );
  return true;
}


//-------------------------------------------------------------------------------
// ksmUnselect    - Объект расселектирован
// ---
VARIANT_BOOL SelectMngEvent::XSelectionMngNotify::Unselect( VARIANT obj ) {
  METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify )
  pThis->ShowEventName( _T("SelectMngEvent::UnSelect"), obj );
  return true;
}


//-------------------------------------------------------------------------------
// ksmUnselectAll - Все объекты расселектированы
// ---
VARIANT_BOOL SelectMngEvent::XSelectionMngNotify::UnselectAll() {
  METHOD_PROLOGUE_EX_(SelectMngEvent, SelectionMngNotify )
	VARIANT obj;
	obj.vt = VT_EMPTY; 
  pThis->ShowEventName( _T("SelectMngEvent::UnselectAll"), obj );
  return true;
}

