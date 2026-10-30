////////////////////////////////////////////////////////////////////////////////
//
// StampEvent  - обрабокчик событий штампа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _STAMPEVENT_H
#define _STAMPEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000  

/*
enum ksStampNotifyEnum
{
  kdBeginEditStamp = 1,
  kdEndEditStamp = 2,
  kdStampCellDblClick = 3,
  kdStampCellBeginEdit = 4
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// StampEvent  - обрабокчик событий штампа
//
////////////////////////////////////////////////////////////////////////////////
class StampEvent : public BaseEvent
{
public:
  StampEvent( LPUNKNOWN pObject, 
              LPDISPATCH doc , 
              bool m_selfAdvise = true);           
  virtual ~StampEvent();

protected:
  //kdBeginEditStamp - Начало редактирования штампа
  afx_msg   VARIANT_BOOL BeginEditStamp();
  //kdEndEditStamp - Завершение редактирования штампа
  afx_msg   VARIANT_BOOL EndEditStamp( bool editResult );
  //kdStampCellDblClick - ДаблКлик по штампу
  afx_msg   VARIANT_BOOL StampCellDblClick( long number );
  //kdStampCellBeginEdit - Начало редактирования ячейки штампа
  afx_msg   VARIANT_BOOL StampCellBeginEdit( long number );
  //kdStampBeginClearCells - Начало очистки ячеек штампа.
  afx_msg   VARIANT_BOOL StampBeginClearCells(LPVARIANT numbers);
  
  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
