// SelectMngEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _SPCOBJECTEVENT_H
#include "SpcObjEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );
//-------------------------------------------------------------------------------
// Создать обработчик событий для объекта спецификации
// ---
BaseEvent* NewSpcObjectEvent( reference doc, int objType ) {
	SpcObjectEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntSpcObjectNotify, doc, objType ) ) {
  		NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
		  res = new SpcObjectEvent( doc, objType );
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
SpcObjectEvent::SpcObjectEvent( reference doc, reference obj)
: BaseEvent( ntSpcObjectNotify, doc, obj, doc )
{
}


//-------------------------------------------------------------------------------
//
// ---
SpcObjectEvent::~SpcObjectEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN SpcObjectEvent::GetUnknown(){
  m_xSpcObjectNotify.AddRef();
  return &m_xSpcObjectNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpcObjectEvent::XSpcObjectNotify::Release()
{
	METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpcObjectEvent::XSpcObjectNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify )
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP SpcObjectEvent::XSpcObjectNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_ISpcObjectNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) SpcObjectEvent::XSpcObjectNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	return  notifyType >= soBeginDelete && notifyType <= soUpdateObject;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void SpcObjectEvent::ShowEventName( LPCTSTR eventName, long obj, long number, int type, LPCTSTR docName ) {
	if ( theApp.m_mes_OBJ_SPC ) {
		CString str = eventName;
    TCHAR buf[255];
	  if ( obj ) {
  		_stprintf_s( buf, _T("\nobj %i"), obj );
      str += buf; 
		}
		if ( number ) {
  		_stprintf_s( buf, _T("\nnumber %i"), number );
      str += buf; 
		}
		if ( type ) {
  		_stprintf_s( buf, _T("\ntype %i"), type );
      str += buf; 
		}
    if ( docName && docName[0] ) {
		  str += _T("\n");
      str += docName;
		}
		::_ShowEventName( str );
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString SpcObjectEvent::EventCaption() {
	CString res = _T("SpcObjectEvent");
	res += GetDocumentParam( refDoc );
	return res;
}

/////////////////////////////////////////////////////////////////////////////
// SpcObjectEvent message handlers
//-------------------------------------------------------------------------------
// soBeginDelete - Удаление объкта
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::BeginDelete( long obj ) {
	METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::BeginDelete"), obj, 0, 0, 0 );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Удалить объект?") ) == 1;
}


//-------------------------------------------------------------------------------
// soDelete    - Объект удален
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::Delete( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::Delete"), obj, 0, 0, 0 );
  return true;
}


//-------------------------------------------------------------------------------
// soCellDblClick - двойной клик по ячейке
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::CellDblClick( long obj, long number ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::CellDblClick"), obj, number, 0, 0 );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Редактировать ячейку?") ) == 1;
}

//-------------------------------------------------------------------------------
// soCellBeginEdit - редактирование ячейки
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::CellBeginEdit( long obj, long number ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::CellBeginEdit"), obj, number, 0, 0 );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Редактировать объект?") ) == 1;
}
//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::ChangeCurrent( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::ChangeCurrent"), obj, 0, 0, 0  );
  return true;
}

//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::DocumentBeginAdd( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::DocumentBeginAdd"), obj, 0, 0, 0  );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Добавить документ?") ) == 1;
}

//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::DocumentAdd( long obj, LPSTR docName ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::DocumentAdd"), obj, 0, 0, _bstr_t(docName)  );
  return true;
}

//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::DocumentRemove( long obj, LPSTR docName ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::DocumentRemove"), obj, 0, 0, _bstr_t(docName) );
  return true;
}

//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::BeginGeomChange( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::BeginGeomChange"), obj, 0, 0, 0 );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Изменить геометрию?") );
}

//-------------------------------------------------------------------------------
// 
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::GeomChange( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::GeomChange"), obj, 0, 0, 0 );
  return true;
}


//-------------------------------------------------------------------------------
// ksmUnselectAll - Запуск процесса
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::BeginProcess( long pType, long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::BeginProcess"), obj, 0, pType, 0 );
  return !theApp.m_mes_OBJ_SPC || ::YesNoT( _T("Запустить процесс?") ) == 1;
}

//-------------------------------------------------------------------------------
// ksmEndProcess - завершение процесса
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::EndProcess( long pType ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::EndProcess") , 0, 0, pType, 0 );
  return true;
}

//-------------------------------------------------------------------------------
// ksmCreateObject - Создание объекта
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::CreateObject( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::CreateObject"), obj, 0, 0, 0 );
  return true;
}

//-------------------------------------------------------------------------------
// ksmUpdateObject - Обновление параметров объекта
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::UpdateObject( long obj ) {
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::UpdateObject"), obj, 0, 0, 0 );
  return true;
}


//-----------------------------------------------------------------------------
//
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::BeginCopy( long objRef )
{
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::BeginCopy"), objRef, 0, 0, 0 );
  return true;	
}
     
//-----------------------------------------------------------------------------
//
// ---
VARIANT_BOOL SpcObjectEvent::XSpcObjectNotify::Copy( long objRef )
{
  METHOD_PROLOGUE_EX_(SpcObjectEvent, SpcObjectNotify)
	pThis->ShowEventName( _T("SpcObjectEvent::Copy"), objRef, 0, 0, 0 );
  return true;	
}
