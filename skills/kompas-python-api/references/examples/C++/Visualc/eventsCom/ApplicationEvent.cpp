////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventCom.h"

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE* pModuleState;



BaseEvent* NewApplicationEvent() {
  ApplicationEvent* res = NULL;
	if ( !BaseEvent::FindEvents( ntKompasObjectNotify, 0 ) ) {
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
  BaseEvent(ntKompasObjectNotify, (reference)0 )
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
LPUNKNOWN ApplicationEvent::GetUnknown() {
  m_xKompasObjectNotify.AddRef();
  return &m_xKompasObjectNotify;
}

//-----------------------------------------------------------------------------
// Выдать имя метода
// ---
void ApplicationEvent::ShowEventName( LPCTSTR eventName, reference pDoc ) {
	if ( theApp.m_mes_APP ) {
		CString str = eventName;
		if ( pDoc ) 
			str += GetDocumentParam( pDoc );  
		::_ShowEventName( str );
	}
}

//-----------------------------------------------------------------------------
// Выдать описание
// ---
CString ApplicationEvent::EventCaption() {
	return _T("ApplicationEvent");
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
	return  notifyType >= koCreateDocument && notifyType <= koBeginDragOpenFiles;
}


/////////////////////////////////////////////////////////////////////////////
// ApplicationEvent message handlers
//-----------------------------------------------------------------------------
// koCreateDocument - Документ создан
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::CreateDocument( long pDoc, int docType ) { 
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  pThis->ShowEventName( _T("EventCom::ApplicationEvent::CreateDocument"), pDoc );
//	pThis->ShowObjParam( pDoc );
  if ( theApp.m_auto ) 
    AdviseDoc( pDoc );
  return true;
}


//-----------------------------------------------------------------------------
// koOpenDocumenBegin - Начало открытия документа
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginOpenDocument( LPSTR docName ) {
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  bool res = true;
  if ( theApp.m_mes_APP ) { 
    CString mess = _T("EventCom::ApplicationEvent::BeginOpenDocumen");
		mess += _T("\n");
		mess += docName;
    res = YesNoT( (LPTSTR) (LPCTSTR) mess ) == 1;
  }
  return res;
}


//-----------------------------------------------------------------------------
// koOpenDocumen - Документ открыт
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::OpenDocument(long _pDoc, int docType) {
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  pThis->ShowEventName( _T("EventCom::ApplicationEvent::OpenDocumen"), _pDoc );
  if ( theApp.m_auto ) 
	  AdviseDoc( _pDoc );

  return true;
}


//-----------------------------------------------------------------------------
// koActiveDocument - Переключение на другой активный документ
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChangeActiveDocument(long _pDoc, int docType) {
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  pThis->ShowEventName( _T("EventCom::ApplicationEvent::ChangeActiveDocument"), _pDoc );
  return true;
}


//-----------------------------------------------------------------------------
// koApplicatinDestroy - Закрытие приложения
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ApplicationDestroy(){
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  pThis->ShowEventName( _T("EventCom::ApplicationEvent::ApplicationDestroy"), 0 );
  pThis->Disconnect();
  return true;
}

//-----------------------------------------------------------------------------
// koBeginCreate - Процесс создания файла
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginCreate( long type ){
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  bool res = !theApp.m_mes_APP;
	if ( !res ) {
    int com = YesNoT( _T("EventCom::ApplicationEvent::BeginCreate\n ")
			                _T("Да - Создать чертеж\n") 
			                _T("Нет - запустить стандартный диалог создания файла\n")
									    _T("Отмена - не создавать файл") );
		switch ( com ) {
		  case 1: {
        DocumentParamT docParam;
				memset( &docParam, 0, sizeof(docParam) );
				docParam.type = type ? (unsigned char)type : lt_DocSheetStandart;
				reference doc = ::CreateDocumentT( &docParam );
				res = !doc; // если документ создан стандартный диалог не нужен
				if ( doc && theApp.m_auto )
					AdviseDoc( doc ); 
				break;
			}	
			case 0:
				res = true;
				break;
			case -1:
				res = false;
		}
	}
	return res;
}

//-----------------------------------------------------------------------------
// koBeginOpenFile - Процесс открытия файла
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginOpenFile() {
  METHOD_PROLOGUE_EX_(ApplicationEvent, KompasObjectNotify)
  bool res = !theApp.m_mes_APP;
	if ( !res ) {
    int com = YesNoT( _T("EventCom::ApplicationEvent::BeginOpenFile\n ")
			                _T("Да - Создать чертеж\n") 
			                _T("Нет - запустить стандартный диалог открытия файла\n")
										  _T("Отмена - не открывать файл") );
		switch ( com ) {
		  case 1: {
        DocumentParam docParam;
				memset( &docParam, 0, sizeof(docParam) );
				docParam.type = lt_DocSheetStandart;
				reference doc = ::CreateDocument( &docParam );
				res = !doc; // если документ создан стандартный диалог не нужен
				if ( doc && theApp.m_auto )
					AdviseDoc( doc ); 
				break;
			}	
			case 0:
				res = true;
				break;
			case -1:
				res = false;
		}
	}
	return res;
}


//-----------------------------------------------------------------------------
// BeginCloseAllDocument - Событие закрытия всех документов
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginCloseAllDocument() {
  return !theApp.m_mes_APP || YesNoT( _T("EventCom::ApplicationEvent::BeginCloseAllDocument\nЗакрыть все?") ) == 1;
}


//-----------------------------------------------------------------------------
// KeyDown - событие клавиатуры. ( Нажимается клавиша )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyDown( long *       key,
                                                                            long         flags,
                                                                            VARIANT_BOOL sysKey ) 
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  //pThis->ShowEventName( _T( "EventCom::ApplicationEvent::KeyDown" ), 0 );
  return true;
}


