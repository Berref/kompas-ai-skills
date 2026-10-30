// SelectMngEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _SPCDOCEVENT_H
#include "SpcDocEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );

//-------------------------------------------------------------------------------
// Создать обработчик событий документа cпецификации
// ---
BaseEvent* NewSpcDocEvent( reference doc ) {
	SpcDocEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntSpcDocumentNotify, doc ) ) {
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			res = new SpcDocEvent( doc );
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
// SpcDocEvent  - обработчик событий от документа спецификации
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
SpcDocEvent::SpcDocEvent( reference doc )
: BaseEvent( ntSpcDocumentNotify, doc, 0, doc )
{
}


//-------------------------------------------------------------------------------
//
// ---
SpcDocEvent::~SpcDocEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN SpcDocEvent::GetUnknown(){
  m_xSpcDocumentNotify.AddRef();
  return &m_xSpcDocumentNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpcDocEvent::XSpcDocumentNotify::Release()
{
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpcDocEvent::XSpcDocumentNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify )
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP SpcDocEvent::XSpcDocumentNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_ISpcDocumentNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) SpcDocEvent::XSpcDocumentNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
	return  notifyType >= sdDocumentBeginAdd && notifyType <= sdSpcStyleChange;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void SpcDocEvent::ShowEventName( LPCTSTR eventName, LPCTSTR docName, long numb ) {
	if ( theApp.m_mes_SPCDOC ) {
		CString str = eventName;
		if ( refDoc ) {
      str += GetDocumentParam( refDoc );
      str += _T("\n");
  		str += docName;
			if ( numb ) {
    		TCHAR buf[20];
				_stprintf_s( buf, _T("\nnumb= %i"), numb );
        str += buf; 
			}
		}	
		::_ShowEventName( (LPTSTR)(LPCTSTR) str );
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString SpcDocEvent::EventCaption() {
	CString res = _T("SpcDocEvent");
	res += GetDocumentParam( refDoc );
	return res;
}


/////////////////////////////////////////////////////////////////////////////
// SpcDocEvent message handlers
//-------------------------------------------------------------------------------
// sdDocumentBeginAdd      - Добавление документа
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::DocumentBeginAdd( THIS_ ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::DocumentBeginAdd"), _T(""), 0 );
  return !theApp.m_mes_SPCDOC || ::YesNoT( _T("Добавить документ в список?") ) == 1;
}


//-------------------------------------------------------------------------------
// sdDocumentAdd    - Добавление документа
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::DocumentAdd( LPSTR docName ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::DocumentAdd"), _bstr_t(docName), 0 );
  return true;
}


//-------------------------------------------------------------------------------
// sdDocumentBeginRemove - Удаление документа
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::DocumentBeginRemove( LPSTR docName ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::DocumentBeginRemove"), _bstr_t(docName), 0 );
  return !theApp.m_mes_SPCDOC || ::YesNoT( _T("Удалить документ из списка?") );
}

//-------------------------------------------------------------------------------
// sdDocumentBeginRemove - Удаление документа
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::DocumentRemove( LPSTR docName ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::DocumentRemove"), _bstr_t(docName), 0 );
  return true;
}
//-------------------------------------------------------------------------------
// sdSpcStyleBeginChange - Изменение стиля
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::SpcStyleBeginChange( LPSTR libName, long numb ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::SpcStyleBeginChange"), _bstr_t(libName), numb );
  return !theApp.m_mes_SPCDOC || ::YesNoT( _T("Изменить стиль?") );
}

//-------------------------------------------------------------------------------
// sdSpcStyleChange - Изменение стиля
// ---
VARIANT_BOOL SpcDocEvent::XSpcDocumentNotify::SpcStyleChange( LPSTR libName, long numb ) {
	METHOD_PROLOGUE_EX_(SpcDocEvent, SpcDocumentNotify)
  pThis->ShowEventName( _T("SpcDocEvent::SpcStyleChange"), _bstr_t(libName), numb );
  return true;
}
