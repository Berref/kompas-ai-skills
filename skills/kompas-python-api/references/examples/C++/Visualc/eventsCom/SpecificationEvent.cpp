// SelectMngEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _SPECIFICATIONEVENT_H
#include "SpecificationEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern BaseEvent* NewDocumentEvent( reference doc );

//extern AFX_MODULE_STATE* pModuleState;
//-------------------------------------------------------------------------------
// Создать обработчик события редактирования спецификации
// ---
BaseEvent* NewSpecificationEvent( reference doc ) {
	SpecificationEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntSpecificationNotify, doc ) ) {
  		NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
		  res = new SpecificationEvent( doc );
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
SpecificationEvent::SpecificationEvent( reference doc )
: BaseEvent( ntSpecificationNotify, doc, 0, doc )
{
}


//-------------------------------------------------------------------------------
//
// ---
SpecificationEvent::~SpecificationEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN SpecificationEvent::GetUnknown(){
  m_xSpecificationNotify.AddRef();
  return &m_xSpecificationNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpecificationEvent::XSpecificationNotify::Release()
{
	METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) SpecificationEvent::XSpecificationNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify )
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP SpecificationEvent::XSpecificationNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_ISpecificationNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) SpecificationEvent::XSpecificationNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
	return  notifyType >= ssTuningSpcStyleBeginChange && notifyType <= ssBeginCreateObject;
}


//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void SpecificationEvent::ShowEventName( LPCTSTR eventName ) {
	if ( theApp.m_mes_SPC )
		::_ShowEventName(eventName);
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString SpecificationEvent::EventCaption() {
	CString res = _T("SpecificationEvent");
	res += GetDocumentParam( refDoc );
	return res;
}

/////////////////////////////////////////////////////////////////////////////
// SpecificationEvent message handlers
//-------------------------------------------------------------------------------
// ssTuningSpcStyleBeginChange  - Начало изменения настроек спецификации.
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::TuningSpcStyleBeginChange( LPSTR libName, long numb ) {
	METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::TuningSpcStyleBeginChange") );
  return !theApp.m_mes_SPC || ::YesNoT(_T("Изменить стиль?")) == 1;
}


//-------------------------------------------------------------------------------
// ssTuningSpcStyleChange  - Изменения настроек спецификации.
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::TuningSpcStyleChange( LPSTR libName, long numb, VARIANT_BOOL isOk ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::TuningSpcStyleChange") );
  return true;
}


//-------------------------------------------------------------------------------
// ssChangeCurrentSpcDescription - Изменение текущего описания спецификации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::ChangeCurrentSpcDescription( LPSTR libName, long numb ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::ChangeCurrentSpcDescription") );
  return true;
}

//-------------------------------------------------------------------------------
// ssSpcDescriptionAdd - Добавление описания спецификации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::SpcDescriptionAdd( LPSTR libName, long numb ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::SpcDescriptionAdd") );
  return true;
}
//-------------------------------------------------------------------------------
// ssSpcDescriptionRemove - Удаление описания спецификации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::SpcDescriptionRemove( LPSTR libName, long numb ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::SpcDescriptionRemove") );
  return true;
}

//-------------------------------------------------------------------------------
// ssSpcDescriptionRemove - Редактирование описания спецификации
// ---
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::SpcDescriptionBeginEdit( LPSTR libName, long numb ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::SpcDescriptionBeginEdit") );
  return !theApp.m_mes_SPC || ::YesNoT( _T("Редактировать описание") ) == 1;
}

//-------------------------------------------------------------------------------
// ssSpcDescriptionEdit - Редактирование описания спецификации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::SpcDescriptionEdit( LPSTR libName, long numb, VARIANT_BOOL isOk ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::SpcDescriptionEdit") );
  return true;
}

//-------------------------------------------------------------------------------
// ssSynchronizationBegin - Запуск синхронизации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::SynchronizationBegin() {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::SynchronizationBegin") );
  return !theApp.m_mes_SPC || ::YesNoT( _T("Синхронизировать?") ) == 1;
}

//-------------------------------------------------------------------------------
// ssSynchronization - Завершение синхронизации
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::Synchronization() {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::Synchronization") );
  return true;
}

//-------------------------------------------------------------------------------
// ssBeginCalcPositions - Расчет позиций
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::BeginCalcPositions() {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::BeginCalcPositions") );
  return !theApp.m_mes_SPC || ::YesNoT( _T("Пересчитать позиции?") ) == 1;
}


//-------------------------------------------------------------------------------
// ssCalcPositions - Расчет позиций
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::CalcPositions() {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::CalcPositions") );
  return true;
}

//-------------------------------------------------------------------------------
// ssBeginCreateObject - Создание объекта
// ---
VARIANT_BOOL SpecificationEvent::XSpecificationNotify::BeginCreateObject( long typeObj ) {
  METHOD_PROLOGUE_EX_(SpecificationEvent, SpecificationNotify)
  pThis->ShowEventName( _T("SpecificationEvent::BeginCreateObject") );
  return !theApp.m_mes_SPC || ::YesNoT( _T("Создать объект?") ) == 1;
}


