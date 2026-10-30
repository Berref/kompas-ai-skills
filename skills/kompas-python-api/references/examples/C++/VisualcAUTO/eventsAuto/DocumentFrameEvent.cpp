////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _DOCUMENTFRAMEEVENT_H
#include "DocumentFrameEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// DocumentFrameEvent  - обработчик событий от окна документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::DocumentFrameEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
: BaseEvent( pObject, DIID_ksDocumentFrameNotify, doc, -1, NULL, selfAdvise )
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
BEGIN_EVENTSINK_MAP(DocumentFrameEvent, BaseEvent)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginPaint,           BeginPaint,           VTS_DISPATCH)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frClosePaint,           ClosePaint,           VTS_DISPATCH)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseDown,            MouseDown,            VTS_I2 VTS_I2 VTS_I4 VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseUp,              MouseUp,              VTS_I2 VTS_I2 VTS_I4 VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseDblClick,        MouseDblClick,        VTS_I2 VTS_I2 VTS_I4 VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginPaintGL,         BeginPaintGL,         VTS_DISPATCH VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frClosePaintGL,         ClosePaintGL,         VTS_DISPATCH VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frAddGabarit,           AddGabarit,           VTS_DISPATCH)
//ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginCurrentProcess,  BeginCurrentProcess,  VTS_I4)
//ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frStopCurrentProcess,   StopCurrentProcess,   VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frActivate,             Activate,             VTS_NONE)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frDeactivate,           Deactivate,           VTS_NONE)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frCloseFrame,           CloseFrame,           VTS_NONE)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frMouseMove,            MouseMove,            VTS_I2 VTS_I4 VTS_I4)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frShowOcxTree,          ShowOcxTree,          VTS_DISPATCH VTS_BOOL)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frBeginPaintTmpObjects, BeginPaintTmpObjects, VTS_NONE)
  ON_EVENT (DocumentFrameEvent, (unsigned int)-1, frClosePaintTmpObjects, ClosePaintTmpObjects, VTS_NONE)

END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// frBeginPaint          - Начало отрисовки документа
// ---
VARIANT_BOOL DocumentFrameEvent::BeginPaint( LPDISPATCH paintObj )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + " --> DocumentFrameEvent::BeginPaint" );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frClosePaint          - Конец отрисовки документа
// ---
VARIANT_BOOL DocumentFrameEvent::ClosePaint( LPDISPATCH paintObj )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + " --> DocumentFrameEvent::ClosePaint" );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frMouseDown           - Нажатие кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::MouseDown( short nButton, short nShiftState, long x, long y )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str;
    str.Format( _T("%s --> SelectMngEvent::MouseDown\nnButton = %i\nnShiftState = %i\nX = %i\nY = %i"), 
                (LPCTSTR)m_libName, nButton, nShiftState, x, y );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frMouseUp             - Отпускание кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::MouseUp( short nButton, short nShiftState, long x, long y )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str;
    str.Format( _T("%s --> SelectMngEvent::MouseUp\nnButton = %i\nnShiftState = %i\nX = %i\nY = %i"), 
                (LPCTSTR)m_libName, nButton, nShiftState, x, y );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frMouseDblClick       - Двойной клик кнопки мыши
// ---
VARIANT_BOOL DocumentFrameEvent::MouseDblClick( short nButton, short nShiftState, long x, long y )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str;
    str.Format( _T("%s --> SelectMngEvent::MouseDblClick\nnButton = %i\nnShiftState = %i\nX = %i\nY = %i"), 
                (LPCTSTR)m_libName, nButton, nShiftState, x, y );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frBeginPaintGL   - Начало отрисовки в контексте OpenGL
// ---
VARIANT_BOOL DocumentFrameEvent::BeginPaintGL( LPDISPATCH glObj, long drawMode )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::BeginPaintGL") );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frClosePaintGL   - Окончание отрисовки в контексте OpenGL
// ---
VARIANT_BOOL DocumentFrameEvent::ClosePaintGL( LPDISPATCH glObj, long drawMode )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::CloseClosePaintGL") );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frAddGabarit          - Определение габаритов документа
// ---
VARIANT_BOOL DocumentFrameEvent::AddGabarit( LPDISPATCH gabObj )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::AddGabarit") );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frBeginCurrentProcess - Начало текущего процесса
// ---
VARIANT_BOOL DocumentFrameEvent::BeginCurrentProcess( long id )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::BeginCurrentProcess") );
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frStopCurrentProcess  - Окончание текущего процесса
// ---
VARIANT_BOOL DocumentFrameEvent::StopCurrentProcess( long id )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::StopCurrentProcess") );
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frActivate            - Окно активизировалось
// ---
VARIANT_BOOL DocumentFrameEvent::Activate()
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::Activate") );
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frDeactivate          - Окно деактивизировалось
// ---
VARIANT_BOOL DocumentFrameEvent::Deactivate()
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::Deactivate") );
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frCloseFrame          - Закрытие окна
// ---
VARIANT_BOOL DocumentFrameEvent::CloseFrame()
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T(" --> DocumentFrameEvent::CloseFrame") );
    kompas->ksMessage( str.GetBuffer(0) );
    delete this;
  }
  return true;
}

//-------------------------------------------------------------------------------
// frMouseMove           - Перемещение мыши
// ---
VARIANT_BOOL DocumentFrameEvent::MouseMove( short nShiftState, long x, long y )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str;
    str.Format( _T( "%s --> SelectMngEvent::MouseMove\nnShiftState = %i\nX = %i\nY = %i" ),
                (LPCTSTR)m_libName, nShiftState, x, y );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frShowOcxTree           -  
// ---
VARIANT_BOOL DocumentFrameEvent::ShowOcxTree( LPDISPATCH tree, VARIANT_BOOL show )
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T( " --> DocumentFrameEvent::ShowOcxTree" ) );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frBeginPaintTmpObjects          - Начало отрисовки временных объектов  
// ---
VARIANT_BOOL DocumentFrameEvent::BeginPaintTmpObjects()
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T( " --> DocumentFrameEvent::BeginPaintTmpObjects" ) );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// frClosePaintTmpObjects          - Конец отрисовки временных объектов
// ---
VARIANT_BOOL DocumentFrameEvent::ClosePaintTmpObjects()
{
  if ( IsSelfAdvise() /*&& theApp.m_mes_SELECT*/ )
  {
    CString str( m_libName + _T( " --> DocumentFrameEvent::ClosePaintTmpObjects" ) );
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

