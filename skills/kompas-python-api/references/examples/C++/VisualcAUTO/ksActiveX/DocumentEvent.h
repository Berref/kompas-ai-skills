#pragma once
#include "BaseEvent.h"

class DocumentEvent : public KSBaseEvent
{
public:
  DocumentEvent(LPDISPATCH doc);           
  virtual ~DocumentEvent();

protected:
  // kdBeginCloseDocument - Начало закрытия документа.
  afx_msg VARIANT_BOOL BeginCloseDocument();
  // kdCloseDocument - Документ закрыт.
  afx_msg VARIANT_BOOL CloseDocument();
  // kdBeginSaveDocument - Начало сохранения документа.
  afx_msg VARIANT_BOOL BeginSaveDocument(LPCTSTR fileName);
  // kdSaveDocument - Документ сохранен.
  afx_msg VARIANT_BOOL SaveDocument();
  // kdActiveDocument - Документ активизирован.
  afx_msg VARIANT_BOOL Activate();
  // kdDeactiveDocument - Документ деактивизирован.
  afx_msg VARIANT_BOOL Deactivate();
  // kdBeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)
  afx_msg VARIANT_BOOL BeginSaveAsDocument();

  DECLARE_EVENTSINK_MAP()
};
