// DocumentFrameEvent.h : header file
//
#ifndef _DOCUMENTFRAMEEVENT_H
#define _DOCUMENTFRAMEEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
class DocumentFrameEvent : public BaseEvent
{
// Attributes
public:
	DocumentFrameEvent( reference doc, LPUNKNOWN iObj );           
  virtual ~DocumentFrameEvent();

// Operations
public:
  void      ShowEventName( LPCTSTR eventName );
	virtual   CString   EventCaption();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DocumentFrameEvent)
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(DocumentFrameEvent)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
 virtual   LPUNKNOWN GetUnknown();
// Implementation

	BEGIN_INTERFACE_PART( DocumentFrameNotify, IDocumentFrameNotify )
		INIT_INTERFACE_PART( DocumentFrameEvent, DocumentFrameNotify)
    // frBeginPaint          - Начало отрисовки документа
    STDMETHOD_(VARIANT_BOOL, BeginPaint)( THIS_ IUnknown* paintObj );
    // frClosePaint          - Конец отрисовки документа
    STDMETHOD_(VARIANT_BOOL, ClosePaint)( THIS_ IUnknown* paintObj );
    // frMouseDown           - Нажатие кнопки мыши
    STDMETHOD_(VARIANT_BOOL, MouseDown)( THIS_ short nButton, short nShiftState, long x, long y );
    // frMouseUp             - Отпускание кнопки мыши
    STDMETHOD_(VARIANT_BOOL, MouseUp)( THIS_ short nButton, short nShiftState, long x, long y );
    // frMouseDblClick       - Двойной клик кнопки мыши
    STDMETHOD_(VARIANT_BOOL, MouseDblClick)( THIS_ short nButton, short nShiftState, long x, long y );
    // frBeginCreateGLList   - Начало создания листа в контексте OpenGL
    STDMETHOD_(VARIANT_BOOL, BeginPaintGL)( THIS_ long drawMode );
    // frCloseCreateGLList   - Окончание создания листа в контексте OpenGL
    STDMETHOD_(VARIANT_BOOL, ClosePaintGL)( THIS_ long drawMode );
    // frAddGabarit          - Определение габаритов документа
    STDMETHOD_(VARIANT_BOOL, AddGabarit)( THIS_ IUnknown* gabObj );
    // frBeginCurrentProcess - Начало текущего процесса
    STDMETHOD_(VARIANT_BOOL, BeginCurrentProcess)( THIS_ long id );
    // frStopCurrentProcess  - Окончание текущего процесса
    STDMETHOD_(VARIANT_BOOL, StopCurrentProcess)( THIS_ long id );
    // frActivate            - Окно активизировалось
    STDMETHOD_(VARIANT_BOOL, Activate)(THIS);
    // frDeactivate          - Окно деактивизировалось
    STDMETHOD_(VARIANT_BOOL, Deactivate)(THIS);
    // frCloseFrame          - Закрытие окна
    STDMETHOD_(VARIANT_BOOL, CloseFrame)(THIS);
    // frMouseMove           - Перемещение мыши
    STDMETHOD_(VARIANT_BOOL, MouseMove)( THIS_ short nShiftState, long x, long y );
    // frShowOcxTree         - 
    STDMETHOD_(VARIANT_BOOL, ShowOcxTree) (THIS_ IUnknown * tree,  VARIANT_BOOL show );

    // frBeginPaintTmpObjects          - Начало отрисовки временных объектов
    STDMETHOD_(VARIANT_BOOL, BeginPaintTmpObjects)( THIS_ );
    // frClosePaintTmpObjects          - Конец отрисовки временных объектов
    STDMETHOD_(VARIANT_BOOL, ClosePaintTmpObjects)( THIS_ );

    STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );

	END_INTERFACE_PART( DocumentFrameNotify )

};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
