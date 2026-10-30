////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent.cpp
// DocumentEvent - обработчик событий от документа (Auto)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#include <ksConstants.h>

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

DocumentEvent* NewDocumentEvent( IUnknown* docPtr ) {
  return  new DocumentEvent( docPtr );
}

//-------------------------------------------------------------------------------
//
// ---
HRESULT DocumentEvent::InvokeEvent(DISPID id, BOOL & resEvent, TVariant *params)
{
  HRESULT hr = E_NOTIMPL;
  switch(id)
  {
    case kdBeginCloseDocument : // Начало закрытия документа
      resEvent = BeginCloseDocument();
      hr = S_OK;
      break;
    case kdCloseDocument      : // Документ закрыт
      resEvent = CloseDocument();
      hr = S_OK;
      break;
    case kdBeginSaveDocument  : // Начало сохранения документа
      resEvent = BeginSaveDocument( (BSTR)params[0] );
      hr = S_OK;
      break;
    case kdSaveDocument       : // Документ сохранен
      resEvent = SaveDocument();
      hr = S_OK;
      break;
    case kdActiveDocument     : // Документ активизировался
      resEvent = Activate();
      hr = S_OK;
      break;
    case kdDeactiveDocument   : // Документ деактивизировался
      resEvent = Deactivate();
      hr = S_OK;
      break;
  }
  return hr;
}


//-------------------------------------------------------------------------------
// Начало закрытия документа
// ---
BOOL DocumentEvent::BeginCloseDocument()
{
  return LibMessage( _T("DocumentEvent - Начало закрытия документа\nЗакрыть документ?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Документ закрыт
// ---
BOOL DocumentEvent::CloseDocument()
{
  LibMessage( _T("DocumentEvent - Документ закрыт") );
  TerminateEvents( GUID_NULL, m_pDoc );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало сохранения документа
// ---
BOOL DocumentEvent::BeginSaveDocument( BSTR fileName )
{
  String s = fileName;
  s += _T("\n\nDocumentEvent - Начало сохранения документа\nСохранить документ?");
  return LibMessage( s.c_str(), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Документ сохранен
// ---
BOOL DocumentEvent::SaveDocument()
{
  LibMessage( _T("DocumentEvent - Документ сохранен") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Документ активизирован
// ---
BOOL DocumentEvent::Activate()
{
  LibMessage( _T("DocumentEvent - Документ активизирован") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Документ деактивизирован
// ---
BOOL DocumentEvent::Deactivate()
{
  LibMessage( _T("DocumentEvent - Документ деактивизирован") );
  return TRUE;
}






