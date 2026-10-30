// StampEvent.cpp : implementation file
//

#include "stdafx.h"
#include "eventCom.h"

#ifndef _STAMPEVENT_H
#include "StampEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;

extern BaseEvent* NewDocumentEvent( reference doc );
//-------------------------------------------------------------------------------
// Создать обработчик событий для штампа
// ---
BaseEvent* NewStampEvent( reference doc ) {
  StampEvent* res = NULL;
	if ( doc ) {
    int docType = ::ksGetDocumentType( doc ); 
		switch ( docType ) {
		  case lt_DocSheetStandart :
			case lt_DocSheetUser     :
      case lt_DocSpc           :
			case lt_DocSpcUser       :
			case lt_DocTxtStandart   :
			case lt_DocTxtUser       : {
				if ( !BaseEvent::FindEvents( ntStampNotify, doc ) ) {
					NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
					res = new StampEvent( doc );
					if ( !res->Advise() ) {
						delete res;
						res = NULL;
					}
				}
			}
		}
	}
	return res;
}



////////////////////////////////////////////////////////////////////////////////
//
// StampEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
StampEvent::StampEvent( reference doc ):
    BaseEvent(ntStampNotify, doc, 0, doc)
{
}


//-------------------------------------------------------------------------------
//
// ---
StampEvent::~StampEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN StampEvent::GetUnknown(){
  m_xStampNotify.AddRef();
  return &m_xStampNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) StampEvent::XStampNotify::Release()
{
	METHOD_PROLOGUE_EX_(StampEvent, StampNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) StampEvent::XStampNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(StampEvent, StampNotify)
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP StampEvent::XStampNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(StampEvent, StampNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IStampNotify) )
	{
		*ppvObj = this;
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void StampEvent::ShowEventName( LPCTSTR eventName ) {
	if ( theApp.m_mes_STAMP )
		::_ShowEventName(eventName);
}


//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(StampEvent, StampNotify)
	return  notifyType >= kdBeginEditStamp && notifyType <= kdStampBeginClearCells;
}


//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString StampEvent::EventCaption() {
	CString res = _T("StampEvent");
	res += GetDocumentParam( refDoc );
	return res;
}


/////////////////////////////////////////////////////////////////////////////
// StampEvent message handlers
//-----------------------------------------------------------------------------
// kdBeginEditStamp      - Начало работы со штампом.
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::BeginEditStamp(){
  return !theApp.m_mes_STAMP || ::YesNoT( _T("EventCom::StampEvent : Редактировать штамп?") ) == 1;
}


//-----------------------------------------------------------------------------
// kdEndEditStamp         - Завершение работы со штампом.
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::EndEditStamp( VARIANT_BOOL editResult ){
  METHOD_PROLOGUE_EX_(StampEvent, StampNotify)
  pThis->ShowEventName(_T("StampEvent::EndEditStamp"));
  return true;
}


//-------------------------------------------------------------------------------
//
// ---
reference GetText( CString & func ) {
  reference pText = ::CreateArray(TEXT_LINE_ARR,0);     // TEXT_LINE_ARR - массив неопределенной длины строк текста

  TextLineParam tLinePar;
  ::memset( &tLinePar, 0, sizeof(tLinePar) );
  tLinePar.pTextItem = ::CreateArray(TEXT_ITEM_ARR,0);   //указатель на массив неопределенной длины компонент строки текста

  TextItemParamT  itemPar;    // параметры компоненты строки текста
  ::memset( &itemPar, 0, sizeof(itemPar) );
  itemPar.font.bitVector = NEW_LINE;

  ::_tcscpy_s( itemPar.s, _T("EventCom::StampEvent") );   // массив символов  для компоненты текста
  ::AddArrayItem( tLinePar.pTextItem, -1, &itemPar,  sizeof(itemPar)  );
  ::AddArrayItem( pText,              -1, &tLinePar, sizeof(tLinePar) );
  ::ClearArray( tLinePar.pTextItem );
  ::_tcscpy_s( itemPar.s, func );   // массив символов  для компоненты текста
  ::AddArrayItem( tLinePar.pTextItem, -1, &itemPar,  sizeof(itemPar)  );
  ::AddArrayItem( pText,              -1, &tLinePar, sizeof(tLinePar) );
  ::ClearArray( tLinePar.pTextItem );

  return pText;
}


//-----------------------------------------------------------------------------
//kdStampCellDblClick    - Двойной клик в ячейке штампа.
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::StampCellDblClick( long number ){
  CString mess;
  mess.Format( _T("EventCom::StampEvent : Редактировать по DblClick'у ячейку %i?"), number );
  BOOL res = !!::YesNoT( mess.GetBuffer(0) );

  if ( ::OpenStamp() ) {
    CString func( _T("Редактирование из StampCellDblClick.") );
//    ::SetStampColumnText( number, ::GetText(func) );
    ::ColumnNumber( number );
    ::TextLineT( NEW_LINE, 0, 0, _T("EventCom::StampEvent") );
    ::TextLineT( NEW_LINE, 0, 0, (LPTSTR)(LPCTSTR)func );
    ::CloseStamp();
  }
  return res;
}


//-----------------------------------------------------------------------------
//kdStampCellBeginEdit   - Начало редактирования в ячейке штампа.
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::StampCellBeginEdit( long number ){
  CString mess;
  mess.Format( _T("EventCom::StampEvent : Редактировать ячейку %i?"), number );
  BOOL res = !!::YesNoT( (LPTSTR)(LPCTSTR)mess );

  if ( ::OpenStamp() ) {
    CString func( _T("Редактирование из StampCellBeginEdit.") );
//    ::SetStampColumnText( number, ::GetText(func) );
    ::ColumnNumber( number );
    ::TextLineT( NEW_LINE, 0, 0, _T("EventCom::StampEvent") );
    ::TextLineT( NEW_LINE, 0, 0, (LPTSTR)(LPCTSTR)func );
    ::CloseStamp();
  }
  return res;
}


//-----------------------------------------------------------------------------
//kdStampBeginClearCells - Начало очистки ячеек штампа.
// ---
STDMETHODIMP_(VARIANT_BOOL) StampEvent::XStampNotify::StampBeginClearCells( VARIANT numbers )
{
  METHOD_PROLOGUE_EX_( StampEvent, StampNotify )
  pThis->ShowEventName( _T( "StampEvent::StampBeginClearCells" ) );
  return true;
}
