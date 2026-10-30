////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent.cpp
// ApplicationEvent - обработчик событий от приложения (Auto)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif
#include <ksConstants.h>

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

extern KompasObjectPtr kompasPtr;
//-------------------------------------------------------------------------------
//
// ---
void AdviseDoc( IUnknownPtr doc, long docType );


//-------------------------------------------------------------------------------
//
// ---
HRESULT ApplicationEvent::InvokeEvent(DISPID id, BOOL & resEvent, TVariant *params)
{
  HRESULT hr = E_NOTIMPL;
  switch(id)
  {
    case koCreateDocument       : // Документ создан
      resEvent = CreateDocument( (LPDISPATCH)params[0], (long)params[1] );
      hr = S_OK;
      break;
    case koBeginOpenDocument    : // Начало открытия документа
      resEvent = BeginOpenDocument( (BSTR)params[0] );
      hr = S_OK;
      break;
    case koOpenDocument         : // Документ открыт
      resEvent = OpenDocument( (LPDISPATCH)params[0], (long)params[1] );
      hr = S_OK;
      break;
    case koChangeActiveDocument : // Переключение на другой активный документ
      resEvent = ChangeActiveDocument( (LPDISPATCH)params[0], (long)params[1] );
      hr = S_OK;
      break;
    case koApplicatinDestroy    : // Закрытие приложения
      resEvent = ApplicationDestroy();
      hr = S_OK;
      break;
    case koBeginCreate          : // Процесс создания документа
      resEvent = BeginCreate( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginOpenFile        : // Процесс открытия документов
      resEvent = BeginOpenFile();
      hr = S_OK;
      break;
    case koBeginCloseAllDocument: // Событие закрытия всех документов
      resEvent = BeginCloseAllDocument();
      hr = S_OK;
      break;

  }
  return hr;
}


//-------------------------------------------------------------------------------
// koCreateDocument - Документ создан
// ---
BOOL ApplicationEvent::CreateDocument( LPDISPATCH newDoc, long docType )
{
//  AdviseDoc( newDoc, docType );

  LibMessage( _T("ApplicationEvent - Документ создан") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало открытия документа
// ---
BOOL ApplicationEvent::BeginOpenDocument( BSTR fileName )
{
  return LibMessage( _T("ApplicationEvent - Начало открытия документа\nОткрыть документ?"), MB_YESNO ) == IDYES;;
}


//-------------------------------------------------------------------------------
// Документ открыт
// ---
BOOL ApplicationEvent::OpenDocument( LPDISPATCH newDoc, long docType )
{
  LibMessage( _T("ApplicationEvent - Документ открыт") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Переключение на другой активный документ
// ---
BOOL ApplicationEvent::ChangeActiveDocument( LPDISPATCH newDoc, long docType )
{
  LibMessage( _T("ApplicationEvent - Переключение на другой активный документ") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Закрытие приложения
// ---
BOOL ApplicationEvent::ApplicationDestroy()
{
  LibMessage( _T("ApplicationEvent - Закрытие приложения") );
  Disconnect();
  EventListObject::TerminateEvents();
  return TRUE;
}

//-----------------------------------------------------------------------------
// koBeginCreate - Начало создания документа(до диалога выбора типа)
// ---
BOOL ApplicationEvent::BeginCreate( long docType )
{
  bool res = true;
  String str( _T("ApplicationEvent::BeginCreate\n"
                 "Да - Создать документ\n"
                 "Нет - запустить стандартный диалог открытия файла\n"
                 "Отмена - не открывать файл") );
  int comm = LibMessage( str.c_str(), MB_YESNOCANCEL );
  switch ( comm ) {
    case ID_YES: {
      ksDocumentParamPtr docParam( kompasPtr->GetParamStruct( ko_DocumentParam ) );
      docParam->Init();
      docParam->type = docType ? docType : lt_DocSheetStandart;
      ksDocument2DPtr doc(kompasPtr->Document2D() );
      res = !(bool)doc->ksCreateDocument( docParam );
      break;
    }
    case ID_CANCEL:
      res = false;
      break;
  }
  return res;
}

//-----------------------------------------------------------------------------
// koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
// ---
BOOL ApplicationEvent::BeginOpenFile()
{
  bool res = true;
  String str( _T("ApplicationEvent::BeginOpenFile\n"
                 "Да - Создать чертеж\n"
                 "Нет - запустить стандартный диалог открытия файла\n"
                 "Отмена - не открывать файл") );
  int comm = LibMessage( str.c_str(), MB_YESNOCANCEL );
  switch ( comm ) {
    case ID_YES:
    {
      ksDocumentParamPtr docParam( kompasPtr->GetParamStruct( ko_DocumentParam ) );
      docParam->Init();
      docParam->type = lt_DocSheetStandart;
      ksDocument2DPtr doc( kompasPtr->Document2D() );
      res = !(bool)doc->ksCreateDocument( docParam );
      break;
    }
    case ID_CANCEL:
      res = false;
      break;
  }
  return res;
}

//-----------------------------------------------------------------------------
// BeginCloseAllDocument - Событие закрытия всех документов
// ---
BOOL ApplicationEvent::BeginCloseAllDocument() {
  return LibMessage( _T("ApplicationEvent::BeginCloseAllDocument\nЗакрыть все?"), MB_YESNO ) == ID_YES;
}

