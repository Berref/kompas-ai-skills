////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DocumentFrameEvent.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Новое событие от окна документа
// ---
ABaseEvent * NewDocumentFrameEvent( LPDISPATCH doc, LPDISPATCH frame, DocumentFrameEventCalback & obj )
{
  DocumentFrameEvent * res = NULL;

  if ( doc ) 
  {
    res = (DocumentFrameEvent *)ABaseEvent::FindEventByContainer(IID_IViewsAndLayersManager, frame); 
    if ( !res ) 
    {
  		res = new DocumentFrameEvent( frame, doc, obj );
	  	
      if ( !res->Advise() ) 
      { 
		  	delete res;
			  res = NULL;
      } // if ( !res->Advise() ) 
    } // if ( !ABaseEvent::FindEventByContainer(IID_IViewsAndLayersManager, obj) ) 
  } // if ( doc )

  return res;

}


////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::DocumentFrameEvent( LPUNKNOWN frame, LPDISPATCH doc, DocumentFrameEventCalback & _obj)
  : ABaseEvent( frame, DIID_ksDocumentFrameNotify, doc )
  , m_obj( _obj )  
{
}


//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::~DocumentFrameEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(DocumentFrameEvent, ABaseEvent)
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginPaint,          BeginPaint,          VTS_DISPATCH               )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frClosePaint,          ClosePaint,          VTS_DISPATCH               )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseDown,           MouseDown,           VTS_I2 VTS_I2 VTS_I4 VTS_I4)
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseUp,             MouseUp,             VTS_I2 VTS_I2 VTS_I4 VTS_I4)
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseDblClick,       MouseDblClick,       VTS_I2 VTS_I2 VTS_I4 VTS_I4)
 	 ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginPaintGL,        BeginPaintGL,        VTS_DISPATCH VTS_I4        )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frClosePaintGL,        ClosePaintGL,        VTS_DISPATCH VTS_I4        )
	 ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frAddGabarit,          AddGabarit,          VTS_DISPATCH               )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frActivate,            Activate,            VTS_NONE                   )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frDeactivate,          Deactivate,          VTS_NONE                   )
   ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frCloseFrame,          CloseFrame,          VTS_NONE                   )
// ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseMove,           MouseMove,           VTS_I2 VTS_R8 VTS_R8       )
END_EVENTSINK_MAP()


////-------------------------------------------------------------------------------
//// frBeginPaint          - Начало отрисовки документа
//// ---
//BOOL DocumentFrameEvent::BeginPaint( LPDISPATCH paintObj )
//{
//  return TRUE;
//}
//
//
////-------------------------------------------------------------------------------
//// frClosePaint          - Конец отрисовки документа
//// ---
//BOOL DocumentFrameEvent::ClosePaint( LPDISPATCH paintObj )
//{
//  return TRUE;
//}
//
//
////-------------------------------------------------------------------------------
//// frMouseDown           - Нажатие кнопки мыши
//// ---
//BOOL DocumentFrameEvent::MouseDown( short nButton, short nShiftState, long x, long y )
//{
//  return TRUE;
//}
//
//
////-------------------------------------------------------------------------------
//// frMouseUp             - Отпускание кнопки мыши
//// ---
//BOOL DocumentFrameEvent::MouseUp( short nButton, short nShiftState, long x, long y )
//{
//  return TRUE;
//}
//
//
////-------------------------------------------------------------------------------
//// frMouseDblClick       - Двойной клик кнопки мыши
//// ---
//BOOL DocumentFrameEvent::MouseDblClick( short nButton, short nShiftState, long x, long y )
//{
//  return TRUE;
//}


//-------------------------------------------------------------------------------
// frBeginPaintGL   - Начало отрисовки в контексте OpenGL
// ---
BOOL DocumentFrameEvent::BeginPaintGL( LPDISPATCH glObj, long drawMode )
{
  return m_obj.BeginPaintGL( IDocumentFramePtr(m_pContainer), ksGLObjectPtr(glObj), drawMode );
}


////-------------------------------------------------------------------------------
//// frClosePaintGL   - Окончание отрисовки в контексте OpenGL
//// ---
//BOOL DocumentFrameEvent::ClosePaintGL( LPDISPATCH glObj, long drawMode )
//{
//  return TRUE;
//}


//-------------------------------------------------------------------------------
// frAddGabarit          - Определение габаритов документа
// ---
BOOL DocumentFrameEvent::AddGabarit( LPDISPATCH gabObj )
{
  return m_obj.AddGabarit( IDocumentFramePtr(m_pContainer), IGabaritObjectPtr(gabObj) );
}


////-------------------------------------------------------------------------------
//// frActivate            - Окно активизировалось
//// ---
//BOOL DocumentFrameEvent::Activate()
//{
//  return TRUE;
//}


////-------------------------------------------------------------------------------
//// frDeactivate          - Окно деактивизировалось
//// ---
//BOOL DocumentFrameEvent::Deactivate()
//{
//  return TRUE;
//}


//-------------------------------------------------------------------------------
// frCloseFrame          - Закрытие окна
// ---
BOOL DocumentFrameEvent::CloseFrame()
{
  return m_obj.CloseFrame( IDocumentFramePtr(m_pContainer) );
}


////-----------------------------------------------------------------------------
//// frMouseMove           - Перемещение мыши
//// ---
//BOOL DocumentFrameEvent::MouseMove( short nShiftState, long x, long y )
//{
//  return TRUE;
//}

