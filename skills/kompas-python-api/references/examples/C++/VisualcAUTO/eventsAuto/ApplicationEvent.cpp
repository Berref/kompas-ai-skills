////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _APPLICATIONEVENT_H
#include "ApplicationEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//-
// ---
ApplicationEvent::ApplicationEvent( LPUNKNOWN pObject, bool selfAdvise /*true*/ )
  : BaseEvent( pObject, DIID_ksKompasObjectNotify, NULL, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
ApplicationEvent::~ApplicationEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(ApplicationEvent, BaseEvent)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koCreateDocument,              CreateDocument,                VTS_DISPATCH VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginOpenDocument,           BeginOpenDocumen,              VTS_BSTR)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koOpenDocument,                OpenDocumen,                   VTS_DISPATCH VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koChangeActiveDocument,        ChangeActiveDocument,          VTS_DISPATCH VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koApplicatinDestroy,           ApplicationDestroy,            VTS_NONE)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginCreate,                 BeginCreate,                   VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginOpenFile,               BeginOpenFile,                 VTS_NONE)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginCloseAllDocument,       BeginCloseAllDocument,         VTS_NONE)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyDown,                     KeyDown,                       VTS_PI4 VTS_I4 VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyUp,                       KeyUp,                         VTS_PI4 VTS_I4 VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyPress,                    KeyPress,                      VTS_PI4 VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginRequestFiles,           BeginRequestFiles,             VTS_I4 VTS_PVARIANT)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginChoiceMaterial,         BeginChoiceMaterial,           VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koChoiceMaterial,              ChoiceMaterial,                VTS_I4 VTS_BSTR VTS_R8)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koIsNeedConvertToSavePrevious, IsNeedConvertToSavePrevious,   VTS_DISPATCH VTS_I4 VTS_I4 VTS_DISPATCH VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginConvertToSavePrevious,  BeginConvertToSavePrevious,    VTS_DISPATCH VTS_I4 VTS_I4 VTS_DISPATCH)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koEndConvertToSavePrevious,    EndConvertToSavePrevious,      VTS_DISPATCH VTS_I4 VTS_I4 VTS_DISPATCH)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koChangeTheme,                 ChangeTheme,                   VTS_I4)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginDragOpenFiles,          BeginDragOpenFiles,            VTS_PVARIANT VTS_BOOL VTS_BOOL)

END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// koCreateDocument - Документ создан
// ---
afx_msg VARIANT_BOOL ApplicationEvent::CreateDocument( LPDISPATCH newDoc, long docType ) 
{    
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T("%s --> ApplicationEvent::CreateDocument\nnewDoc = %i\ndocType = %i"), (LPCTSTR)m_libName, newDoc, docType );
    kompas->ksMessage( (LPCTSTR)str );
  }  
  if ( theApp.m_auto )
    AdviseDoc( newDoc, docType );
  return true;
}


//-----------------------------------------------------------------------------
// koOpenDocumenBegin - Начало открытия документа
// ---
afx_msg VARIANT_BOOL ApplicationEvent::BeginOpenDocumen( LPCTSTR fileName )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T(" --> ApplicationEvent::BeginOpenDocumen\nfileName = ") + fileName );
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-----------------------------------------------------------------------------
// koOpenDocumen - Документ открыт
// ---
afx_msg VARIANT_BOOL ApplicationEvent::OpenDocumen( LPDISPATCH newDoc, long docType ) 
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T("%s --> ApplicationEvent::OpenDocumen\nnewDoc = %i\ndocType = %i"), (LPCTSTR)m_libName, newDoc, docType );
    kompas->ksMessage( (LPCTSTR)str );
  }
  if ( theApp.m_auto )
    AdviseDoc( newDoc, docType );
  return true;
}


//-----------------------------------------------------------------------------
// koActiveDocument - Переключение на другой активный документ
// ---
afx_msg VARIANT_BOOL ApplicationEvent::ChangeActiveDocument( LPDISPATCH newDoc, long docType )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T("%s --> ApplicationEvent::ChangeActiveDocument\nnewDoc = %i\ndocType = %i"), (LPCTSTR)m_libName, newDoc, docType );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-----------------------------------------------------------------------------
// koApplicatinDestroy - Закрытие приложения
// ---
afx_msg VARIANT_BOOL ApplicationEvent::ApplicationDestroy()
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T(" --> ApplicationEvent::ApplicationDestroy") );
    kompas->ksMessage( (LPCTSTR)str );
  }
  
  // Отписываемся от всех событий
  BaseEvent::TerminateEvents( GUID_NULL );
  return true;
}


//-----------------------------------------------------------------------------
// koBeginCreate - Начало создания документа(до диалога выбора типа)
// ---
afx_msg VARIANT_BOOL ApplicationEvent::BeginCreate( long docType )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T("%s --> ApplicationEvent::BeginCreate\ndocType = %i\n"), (LPCTSTR)m_libName, docType );
    str += _T("Да - Создать чертеж\n") 
           _T("Нет - запустить стандартный диалог открытия файла\n")
           _T("Отмена - не открывать файл");
    int comm = kompas->ksYesNo( (LPCTSTR)str );
    switch ( comm ) 
    {
      case 1: 
      {
        ksDocumentParamPtr docParam( kompas->GetParamStruct( ko_DocumentParam ) );
        docParam->Init();
        docParam->type = lt_DocSheetStandart;
        ksDocument2DPtr doc( kompas->Document2D() );
        doc->ksCreateDocument( docParam );
        res = !doc->Getreference(); // Если документ создан стандартный диалог не нужен
        break;
      }  
      case -1:
        res = false;
        break;
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
// ---
afx_msg VARIANT_BOOL ApplicationEvent::BeginOpenFile()
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T(" --> ApplicationEvent::BeginOpenFile\n")
                 _T("Да - Создать чертеж\n")
                 _T("Нет - запустить стандартный диалог открытия файла\n")
                  _T("Отмена - не открывать файл") );
    int comm = kompas->ksYesNo( (LPCTSTR)str );
    switch ( comm ) 
    {
      case 1: 
      {
        ksDocumentParamPtr docParam( kompas->GetParamStruct( ko_DocumentParam ) );
        docParam->Init();
        docParam->type = lt_DocSheetStandart;
        ksDocument2DPtr doc( kompas->Document2D() );
        res = !doc->ksCreateDocument( docParam );
        break;
      }  
      case -1:
        res = false;
        break;
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// koBeginCloseAllDocument - Начало закрытия всех открытых документов
// ---
afx_msg VARIANT_BOOL ApplicationEvent::BeginCloseAllDocument()
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T("%s --> ApplicationEvent::BeginCloseAllDocument\nЗакрыть все?"), (LPCTSTR)m_libName );
    res = !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return res;
}

