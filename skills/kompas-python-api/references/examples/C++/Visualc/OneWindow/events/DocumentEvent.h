////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOCUMENTEVENT_H
#define _DOCUMENTEVENT_H

#include "ABaseEvent.h"


////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
class DocumentEvent : public ABaseEvent
{
public:
	DocumentEvent( LPDISPATCH doc );           
  virtual ~DocumentEvent();

protected:
  // kdBeginCloseDocument - Начало закрытия документа.
  afx_msg   BOOL BeginCloseDocument ();
  // kdCloseDocument - Документ закрыт.
  afx_msg   BOOL CloseDocument      ();
  // kdBeginSaveDocument - Начало сохранения документа.
  afx_msg   BOOL BeginSaveDocument  ( LPCTSTR fileName );
  // kdSaveDocument - Документ сохранен.
  afx_msg   BOOL SaveDocument       ();
  // kdActiveDocument - Документ активизирован.
  afx_msg   BOOL Activate           ();
  // kdDeactiveDocument - Документ деактивизирован.
  afx_msg   BOOL Deactivate         ();
  // kdBeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)
  afx_msg   BOOL BeginSaveAsDocument();
  // kdDocumentFrameOpen - Окно документа открылось
  afx_msg   BOOL DocumentFrameOpen  ( LPDISPATCH v );
  // kdProcessActivate - Активизация процесса
  afx_msg BOOL ProcessActivate( long id );
  // kdProcessDeactivate - Деактивизация процесса
  afx_msg BOOL ProcessDeactivate( long id );


	DECLARE_EVENTSINK_MAP()
};

ABaseEvent * NewDocumentEvent( LPDISPATCH doc );
 
/////////////////////////////////////////////////////////////////////////////

#endif 
