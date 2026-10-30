////////////////////////////////////////////////////////////////////////////////
//
// StampEvent  - обработчик событий штампа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _STAMPEVENT_H
#include "StampEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// StampEvent  - обработчик событий штампа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
StampEvent::StampEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
  : BaseEvent( pObject, DIID_ksStampNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
StampEvent::~StampEvent()
{
}     


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(StampEvent, BaseEvent)
  ON_EVENT (StampEvent, (unsigned int)-1, kdBeginEditStamp,       BeginEditStamp,       VTS_NONE)
  ON_EVENT (StampEvent, (unsigned int)-1, kdEndEditStamp,         EndEditStamp,         VTS_BOOL)
  ON_EVENT (StampEvent, (unsigned int)-1, kdStampCellDblClick,    StampCellDblClick,    VTS_I4)
  ON_EVENT (StampEvent, (unsigned int)-1, kdStampCellBeginEdit,   StampCellBeginEdit,   VTS_I4)
  ON_EVENT (StampEvent, (unsigned int)-1, kdStampBeginClearCells, StampBeginClearCells, VTS_VARIANT)
END_EVENTSINK_MAP()


//-----------------------------------------------------------------------------
// kdBeginEditStamp - Начало редактирования штампа
// ---
afx_msg VARIANT_BOOL StampEvent::BeginEditStamp()
{
  if ( IsSelfAdvise() && theApp.m_mes_STAMP )
  {
    CString str( m_libName + " --> StampEvent::BeginEditStamp" );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}


//-----------------------------------------------------------------------------
// kdEndEditStamp - Завершение редактирования штампа
// ---
afx_msg VARIANT_BOOL StampEvent::EndEditStamp( bool editResult )
{
  if ( IsSelfAdvise() && theApp.m_mes_STAMP )
  {
    CString str;
    str.Format( _T("%s --> StampEvent::EndEditStamp\neditResult = %s"), (LPCTSTR)m_libName, editResult ? _T("TRUE") : _T("FALSE") );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;  
}


//-----------------------------------------------------------------------------
// kdStampCellDblClick - ДаблКлик по штампу
// ---
afx_msg VARIANT_BOOL StampEvent::StampCellDblClick( long number )
{
  if ( IsSelfAdvise() && theApp.m_mes_STAMP )
  {
    CString str;
    str.Format( _T("%s --> StampEvent::StampCellDblClick\nnumber = %i"), (LPCTSTR)m_libName, number );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true; 
}


//-----------------------------------------------------------------------------
// kdStampCellBeginEdit - Начало редактирования ячейки штампа
// ---
afx_msg VARIANT_BOOL StampEvent::StampCellBeginEdit( long number )
{
  if ( IsSelfAdvise() && theApp.m_mes_STAMP )
  {
    CString str;
    str.Format( _T("%s --> StampEvent::StampCellBeginEdit\nnumber = %i"), (LPCTSTR)m_libName, number );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true; 
}

//-----------------------------------------------------------------------------
// kdStampBeginClearCells - Начало очистки ячеек штампа
// ---
VARIANT_BOOL StampEvent::StampBeginClearCells( LPVARIANT numbers )
{
  if ( IsSelfAdvise() && theApp.m_mes_STAMP )
  {
    CString str;
    str.Format( _T( "%s --> StampEvent::StampBeginClearCells" ), (LPCTSTR)m_libName );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( (LPCTSTR)str );
  }
  return true;
}
