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

extern int LibMessage( char* str, int flags  = MB_OK );

//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
BaseEvent*  NewDocumentEvent( reference doc ) {
	DocumentEvent* res = NULL;
	if ( doc ) {
		if ( !BaseEvent::FindEvents( ntDocumentFileNotify, doc ) ) {
			res = new DocumentEvent( doc );
			if ( !res->Advise() ) {
				delete res;
				res = NULL;
			}
		}
	}
	return res;
}

//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::DocumentEvent( reference refDoc ) :
  TBaseEvent<IDocumentFileNotify, & IID_IDocumentFileNotify>( ntDocumentFileNotify, refDoc, 0, refDoc )
{
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::IsNotifyProcess( int notifyType )
{
	return  notifyType >= kdBeginCloseDocument && notifyType <= kdBeginSaveAsDocument;
}


//-------------------------------------------------------------------------------
// Начало закрытия документа
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::BeginCloseDocument( void ) {
  return LibMessage( "DocumentEvent - Начало закрытия документа\nЗакрыть документ?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Документ закрыт
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::CloseDocument( void )
{
  LibMessage( "DocumentEvent - Документ закрыт" );
  TerminateEvents( 0, refDoc );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало сохранения документа
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::BeginSaveDocument( LPCSTR docName )
{
  AnsiString s = docName;
  s += "\n\nDocumentEvent - Начало сохранения документа\nСохранить документ?";
  return LibMessage( s.c_str(), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Документ сохранен
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::SaveDocument( void )
{
  LibMessage( "DocumentEvent - Документ сохранен" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Документ активизирован
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::Activate( void )
{
  LibMessage( "DocumentEvent - Документ активизирован" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Документ деактивизирован
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::Deactivate( void )
{
  LibMessage( "DocumentEvent - Документ деактивизирован" );
  return TRUE;
}

//-----------------------------------------------------------------------------
//kdBeginSaveAsDocument - Процесс сохранения файла с новым именем.
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::BeginSaveAsDocument() {
	bool res = true;
  int com = YesNo( "DocumentEvent::BeginSaveAsDocument\n "
   	               "Да - Сохранить чертеж\n"
	 	               "Нет - запустить стандартный диалог сохранения файла\n"
	 								 "Отмена - не сохранять файл" );
 	switch ( com ) {
    case 1: {
      int type = ksGetDocumentType( refDoc );
      switch ( type ) {
        case lt_DocTxtStandart:             //               7- текстовый документ стандартный
        case lt_DocTxtUser: {                //               8- текстовый документ нестандартный
          TextDocumentParam docParam;
          GetObjParam( refDoc, &docParam, sizeof(docParam), ALLPARAM );
          if ( !docParam.fileName[0] )
            res = !::SaveDocument( 0, "C:\\1.kdw" );
          else
            res = !::SaveDocument( 0, 0 );
          break;
        }
        default: {
          DocumentParam docParam;
          GetObjParam( refDoc, &docParam, sizeof(docParam), ALLPARAM );
          if ( !docParam.fileName[0] ) {
            switch ( type ) {
              case lt_DocFragment:           //               3- фрагмент
                res = !::SaveDocument( 0, "C:\\1.frw" );
                break;
              case lt_DocSheetStandart:
              case lt_DocSheetUser:
                res = !::SaveDocument( 0, "C:\\1.cdw" );
                break;
              case lt_DocSpc:                //               4- спецификация
              case lt_DocSpcUser:
                res = !::SaveDocument( 0, "C:\\1.spw" );
                break;
              case lt_DocPart3D:                  //          5- 3d-документ модель
                res = !::SaveDocument( 0, "C:\\1.m3d" );
                break;
              case lt_DocAssemble3D:                  //      6- 3d-документ сборка
                res = !::SaveDocument( 0, "C:\\1.a3d" );
                break;

            }
          }
          else
            res = !::SaveDocument( 0, 0 );
        }
      }
    }
    case 0:
      res = true;
      break;
    case -1:
      res = false;
  }
  return res;
}

//-----------------------------------------------------------------------------
//kdDocumentFrameOpen    - Окно документа открылось.
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::DocumentFrameOpen( LPUNKNOWN v ) {
  return true;
}

//-----------------------------------------------------------------------------
// kdProcessActivate      - Активизация процесса
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::ProcessActivate( long Id ) {
  return true;
}

//-----------------------------------------------------------------------------
// kdProcessDeactivate    - Деактивизация процесса
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::ProcessDeactivate( long Id ) {
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE STDMETHODCALLTYPE DocumentEvent::BeginProcess(long Id)
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE STDMETHODCALLTYPE DocumentEvent::EndProcess( long Id, VARIANT_BOOL Success)
{
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::BeginAutoSaveDocument( LPCSTR docName)
{
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::AutoSaveDocument( void )
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE DocumentEvent::ActivateToolbarSet( PCSTR oldToolbarSetId, LPCSTR newToolbarSetId)
{
  return true;
}
