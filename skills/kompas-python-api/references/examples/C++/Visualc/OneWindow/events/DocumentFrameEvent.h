////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOCUMENTFRAMEEVENT_H
#define _DOCUMENTFRAMEEVENT_H

#include "ABaseEvent.h"


////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
class DocumentFrameEventCalback
{
  public:
// АВВ К11     // frBeginPaint          - Начало отрисовки документа
// АВВ К11     BOOL BeginPaint( IDocumentFramePtr & docFrame, IPaintObjectPtr & paintObj ) { return true; }
// АВВ К11     // frClosePaint          - Конец отрисовки документа
// АВВ К11     BOOL ClosePaint( IDocumentFramePtr & docFrame, IPaintObjectPtr & paintObj ) { return true; }
// АВВ К11     // frMouseDown           - Нажатие кнопки мыши
// АВВ К11     BOOL MouseDown( IDocumentFramePtr & docFrame, short nButton, short nShiftState, long x, long y ) { return true; }
// АВВ К11     // frMouseUp             - Отпускание кнопки мыши
// АВВ К11     BOOL MouseUp      ( IDocumentFramePtr & docFrame, short nButton, short nShiftState, long x, long y ) { return true; }
// АВВ К11     // frMouseDblClick       - Двойной клик кнопки мыши
// АВВ К11     BOOL MouseDblClick( IDocumentFramePtr & docFrame, short nButton, short nShiftState, long x, long y ) { return true; }
   // frBeginPaintGL        - Начало создания листа в контексте OpenGL
   virtual BOOL BeginPaintGL ( IDocumentFramePtr & docFrame, ksGLObjectPtr & glObj, long drawMode ) { return true; }
// АВВ К11     // frClosePaintGL        - Окончание создания листа в контексте OpenGL
// АВВ К11     afx_msg BOOL ClosePaintGL       ( ksGLObjectPtr & glObj, long drawMode );
    // frAddGabarit          - Определение габаритов документа
    virtual BOOL AddGabarit( IDocumentFramePtr & docFrame, IGabaritObjectPtr & gabObj ) { return true; }
// АВВ К11     // frActivate            - Окно активизировалось
// АВВ К11     afx_msg BOOL Activate           ();
// АВВ К11     // frDeactivate          - Окно деактивизировалось
// АВВ К11     afx_msg BOOL Deactivate         ();
    // frCloseFrame          - Закрытие окна
    virtual BOOL CloseFrame( IDocumentFramePtr & docFrame ) { return true; }
// АВВ К11     // frMouseMove           - Перемещение мыши
// АВВ К11     afx_msg BOOL MouseMove          ( short nShiftState, long x, long y ); 

};

class DocumentFrameEvent : public ABaseEvent
{
  DocumentFrameEventCalback & m_obj;
public:
	DocumentFrameEvent( LPUNKNOWN  pObject, 
                      LPDISPATCH doc, DocumentFrameEventCalback & obj );           
  virtual ~DocumentFrameEvent();

protected:
// АВВ К11   // frBeginPaint          - Начало отрисовки документа
// АВВ К11   afx_msg BOOL BeginPaint         ( LPDISPATCH paintObj );
// АВВ К11   // frClosePaint          - Конец отрисовки документа
// АВВ К11   afx_msg BOOL ClosePaint         ( LPDISPATCH paintObj );
// АВВ К11   // frMouseDown           - Нажатие кнопки мыши
// АВВ К11   afx_msg BOOL MouseDown          ( short nButton, short nShiftState, long x, long y );
// АВВ К11   // frMouseUp             - Отпускание кнопки мыши
// АВВ К11   afx_msg BOOL MouseUp            ( short nButton, short nShiftState, long x, long y );
// АВВ К11   // frMouseDblClick       - Двойной клик кнопки мыши
// АВВ К11   afx_msg BOOL MouseDblClick      ( short nButton, short nShiftState, long x, long y );
   // frBeginPaintGL        - Начало создания листа в контексте OpenGL
   afx_msg BOOL BeginPaintGL( LPDISPATCH glObj, long drawMode );
// АВВ К11   // frClosePaintGL        - Окончание создания листа в контексте OpenGL
// АВВ К11   afx_msg BOOL ClosePaintGL       ( LPDISPATCH glObj, long drawMode );
  // frAddGabarit          - Определение габаритов документа
  afx_msg BOOL AddGabarit   ( LPDISPATCH gabObj );
// АВВ К11   // frActivate            - Окно активизировалось
// АВВ К11   afx_msg BOOL Activate           ();
// АВВ К11   // frDeactivate          - Окно деактивизировалось
// АВВ К11   afx_msg BOOL Deactivate         ();
  // frCloseFrame          - Закрытие окна
  afx_msg BOOL CloseFrame   ();
// АВВ К11   // frMouseMove           - Перемещение мыши
// АВВ К11   afx_msg BOOL MouseMove          ( short nShiftState, long x, long y ); 

	DECLARE_EVENTSINK_MAP()
};

ABaseEvent * NewDocumentFrameEvent( LPDISPATCH doc, LPDISPATCH frame, DocumentFrameEventCalback & obj );

/////////////////////////////////////////////////////////////////////////////

#endif 