//-----------------------------------------------------------------------------
// KeyUp - событие клавиатуры. ( Отпускается клавиша )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyUp( long *       key,
                                                                          long         flags,
                                                                          VARIANT_BOOL sysKey ) 
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  //pThis->ShowEventName( _T( "EventCom::ApplicationEvent::KeyUp" ), 0 );
  return true;
}


//-----------------------------------------------------------------------------
// KeyPress - событие клавиатуры. ( событие одиночного нажатия символьной клавиши )
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::KeyPress( long *       key,
                                                                             VARIANT_BOOL sysKey ) 
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  //pThis->ShowEventName( _T( "EventCom::ApplicationEvent::KeyPress" ), 0 );
  return true;
}


//-----------------------------------------------------------------------------
// koBeginRequestFiles - Событие запроса имен файлов
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginRequestFiles(long requestID,
                                                                                     VARIANT * files )
{
  if ( requestID == koRFCopyBilletPart )
  {
//  TCHAR filename[_MAX_PATH] = _T("");
//  res = ksChoiceFileT( _T("m3d"), _T("КОМПАС-Модели (*.m3d)|*.m3d"),filename, _MAX_PATH, 1 ) > 0;
//  if ( res && files )
//  {
//    files->vt = VT_BSTR;
//    files->bstrVal = _bstr_t(filename).copy(); 
//  }  
  }

  return !theApp.m_mes_APP || YesNoT( _T("EventCom::ApplicationEvent::BeginRequestFiles\nЗапросить имена файлов?") ) == 1;
}


//-----------------------------------------------------------------------------
// koBeginChoiceMaterial - Начало выбора материала.
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginChoiceMaterial( long MaterialPropertyId ) 
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::BeginChoiceMaterial" ), 0 );
  return !theApp.m_mes_APP || YesNoT( _T("Начать выбор материала?") ) == 1;
}

//-----------------------------------------------------------------------------
// koChoiceMaterial - Закончен выбор материала
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChoiceMaterial( long MaterialPropertyId, LPSTR material, double density ) 
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::ChoiceMaterial" ), 0 );
  return true;
}

//-----------------------------------------------------------------------------
// koIsNeedConvertToSavePrevious - Начало сохранения документа в предыдущую верию.
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::IsNeedConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam, VARIANT_BOOL * needConvert )
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::IsNeedConvertToSavePrevious" ), pDoc );
  return true;
}

//-----------------------------------------------------------------------------
// koBeginConvertToSavePrevious  - Начало конвертации документа перед записью в предыдущую верию.
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::BeginConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam )
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::BeginConvertToSavePrevious" ), pDoc );
	return true;
}

//-----------------------------------------------------------------------------
// koEndConvertToSavePrevious - Завершение конвертации документа перед записью в предыдущую верию
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::EndConvertToSavePrevious( long pDoc, int docType, long saveVersion, IUnknown * saveToPreviusParam )
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::EndConvertToSavePrevious" ), pDoc );
  return true;
}

//-----------------------------------------------------------------------------
// koChangeTheme - Изменение темы
// ---
STDMETHODIMP_(VARIANT_BOOL) ApplicationEvent::XKompasObjectNotify::ChangeTheme( long )
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::ChangeTheme" ), 0 );
  return true;
}

//-----------------------------------------------------------------------------
// koBeginDragOpenFiles - Открытие файлов перетаскиванием в окно Компас
// ---
STDMETHODIMP_( VARIANT_BOOL ) ApplicationEvent::XKompasObjectNotify::BeginDragOpenFiles( VARIANT * filesList, VARIANT_BOOL insert, VARIANT_BOOL * filesListChanged )
{
  METHOD_PROLOGUE_EX_( ApplicationEvent, KompasObjectNotify )
  pThis->ShowEventName( _T( "EventCom::ApplicationEvent::BeginDragOpenFiles" ), 0 );
  return true;
}
