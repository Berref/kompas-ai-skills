////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "ApplicationEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern KompasObjectPtr kompas;
extern IApplicationPtr newKompasAPI;         

//-------------------------------------------------------------------------------
// Создать обработчик событий приложения Компас
// ---
ABaseEvent * NewApplicationEvent()          
{
  ApplicationEvent* res = (ApplicationEvent*)ABaseEvent::FindEvent(DIID_ksKompasObjectNotify);
	if ( !res )
  {
		res = new ApplicationEvent( kompas );
		if ( !res->Advise() ) 
    { 
			delete res;
			res = NULL;
		}
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
ApplicationEvent::ApplicationEvent( LPUNKNOWN pObject )
  : ABaseEvent( pObject, DIID_ksKompasObjectNotify, NULL, -1 )
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
BEGIN_EVENTSINK_MAP(ApplicationEvent, ABaseEvent)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koCreateDocument,        CreateDocument,        VTS_DISPATCH VTS_I4    )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginOpenDocument,     BeginOpenDocumen,      VTS_BSTR               )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koOpenDocument,          OpenDocumen,           VTS_DISPATCH VTS_I4    )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koChangeActiveDocument,  ChangeActiveDocument,  VTS_DISPATCH VTS_I4    )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koApplicatinDestroy,     ApplicationDestroy,    VTS_NONE               )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginCreate,           BeginCreate,           VTS_I4                 )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginOpenFile,         BeginOpenFile,         VTS_NONE               )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koBeginCloseAllDocument, BeginCloseAllDocument, VTS_NONE               )
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyDown,               KeyDown,               VTS_PI4 VTS_I4 VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyUp,                 KeyUp,                 VTS_PI4 VTS_I4 VTS_BOOL)
  ON_EVENT (ApplicationEvent, (unsigned int)-1, koKeyPress,              KeyPress,              VTS_PI4 VTS_BOOL       )
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// koCreateDocument - Документ создан
// ---
afx_msg BOOL ApplicationEvent::CreateDocument( LPDISPATCH newDoc, long docType ) 
{    
  return true;
}


//-----------------------------------------------------------------------------
// koOpenDocumenBegin - Начало открытия документа
// ---
afx_msg BOOL ApplicationEvent::BeginOpenDocumen( LPCTSTR fileName )
{
  return true;
}


//-----------------------------------------------------------------------------
// koOpenDocumen - Документ открыт
// ---
afx_msg BOOL ApplicationEvent::OpenDocumen( LPDISPATCH newDoc, long docType ) 
{
  return true;
}


//-----------------------------------------------------------------------------
// koActiveDocument - Переключение на другой активный документ
// ---
afx_msg BOOL ApplicationEvent::ChangeActiveDocument( LPDISPATCH newDoc, long docType )
{
  return true;
}


//-----------------------------------------------------------------------------
// koApplicatinDestroy - Закрытие приложения
// ---
afx_msg BOOL ApplicationEvent::ApplicationDestroy()
{
  // Самоудаление
  kompas       = NULL;
  newKompasAPI = NULL;         
  ABaseEvent::TerminateEvents();
  return true;
}


//-----------------------------------------------------------------------------
// koBeginCreate - Начало создания документа(до диалога выбора типа)
// ---
afx_msg BOOL ApplicationEvent::BeginCreate( long docType )
{
  bool res = true;
  return res;
}


//-----------------------------------------------------------------------------
// koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
// ---
afx_msg BOOL ApplicationEvent::BeginOpenFile()
{
  bool res = true;
  return res;
}


//-----------------------------------------------------------------------------
// koBeginCloseAllDocument - Начало закрытия всех открытых документов
// ---
afx_msg BOOL ApplicationEvent::BeginCloseAllDocument()
{
  bool res = true;
  return res;
}


//-----------------------------------------------------------------------------
// koKeyDown - Нажатие клавиши
// ---
afx_msg BOOL ApplicationEvent::KeyDown ( long * key, long flags, BOOL systemKey )
{
  bool res = true;
  return res;
}


//-----------------------------------------------------------------------------
// koKeyUp - Отпускание клавиши
// ---
afx_msg BOOL ApplicationEvent::KeyUp ( long * key, long flags, BOOL systemKey )
{
  bool res = true;
  return res;
}


//-----------------------------------------------------------------------------
// koKeyPress - Одиночное нажатие символьной клавиши
// ---
afx_msg BOOL ApplicationEvent::KeyPress ( long * key, BOOL systemKey )
{
  bool res = true;
  return res;
}


