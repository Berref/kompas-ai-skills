////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent.h : header file
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _CFRAMEEVENT_H
#define _CFRAMEEVENT_H

#ifndef _ABASEEVENT_H
#include "abaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий Cобытия для окна документа
//
////////////////////////////////////////////////////////////////////////////////

class DocumentFrameEvent : public cBaseEvent
{
protected:
public:
	DocumentFrameEvent( LPUNKNOWN I, reference doc );           
  virtual ~DocumentFrameEvent();
  bool down;
  static int redrawType;
// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PropertyManagerEvent)
	//}}AFX_VIRTUAL
  virtual   LPUNKNOWN GetUnknown();
// Implementation

	BEGIN_INTERFACE_PART(DocumentFrameNotify, IDocumentFrameNotify)
		INIT_INTERFACE_PART(DocumentFrameEvent, DocumentFrameNotify)
        //Обрабатывается ли библиотекой событие с номером notifyType
        STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( int notifyType );
        // frBeginPaint = 1 Начало отрисовки документа.
        virtual VARIANT_BOOL STDMETHODCALLTYPE BeginPaint( 
            IUnknown __RPC_FAR *paintObj);
        // frClosePaint = 2 Конец отрисовки документа.
        virtual VARIANT_BOOL STDMETHODCALLTYPE ClosePaint( 
            IUnknown __RPC_FAR *paintObj);
        // frMouseDown  = 3 Нажатие кнопки мыши.
        virtual VARIANT_BOOL STDMETHODCALLTYPE MouseDown( 
             short nButton,
             short nShiftState,
             long x,
             long y);
        // frMouseUp = 4 Отпускание кнопки мыши.
        virtual VARIANT_BOOL STDMETHODCALLTYPE MouseUp( 
             short nButton,
             short nShiftState,
             long x,
             long y);
        // frMouseDblClick = 5 Двойной клик кнопки мыши.
        virtual VARIANT_BOOL STDMETHODCALLTYPE MouseDblClick( 
            short nButton,
            short nShiftState,
            long x,
            long y);
        // frBeginCreateGLList = 6 Начало создания листа в контексте OpenGL.
        virtual VARIANT_BOOL STDMETHODCALLTYPE BeginPaintGL( 
            long drawMode);
        // frCloseCreateGLList = 7 Окончание создания листа в контексте OpenGL.
        virtual VARIANT_BOOL STDMETHODCALLTYPE ClosePaintGL( 
            long drawMode);
        // frAddGabarit = 8 Определение габаритов документа.
        virtual VARIANT_BOOL STDMETHODCALLTYPE AddGabarit( 
            IUnknown __RPC_FAR *gabObj);
        // frActivate = 9 Окно активизировалось.
        virtual VARIANT_BOOL STDMETHODCALLTYPE Activate( void);
        // frDeactivate = 10 Окно деактивизировалось.
        virtual VARIANT_BOOL STDMETHODCALLTYPE Deactivate( void);
        // frCloseFrame = 11 Закрытие окна.
        virtual VARIANT_BOOL STDMETHODCALLTYPE CloseFrame( void);

        virtual VARIANT_BOOL STDMETHODCALLTYPE MouseMove (
           short nShiftState,
           long x,
           long y );  
        
        virtual VARIANT_BOOL STDMETHODCALLTYPE ShowOcxTree (
          IUnknown * tree,
          VARIANT_BOOL show );

        // frBeginPaintTmpObjects          - Начало отрисовки временных объектов
        virtual VARIANT_BOOL STDMETHODCALLTYPE BeginPaintTmpObjects();
        // frClosePaintTmpObjects          - Конец отрисовки временных объектов
        virtual VARIANT_BOOL STDMETHODCALLTYPE ClosePaintTmpObjects();

        END_INTERFACE_PART(DocumentFrameNotify)
	
};


 
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
