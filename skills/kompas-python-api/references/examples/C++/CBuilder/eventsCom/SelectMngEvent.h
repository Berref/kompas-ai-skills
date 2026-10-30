////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent.h
// SelectMngEvent - обрабокчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _SELECTMNGEVENT_H
#define _SELECTMNGEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif  

//---------------------------------------------------------------------------
// SelectMngEvent - обрабокчик событий от приложения (TEventsDispatcher)
// ---
class SelectMngEvent : public TBaseEvent<ISelectionMngNotify, & IID_ISelectionMngNotify>
{
  reference m_refDoc;

public:
  SelectMngEvent( reference refDoc );

protected:
  // Обработчики событий
  //Обрабатывается ли библиотекой событие с номером notifyType
  virtual VARIANT_BOOL STDMETHODCALLTYPE IsNotifyProcess( int notifyType );
  // Объект селектирован
  virtual VARIANT_BOOL STDMETHODCALLTYPE Select( VARIANT obj );
  // Объект расселектирован
  virtual VARIANT_BOOL STDMETHODCALLTYPE Unselect( VARIANT obj );
  // Все объекты расселектированы
  virtual VARIANT_BOOL STDMETHODCALLTYPE UnselectAll( void );
};
#endif

