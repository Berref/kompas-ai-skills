////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent.cpp
// ApplicationEvent - обработчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _DOCUMENTEVENT_H
#include "DocumentEvent.h"
#endif

#include <ksConstants.h>

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

extern int LibMessage( char* str, int flags = MB_OK );
//-------------------------------------------------------------------------------
//
// ---
ApplicationEvent::ApplicationEvent() :
  TBaseEvent<IKompasObjectNotify, & IID_IKompasObjectNotify>( ntKompasObjectNotify, 0 )
{
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::IsNotifyProcess( int notifyType )
{
	return  notifyType >= koCreateDocument && notifyType <= koBeginCloseAllDocument;
}

//-------------------------------------------------------------------------------
// Документ создан
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::CreateDocument( long pDoc, int docType )
{
  LibMessage( "ApplicationEvent - Документ создан" );
  return TRUE;
}

//-------------------------------------------------------------------------------
// Начало открытия документа
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginOpenDocument( LPCSTR docName )
{
  return LibMessage( "ApplicationEvent - Начало открытия документа\nОткрыть документ?", MB_YESNO ) == IDYES;
}

//-------------------------------------------------------------------------------
// Документ открыт
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::OpenDocument( long pDoc, int docType)
{
  LibMessage( "ApplicationEvent - Документ открыт" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Переключение на другой активный документ
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::ChangeActiveDocument( long pDoc, int docType)
{
  LibMessage( "ApplicationEvent - Переключение на другой активный документ" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Закрытие приложения
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::ApplicationDestroy( void )
{
  LibMessage( "ApplicationEvent - Закрытие приложения" );
  return TRUE;
}

//-----------------------------------------------------------------------------
// koBeginCreate - Процесс создания файла
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginCreate(long type){
  bool res = true;
  int com = YesNo( "ApplicationEvent::BeginCreate\n "
		               "Да - Создать чертеж\n"
		               "Нет - запустить стандартный диалог создания файла\n"
									 "Отмена - не создавать файл" );
	switch ( com ) {
	  case 1: {
      DocumentParam docParam;
			memset( &docParam, 0, sizeof(docParam) );
			docParam.type = type ? type : lt_DocSheetStandart;
			reference doc = ::CreateDocument( &docParam );
      res = !doc;
//			if ( doc )
//				AdviseDoc( doc );
			break;
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
// koBeginOpenFile - Процесс открытия файла
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginOpenFile(){
  bool res = true;
  int com = YesNo( "ApplicationEvent::BeginOpenFile\n "
		               "Да - Создать чертеж\n"
		               "Нет - запустить стандартный диалог открытия файла\n"
									 "Отмена - не открывать файл" );
	switch ( com ) {
	  case 1: {
      DocumentParam docParam;
			memset( &docParam, 0, sizeof(docParam) );
      docParam.type = lt_DocSheetStandart;
      reference doc = ::CreateDocument( &docParam );
      res = !doc; // если документ создан стандартный диалог не нужен
//      if ( doc && theApp.m_auto )
//        AdviseDoc( doc );
      break;
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
// BeginCloseAllDocument - Событие закрытия всех документов
// ---
VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginCloseAllDocument() {
  return YesNo( "EventCom::ApplicationEvent::BeginCloseAllDocument\nЗакрыть все?" ) == 1;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::KeyDown( long __RPC_FAR *key,
                                                  long flags,
                                                  VARIANT_BOOL sysKey)
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::KeyUp( long __RPC_FAR *key,
                                                        long flags,
                                                        VARIANT_BOOL sysKey)
{
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::KeyPress( long __RPC_FAR *key,
                                                           VARIANT_BOOL sysKey)
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginRequestFiles(  long requestID, VARIANT __RPC_FAR *files )
{
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginChoiceMaterial( long MaterialPropertyId )
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::ChoiceMaterial( long MaterialPropertyId, LPCSTR material, double density)
{
  return true;
}

 VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::IsNeedConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam,
			VARIANT_BOOL *needConvert)
{
  return true;
}


VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam)
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::EndConvertToSavePrevious(
			long pDoc,
			int docType,
			long saveVersion,
			LPUNKNOWN saveToPreviusParam)
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::ChangeTheme( long newTheme )
{
  return true;
}

VARIANT_BOOL STDMETHODCALLTYPE ApplicationEvent::BeginDragOpenFiles( VARIANT *filesList, VARIANT_BOOL insert, VARIANT_BOOL *filesListChanged)
{
  return true;
}


