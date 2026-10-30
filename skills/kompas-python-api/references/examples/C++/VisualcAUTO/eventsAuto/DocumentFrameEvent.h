////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обрабокчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOCUMENTFRAMEEVENT_H
#define _DOCUMENTFRAMEEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000  

/*
  typedef enum 
  {
    [helpstring("Начало отрисовки документа."),                   helpcontext(290)] frBeginPaint          = 1,
    [helpstring("Конец отрисовки документа."),                    helpcontext(290)] frClosePaint          = 2,
    [helpstring("Нажатие кнопки мыши."),                          helpcontext(290)] frMouseDown           = 3,
    [helpstring("Отпускание кнопки мыши."),                       helpcontext(290)] frMouseUp             = 4,
    [helpstring("Двойной клик кнопки мыши."),                     helpcontext(290)] frMouseDblClick       = 5,
    [helpstring("Начало создания листа в контексте OpenGL."),     helpcontext(290)] frBeginPaintGL        = 6,
    [helpstring("Окончание создания листа в контексте OpenGL."),  helpcontext(290)] frClosePaintGL        = 7,
    [helpstring("Определение габаритов документа."),              helpcontext(290)] frAddGabarit          = 8,
    [helpstring("Начало текущего процесса."),                     helpcontext(290)] frBeginCurrentProcess = 9,
    [helpstring("Окончание текущего процесса."),                  helpcontext(290)] frStopCurrentProcess  = 10,
    [helpstring("Окно активизировалось."),                        helpcontext(290)] frActivate            = 11,
    [helpstring("Окно деактивизировалось."),                      helpcontext(290)] frDeactivate          = 12,
    [helpstring("Закрытие окна."),                                helpcontext(290)] frCloseFrame          = 13,
  }
  ksDocumentFrameNotifyEnum;
*/

////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обрабокчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
class DocumentFrameEvent : public BaseEvent
{
public:
  DocumentFrameEvent( LPUNKNOWN pObject, 
                      LPDISPATCH doc, 
                      bool m_selfAdvise = true );           
  virtual ~DocumentFrameEvent();

protected:
  // frBeginPaint          - Начало отрисовки документа
  afx_msg VARIANT_BOOL BeginPaint( LPDISPATCH paintObj );
  // frClosePaint          - Конец отрисовки документа
  afx_msg VARIANT_BOOL ClosePaint( LPDISPATCH paintObj );
  // frMouseDown           - Нажатие кнопки мыши
  afx_msg VARIANT_BOOL MouseDown( short nButton, short nShiftState, long x, long y );
  // frMouseUp             - Отпускание кнопки мыши
  afx_msg VARIANT_BOOL MouseUp( short nButton, short nShiftState, long x, long y );
  // frMouseDblClick       - Двойной клик кнопки мыши
  afx_msg VARIANT_BOOL MouseDblClick( short nButton, short nShiftState, long x, long y );
  // frBeginPaintGL        - Начало создания листа в контексте OpenGL
  afx_msg VARIANT_BOOL BeginPaintGL( LPDISPATCH glObj, long drawMode );
  // frClosePaintGL        - Окончание создания листа в контексте OpenGL
  afx_msg VARIANT_BOOL ClosePaintGL( LPDISPATCH glObj, long drawMode );
  // frAddGabarit          - Определение габаритов документа
  afx_msg VARIANT_BOOL AddGabarit( LPDISPATCH gabObj );
  // frBeginCurrentProcess - Начало текущего процесса
  afx_msg VARIANT_BOOL BeginCurrentProcess( long id );
  // frStopCurrentProcess  - Окончание текущего процесса
  afx_msg VARIANT_BOOL StopCurrentProcess( long id );
  // frActivate            - Окно активизировалось
  afx_msg VARIANT_BOOL Activate();
  // frDeactivate          - Окно деактивизировалось
  afx_msg VARIANT_BOOL Deactivate();
  // frCloseFrame          - Закрытие окна
  afx_msg VARIANT_BOOL CloseFrame();
  // frMouseMove           - Перемещение мыши
  afx_msg VARIANT_BOOL MouseMove (short nShiftState, long x, long y);
  // frShowOcxTree         - 
  afx_msg VARIANT_BOOL ShowOcxTree(LPDISPATCH tree, VARIANT_BOOL show);
  // frBeginPaintTmpObjects          - Начало отрисовки временных объектов
  afx_msg VARIANT_BOOL BeginPaintTmpObjects();
  // frClosePaintTmpObjects          - Конец отрисовки временных объектов
  afx_msg VARIANT_BOOL ClosePaintTmpObjects();

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