//-----------------------------------------------------------------------------
// koKeyDown - событие клавиатуры. ( Нажимается клавиша )
// ---
VARIANT_BOOL ApplicationEvent::KeyDown( long * key, long flags, VARIANT_BOOL sysKey )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T( " --> ApplicationEvent::KeyDown" ) );
    //kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koKeyUp - событие клавиатуры. ( Отпускается клавиша )
// ---
VARIANT_BOOL ApplicationEvent::KeyUp( long * key, long flags, VARIANT_BOOL sysKey )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T( " --> ApplicationEvent::KeyUp" ) );
    //kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koKeyUp - событие клавиатуры. ( событие одиночного нажатия символьной клавиши )
// ---
VARIANT_BOOL ApplicationEvent::KeyPress( long * key, VARIANT_BOOL sysKey )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str( m_libName + _T( " --> ApplicationEvent::KeyPress" ) );
    //kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}


//-----------------------------------------------------------------------------
// koBeginRequestFiles - Начало закрытия всех открытых документов
// ---
afx_msg VARIANT_BOOL ApplicationEvent::BeginRequestFiles( long requestID, VARIANT * files )
{
  VARIANT_BOOL res = VARIANT_TRUE;
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    if ( requestID == koRFCopyBilletPart )
    {
      
      _bstr_t file = kompas->ksChoiceFile( _T("m3d"), _T("КОМПАС-Модели (*.m3d)|*.m3d"), 1 );
      if ( file.length() > 0 )
      {
        files->vt = VT_BSTR;
        files->bstrVal = file.copy(); 
      }  
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
// koBeginChoiceMaterial - Начало выбора материала
// ---
VARIANT_BOOL ApplicationEvent::BeginChoiceMaterial( long MaterialPropertyId )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( m_libName + _T( "%s --> ApplicationEvent::BeginChoiceMaterial\nMaterialPropertyId = %i\n" ), MaterialPropertyId );
    res = !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return res;
}

//-----------------------------------------------------------------------------
// koChoiceMaterial - Закончен выбор материала
// ---
VARIANT_BOOL ApplicationEvent::ChoiceMaterial( long MaterialPropertyId, LPSTR material, double density )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( m_libName + _T( " --> ApplicationEvent::ChoiceMaterial\nMaterialPropertyId = %i\n material =" ), MaterialPropertyId, material);
    kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koIsNeedConvertToSavePrevious - Начало сохранения документа в предыдущую верию
// ---
VARIANT_BOOL ApplicationEvent::IsNeedConvertToSavePrevious( LPDISPATCH newDoc, long docType, long saveVersion, LPDISPATCH saveToPreviusParam, VARIANT_BOOL * needConvert )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T( "%s --> ApplicationEvent::IsNeedConvertToSavePrevious\nnewDoc = %i\ndocType = %i" ), (LPCTSTR)m_libName, newDoc, docType );
    kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koBeginConvertToSavePrevious - Начало конвертации документа перед записью в предыдущую верию
// ---
VARIANT_BOOL ApplicationEvent::BeginConvertToSavePrevious( LPDISPATCH newDoc, long docType, long saveVersion, LPDISPATCH saveToPreviusParam )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T( "%s --> ApplicationEvent::BeginConvertToSavePrevious\nnewDoc = %i\ndocType = %i" ), (LPCTSTR)m_libName, newDoc, docType );
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koEndConvertToSavePrevious - Завершение конвертации документа перед записью в предыдущую верию
// ---
VARIANT_BOOL ApplicationEvent::EndConvertToSavePrevious( LPDISPATCH newDoc, long docType, long saveVersion, LPDISPATCH saveToPreviusParam )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T( "%s --> ApplicationEvent::BeginConvertToSavePrevious\nnewDoc = %i\ndocType = %i" ), (LPCTSTR)m_libName, newDoc, docType );
    kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koChangeTheme - Изменение темы
// ---
VARIANT_BOOL ApplicationEvent::ChangeTheme( long newTheme )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T( "%s --> ApplicationEvent::ChangeTheme\nnewTheme = %i" ), (LPCTSTR)m_libName, newTheme );
    kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

//-----------------------------------------------------------------------------
// koBeginDragOpenFiles - Открытие файлов перетаскиванием в окно Компас
// ---
VARIANT_BOOL ApplicationEvent::BeginDragOpenFiles( VARIANT * filesList, VARIANT_BOOL insert, VARIANT_BOOL * filesListChanged )
{
  if ( IsSelfAdvise() && theApp.m_mes_APP )
  {
    CString str;
    str.Format( _T( "%s --> ApplicationEvent::BeginDragOpenFiles"), (LPCTSTR)m_libName );
    kompas->ksMessage( (LPCTSTR)str );
  }

  return true;
}

