////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обрабокчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _SELECTMNGEVENT_H
#define _SELECTMNGEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000  

/*
enum ksSelectionMngNotifyEnum
{
  ksmSelect = 1,
  ksmUnselect = 2,
  ksmUnselectAll = 3
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обрабокчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////
class SelectMngEvent : public BaseEvent
{
public:
  SelectMngEvent( LPUNKNOWN pObject, 
                  LPDISPATCH doc, 
                  bool m_selfAdvise = true );           
  virtual ~SelectMngEvent();

protected:
  // ksmSelect      - Объект селектирован
  afx_msg VARIANT_BOOL Select( LPVARIANT obj );
  // ksmUnselect    - Объект расселектирован
  afx_msg VARIANT_BOOL Unselect( LPVARIANT obj );
  // ksmUnselectAll - Все объекты расселектированы
  afx_msg VARIANT_BOOL UnselectAll();   

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
