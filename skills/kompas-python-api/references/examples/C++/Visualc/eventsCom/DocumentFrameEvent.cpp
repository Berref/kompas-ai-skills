////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventCom.h"

#ifndef _DOCUMENTFRAMEEVENT_H
#include "DocumentFrameEvent.h"
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
BaseEvent* NewDocumentFrameEvent( reference doc, LPUNKNOWN iObj ) {
	DocumentFrameEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntDocumentFrameNotify, doc, -1, iObj ) ) {
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			res = new DocumentFrameEvent( doc, iObj );
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
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::DocumentFrameEvent( reference doc, LPUNKNOWN iObj )
: BaseEvent( ntDocumentFrameNotify, NULL, 0, iObj, doc )
{
}


//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::~DocumentFrameEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN DocumentFrameEvent::GetUnknown(){
  m_xDocumentFrameNotify.AddRef();
  return &m_xDocumentFrameNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentFrameEvent::XDocumentFrameNotify::Release()
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentFrameEvent::XDocumentFrameNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP DocumentFrameEvent::XDocumentFrameNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IDocumentFrameNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) DocumentFrameEvent::XDocumentFrameNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)
	return  notifyType >= frBeginPaint && notifyType <= frCloseFrame;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void DocumentFrameEvent::ShowEventName( LPCTSTR eventName ) {
// 	if ( theApp.m_mes_SELECT ) {
		::_ShowEventName(eventName);
// 	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString DocumentFrameEvent::EventCaption() {
	CString res = _T("DocumentFrameEvent");
	res += GetDocumentParam( refDoc );
	return res;
}


/////////////////////////////////////////////////////////////////////////////
// DocumentFrameEvent message handlers
//-------------------------------------------------------------------------------
// frBeginPaint          - Начало отрисовки документа
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::BeginPaint( IUnknown* paintObj ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName(_T("DocumentFrameEvent::BeginPaint") );
  return true;
}


//-------------------------------------------------------------------------------
// frClosePaint          - Конец отрисовки документа
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::ClosePaint( IUnknown* paintObj ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::ClosePaint") );
  return true;
}


//-------------------------------------------------------------------------------
// frMouseDown           - Нажатие кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::MouseDown( short nButton, short nShiftState, long x, long y ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::MouseDown") );
  return true;
}


//-------------------------------------------------------------------------------
// frMouseUp             - Отпускание кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::MouseUp( short nButton, short nShiftState, long x, long y ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::MouseUp") );
  return true;
}


//-------------------------------------------------------------------------------
// frMouseDblClick       - Двойной клик кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::MouseDblClick( short nButton, short nShiftState, long x, long y ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::MouseDblClick") );
  return true;
}


//-------------------------------------------------------------------------------
// frBeginCreateGLList   - Начало создания листа в контексте OpenGL
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::BeginPaintGL( long drawMode ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::BeginCreateGLList") );
  return true;
}


//-------------------------------------------------------------------------------
// frCloseCreateGLList   - Окончание создания листа в контексте OpenGL
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::ClosePaintGL( long drawMode ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::CloseCreateGLList") );
  return true;
}


//-------------------------------------------------------------------------------
// frAddGabarit          - Определение габаритов документа
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::AddGabarit( IUnknown* paintObj ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::AddGabarit") );
  return true;
}


//-------------------------------------------------------------------------------
// frBeginCurrentProcess - Начало текущего процесса
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::BeginCurrentProcess( long id ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::BeginCurrentProcess") );
  return true;
}


//-------------------------------------------------------------------------------
// frStopCurrentProcess  - Окончание текущего процесса
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::StopCurrentProcess( long id ) {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::StopCurrentProcess") );
  return true;
}


//-------------------------------------------------------------------------------
// frActivate            - Окно активизировалось
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::Activate() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::Activate") );
  return true;
}


//-------------------------------------------------------------------------------
// frDeactivate          - Окно деактивизировалось
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::Deactivate() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::Deactivate") );
  return true;
}


//-------------------------------------------------------------------------------
// frCloseFrame          - Закрытие окна
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::CloseFrame() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::CloseFrame") );
  pThis->Disconnect();
  return true;
}

//-------------------------------------------------------------------------------
// frMouseMove           - Перемещение мыши
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::MouseMove( short nShiftState, long x, long y )
{
  METHOD_PROLOGUE_EX_( DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T( "DocumentFrameEvent::MouseMove" ) );
  return true;
}

// frShowOcxTree         - 
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::ShowOcxTree( IUnknown * tree,  VARIANT_BOOL show )
{
  return true;
}

//-------------------------------------------------------------------------------
// frBeginPaintTmpObjects          - Начало отрисовки временных объектов
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::BeginPaintTmpObjects() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName(_T("DocumentFrameEvent::BeginPaintTmpObjects") );
  return true;
}


//-------------------------------------------------------------------------------
// frClosePaintTmpObjects          - Конец отрисовки временных объектов
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::ClosePaintTmpObjects() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  pThis->ShowEventName( _T("DocumentFrameEvent::ClosePaintTmpObjects") );
  return true;
}
