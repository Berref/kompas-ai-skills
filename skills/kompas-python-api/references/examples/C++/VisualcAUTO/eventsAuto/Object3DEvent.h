////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обрабокчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _OBJECT3DEVENT_H
#define _OBJECT3DEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000    

/*
enum ksObject3DNotifyEnum
{
  o3BeginDelete = 1,
  o3Delete = 2,
  o3Excluded = 3,
  o3Hidden = 4,
  o3BeginPropertyChanged = 5,
  o3PropertyChanged = 6,
  o3BeginPlacementChanged = 7,
  o3PlacementChanged = 8,
  o3BeginProcess = 9,
  o3EndProcess = 10,
  o3CreateObject = 11,
  o3UpdateObject = 12
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обрабокчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////
class Object3DEvent : public BaseEvent
{
  ksObject3DNotifyResultPtr m_res;

public:
  Object3DEvent( LPUNKNOWN object, 
                 LPDISPATCH doc, 
                 long objType,
                 LPDISPATCH obj3D,
                 ksObject3DNotifyResultPtr res, 
                 bool m_selfAdvise = true );           
  virtual ~Object3DEvent(); 

protected:
  CString OutRes();

  // o3BeginDelete - Начало удаления объектов
  afx_msg VARIANT_BOOL BeginDelete( LPDISPATCH obj);
  // o3Delete - Oбъекты удалены
  afx_msg VARIANT_BOOL Delete(LPDISPATCH obj );
  // o3Excluded - Oбъект исключен/включен в расчет
  afx_msg VARIANT_BOOL Excluded(LPDISPATCH obj, VARIANT_BOOL excluded);
  // o3Hidden - Oбъект скрыт/показан
  afx_msg VARIANT_BOOL Hidden(LPDISPATCH obj, VARIANT_BOOL _hidden);
  // o3BeginPropertyChanged - Начало изменения свойств объета
  afx_msg VARIANT_BOOL BeginPropertyChanged(LPDISPATCH obj);
  // o3PropertyChanged - Изменены свойства объета
  afx_msg VARIANT_BOOL PropertyChanged(LPDISPATCH obj);
  // o3BeginPlacementChanged - Начало изменения положения объета
  afx_msg VARIANT_BOOL BeginPlacementChanged(LPDISPATCH obj);
  // o3PlacementChanged - Изменено положения объета
  afx_msg VARIANT_BOOL PlacementChanged(LPDISPATCH obj);
  // o3BeginProcess - Начало редактирования\создания объекта
  afx_msg VARIANT_BOOL BeginProcess( long pType, LPDISPATCH obj );
  // o3EndProcess - Конец редактирования\создания объекта
  afx_msg VARIANT_BOOL EndProcess( long pType );
  // o3CreateObject - Создание объекта
  afx_msg VARIANT_BOOL CreateObject( LPDISPATCH obj );
  // o3UpdateObject - Редактирование объекта
  afx_msg VARIANT_BOOL UpdateObject( LPDISPATCH obj );
  // o3BeginLoadStateChange - Начало изменения типа загрузки
  afx_msg VARIANT_BOOL BeginLoadStateChange (LPDISPATCH obj, long loadState);
  // o3LoadStateChange - Завершение изменения типа загрузки
  afx_msg VARIANT_BOOL LoadStateChange(LPDISPATCH obj, long loadState);


  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
