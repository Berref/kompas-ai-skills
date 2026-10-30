////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent.h
// Object2DEvent - обработчик событий от 2D документа (Auto)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _OBJECT2DEVENT_H
#define _OBJECT2DEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#ifdef __LIGHT_VERSION__
  #ifndef __KL_TLB_H
  #include <kl_tlb.h>
  #endif
#else
  #ifndef __KS_TLB_H
  #include <ks_tlb.h>
  #endif
#endif


//---------------------------------------------------------------------------
// DocumentEvent - обработчик событий от 2D документа (TEventsDispatcher)
// ---
class Object2DEvent : public BaseEvent
{
public:
  Object2DEvent( LPUNKNOWN pContainer ): BaseEvent(pContainer, DIID_ksObject2DNotify) {}
  ~Object2DEvent(){}

protected:
  virtual HRESULT InvokeEvent(DISPID id, BOOL & resEvent, TVariant * params);

  // Обработчики событий
  BOOL ChangeActive( long objRef );    // Переключение активности объекта( вид, слой)
  BOOL BeginDelete( long objRef );     // Начало удаления объекта
  BOOL Delete( long objRef );          // Удаление объекта
  BOOL BeginMove( long objRef );       // Начало сдвига объекта
  BOOL Move( long objRef );            // Сдвиг объекта
  BOOL BeginRotate( long objRef );     // Начало поворота объекта
  BOOL Rotate( long objRef );          // Поворот объекта
  BOOL BeginScale( long objRef );      // Начало масштабирования объекта
  BOOL Scale( long objRef );           // Масштабирования объекта
  BOOL BeginTransform( long objRef );  // Начало трансформации объекта
  BOOL Transform( long objRef );       // Трансформация объекта
  BOOL BeginCopy( long objRef );       // Начало копирования объекта
  BOOL Copy( long objRef );            // Копирование объекта
  BOOL BeginSymmetry( long objRef );   // Начало симметрии  объекта
  BOOL Symmetry( long objRef );        // Симметрия  объекта
  BOOL BeginProcess( long pType, long objRef ); // Начало редактирования\создания объекта
  BOOL EndProcess( long pType );      // Конец редактирования\создания объекта
  BOOL CreateObject( long objRef );    // Создание объекта
  BOOL UpdateObject( long objRef );    // Редактирование объекта  
};
#endif
