// ApplicationEvent.cpp : implementation file
//
#include "stdafx.h"

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif
#include "..\CPropmen.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;


cBaseEvent* NewApplicationEvent() {
  ApplicationEvent* res = NULL;
	if ( !cBaseEvent::FindEvents( ntKompasObjectNotify, 0 ) ) {
		res = new ApplicationEvent();
		if ( !res->Advise() ) { 
			delete res;
			res = NULL;
		}
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
ApplicationEvent::ApplicationEvent():
  cBaseEvent(ntKompasObjectNotify, (reference)0 )
{
}

//-------------------------------------------------------------------------------
//
// ---
ApplicationEvent::~ApplicationEvent()
{
}


//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN ApplicationEvent::GetUnknown(){
  m_xKompasObjectNotify.AddRef();
  return &m_xKompasObjectNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) ApplicationEvent::XKompasObjectNotify::Release()
{
	METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) ApplicationEvent::XKompasObjectNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
	return (ULONG)pThis->InternalAddRef();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP ApplicationEvent::XKompasObjectNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IKompasObjectNotify) )
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
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
	return  notifyType >= koCreateDocument && notifyType <= koKeyPress && notifyType != koBeginOpenDocument; // koBeginCloseAllDocument;
}


/////////////////////////////////////////////////////////////////////////////
// ApplicationEvent message handlers
//-----------------------------------------------------------------------------
// koCreateDocument - Документ создан
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::CreateDocument( long pDoc, int docType ){
//METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// koOpenDocumenBegin - Начало открытия документа
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginOpenDocument( LPSTR docName ){
//METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// koOpenDocumen - Документ открыт
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::OpenDocument(long pDoc, int docType){
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// koActiveDocument - Переключение на другой активный документ
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChangeActiveDocument(long pDoc, int docType){
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// koApplicatinDestroy - Закрытие приложения
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ApplicationDestroy(){
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  PropertyManagerObject *macroObj=NULL;
  if ( macroObj )
    macroObj->EndProcess();
  return VARIANT_TRUE;
}

//-----------------------------------------------------------------------------
// koBeginCreate - Процесс создания файла
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginCreate( long type ){
//	METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}

//-----------------------------------------------------------------------------
// koBeginOpenFile - Процесс открытия файла
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginOpenFile(){
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
	return VARIANT_TRUE;
}

//-----------------------------------------------------------------------------
// BeginCloseAllDocument - Событие закрытия всех документов
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginCloseAllDocument() {
// ТНЮ K10   UpdateSlideBox( 0 ); 
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// KeyDown - событие клавиатуры. ( Нажимается клавиша )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyDown( long *       key,
                                                                            long         flags,
                                                                            VARIANT_BOOL sysKey ) 
{
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// KeyUp - событие клавиатуры. ( Отпускается клавиша )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyUp( long *       key,
                                                                          long         flags,
                                                                          VARIANT_BOOL sysKey ) 
{
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


//-----------------------------------------------------------------------------
// KeyPress - событие клавиатуры. ( Событие одиночного нажатия символьной клавиши )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyPress( long *       key,
                                                                             VARIANT_BOOL sysKey ) 
{
//  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginRequestFiles( long requestID,  VARIANT * files )
{
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginChoiceMaterial( long MaterialPropertyId )
{
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChoiceMaterial( long MaterialPropertyId, LPSTR material, double density )
{
  return VARIANT_TRUE;
}

STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::IsNeedConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam, VARIANT_BOOL * needConvert )
{
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam )
{
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::EndConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam )
{
  return VARIANT_TRUE;
}


STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChangeTheme( long )
{
  return VARIANT_TRUE;
}

STDMETHODIMP_( VARIANT_BOOL ) ApplicationEvent::XKompasObjectNotify::BeginDragOpenFiles( VARIANT * filesList, VARIANT_BOOL insert, VARIANT_BOOL * filesListChanged )
{
	return VARIANT_TRUE;
}