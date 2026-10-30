////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONEVENT_H
#define _APPLICATIONEVENT_H

#include "ABaseEvent.h"


////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обработчик событий от приложения
//
////////////////////////////////////////////////////////////////////////////////
class ApplicationEvent : public ABaseEvent
{
public:
	ApplicationEvent( LPUNKNOWN pObject );           
  virtual ~ApplicationEvent();

protected:
  // koCreateDocument - Документ создан
  afx_msg BOOL CreateDocument       ( LPDISPATCH newDoc, long docType );
  // koOpenDocumenBegin - Начало открытия документа
  afx_msg BOOL BeginOpenDocumen     ( LPCTSTR fileName );
  // koOpenDocumen - Документ открыт
  afx_msg BOOL OpenDocumen          ( LPDISPATCH newDoc, long docType );
  // koActiveDocument - Переключение на другой активный документ
  afx_msg BOOL ChangeActiveDocument ( LPDISPATCH newDoc, long docType );
  // koApplicatinDestroy - Закрытие приложения
  afx_msg BOOL ApplicationDestroy   ();
  // koBeginCreate - Начало создания документа(до диалога выбора типа)
  afx_msg BOOL BeginCreate          ( long docType );
  // koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
  afx_msg BOOL BeginOpenFile        ();
  // koBeginCloseAllDocument - Начало закрытия всех открытых документов
  afx_msg BOOL BeginCloseAllDocument();
  // koKeyDown - Нажатие клавиши
  afx_msg BOOL KeyDown              ( long * key, long flags, BOOL systemKey );
  // koKeyUp - Отпускание клавиши
  afx_msg BOOL KeyUp                ( long * key, long flags, BOOL systemKey );
	// koKeyPress - Одиночное нажатие символьной клавиши
  afx_msg BOOL KeyPress             ( long * key, BOOL systemKey );
	DECLARE_EVENTSINK_MAP()
};

ABaseEvent * NewApplicationEvent();
/////////////////////////////////////////////////////////////////////////////

#endif 
