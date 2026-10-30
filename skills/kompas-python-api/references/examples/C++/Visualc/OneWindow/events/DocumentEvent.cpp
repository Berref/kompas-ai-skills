////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "DocumentFrameEvent.h"

#include "DocumentEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  


extern ABaseEvent * NewDocumentFrameEvent( LPDISPATCH doc, LPDISPATCH frame, DocumentFrameEventCalback & obj );


//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
ABaseEvent * NewDocumentEvent( LPDISPATCH doc )
{
	DocumentEvent * res = NULL;
	if ( doc ) 
  {
		if ( !ABaseEvent::FindEvent( DIID_ksDocumentFileNotify, doc ) ) 
    {
			res = new DocumentEvent( doc );
			if ( !res->Advise() ) 
      { 
				delete res;
				res = NULL;
			}
		}
	}
	return res;
}


////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::DocumentEvent( LPDISPATCH doc )
  : ABaseEvent( doc, DIID_ksDocumentFileNotify, doc, -1 )
{
}


//-------------------------------------------------------------------------------
//
// ---
DocumentEvent::~DocumentEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(DocumentEvent, ABaseEvent)
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginCloseDocument,  BeginCloseDocument,  VTS_NONE    )
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdCloseDocument,       CloseDocument,       VTS_NONE    )
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginSaveDocument,   BeginSaveDocument,   VTS_BSTR    )
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdSaveDocument,        SaveDocument,        VTS_NONE    )
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdActiveDocument,      Activate,            VTS_NONE    )
	ON_EVENT (DocumentEvent, (unsigned int)-1, kdDeactiveDocument,    Deactivate,          VTS_NONE    )
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdBeginSaveAsDocument, BeginSaveAsDocument, VTS_NONE    )
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdDocumentFrameOpen,   DocumentFrameOpen,   VTS_DISPATCH)
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdProcessActivate,     ProcessActivate,     VTS_I4      )
  ON_EVENT (DocumentEvent, (unsigned int)-1, kdProcessDeactivate,   ProcessDeactivate,   VTS_I4      )
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// kdBeginCloseDocument - Начало закрытия документа
// ---
afx_msg BOOL DocumentEvent::BeginCloseDocument()
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdCloseDocument - Документ закрыт
// ---
afx_msg BOOL DocumentEvent::CloseDocument()
{
  TerminateEvents( GUID_NULL, m_doc );
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdBeginSaveDocument - Начало сохранения документа
// ---
afx_msg BOOL DocumentEvent::BeginSaveDocument( LPCTSTR fileName )
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdSaveDocument - Документ сохранен
// ---
afx_msg BOOL DocumentEvent::SaveDocument()
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdActiveDocument - Документ активизирован.
// ---
afx_msg BOOL DocumentEvent::Activate()
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdDeactiveDocument - Документ деактивизирован.
// ---
afx_msg BOOL DocumentEvent::Deactivate()
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdBeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)
// ---
afx_msg BOOL DocumentEvent::BeginSaveAsDocument()
{
  return TRUE;
}

class LibObj;
extern LibObj * FindOrCreateLibObj( IDocumentFramePtr & docFrame, bool create );

//-------------------------------------------------------------------------------
// kdDocumentFrameOpen - Окно документа открылось
// ---
BOOL DocumentEvent::DocumentFrameOpen( LPDISPATCH v )
{
  FindOrCreateLibObj( IDocumentFramePtr(v), true );
  return TRUE;
}


//-----------------------------------------------------------------------------
// ProcessActivate - Активизация процесса.
// ---
afx_msg BOOL DocumentEvent::ProcessActivate( long id )
{
  return TRUE;
}


//-----------------------------------------------------------------------------
// kdProcessDeactivate - Деактивизация процесса.
// ---
afx_msg BOOL DocumentEvent::ProcessDeactivate( long id )
{
  return TRUE;
}
