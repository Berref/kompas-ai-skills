////////////////////////////////////////////////////////////////////////////////
//
// SpecificationEvent  - обрабокчик событий от спецификации
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _SPECIFICATIONEVENT_H
#define _SPECIFICATIONEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000     

/*
enum ksSpecificationNotifyEnum
{
  ssTuningSpcStyleBeginChange    =  1,
  ssTuningSpcStyleChange         =  2,
  ssChangeCurrentSpcDescription  =  3,
  ssSpcDescriptionAdd            =  4,
  ssSpcDescriptionRemove         =  5,
  ssSpcDescriptionBeginEdit      =  6,
  ssSpcDescriptionEdit           =  7,
  ssSynchronizationBegin         =  8,
  ssSynchronization              =  9,
  ssBeginCalcPositions           = 10,
  ssCalcPositions                = 11,
  ssBeginCreateObject            = 12
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// SpecificationEvent  - обрабокчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
class SpecificationEvent : public BaseEvent
{
public:
  SpecificationEvent( LPUNKNOWN pObject, 
                      LPDISPATCH doc, 
                      bool m_selfAdvise = true );           
  virtual ~SpecificationEvent();

protected:
  // ssTuningSpcStyleBeginChange - Начало изменения настроек спецификации
  VARIANT_BOOL TuningSpcStyleBeginChange( LPCTSTR libName, long numb );
  // ssTuningSpcStyleChange - Настроейки спецификации изменились
  VARIANT_BOOL TuningSpcStyleChange( LPCTSTR libName, long numb, BOOL isOk );
  // ssChangeCurrentSpcDescription - Изменилось текущее описание спецификации
  VARIANT_BOOL ChangeCurrentSpcDescription( LPCTSTR libName, long numb );
  // ssSpcDescriptionAdd - Добавилось описание спецификации
  VARIANT_BOOL SpcDescriptionAdd( LPCTSTR libName, long numb );
  // ssSpcDescriptionRemove - Удалилось описание спецификации
  VARIANT_BOOL SpcDescriptionRemove( LPCTSTR libName, long numb );
  // ssSpcDescriptionBeginEdit - Начало редактирования описания спецификации
  VARIANT_BOOL SpcDescriptionBeginEdit( LPCTSTR libName, long numb );
  // ssSpcDescriptionEdit - Отредактировали описание спецификации
  VARIANT_BOOL SpcDescriptionEdit( LPCTSTR libName, long numb, BOOL isOk  );
  // ssSynchronizationBegin - Начало синхронизации
  VARIANT_BOOL SynchronizationBegin();
  // ssSynchronization - Синхронизация проведена
  VARIANT_BOOL Synchronization();
  // ssBeginCalcPositions - Начало  расчета позиций
  VARIANT_BOOL BeginCalcPositions();
  // ssCalcPositions - Проведен расчет позиций 
  VARIANT_BOOL CalcPositions();
  // ssBeginCreateObject - Начало создания объекта спецификации (до диалога выбора раздела ) 
  VARIANT_BOOL BeginCreateObject( long typeObj );

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
