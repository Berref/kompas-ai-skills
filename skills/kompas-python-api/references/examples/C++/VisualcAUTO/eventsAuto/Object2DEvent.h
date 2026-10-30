////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обрабокчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _OBJECT2DEVENT_H
#define _OBJECT2DEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
enum ksObject2DNotifyEnum
{
   koChangeActive  = 1,
  koBeginDelete  = 2,
  koDelete  = 3,
  koBeginMove  = 4,
  koMove  = 5,
  koBeginRotate  = 6,
  koRotate  = 7,
  koBeginScale  = 8,
  koScale  = 9,
  koBeginTransform  = 10,
  koTransform  = 11,
  koBeginCopy  = 12,
  koCopy  = 13,
  koBeginSymmetry  = 14,
  koSymmetry  = 15,
  koBeginProcess  = 16,
  koEndProcess  = 17,
  koCreateObject  = 18,
  koUpdateObject  = 19
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обрабокчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////
class Object2DEvent : public BaseEvent
{
  ksObject2DNotifyResultPtr m_res;

public:
  Object2DEvent( LPUNKNOWN object, 
                 LPDISPATCH doc, 
                 long objType,
                 ksObject2DNotifyResultPtr res, 
                 bool m_selfAdvise = true );           
  virtual ~Object2DEvent(); 

protected:
  CString OutRes();

  // koChangeActive    - Переключение вида в текущий
  afx_msg VARIANT_BOOL ChangeActive( long viewRef );
  // koBeginDelete     - Начало удаления объекта
  afx_msg VARIANT_BOOL BeginDelete( long layerRef );
  // koDelete          - Удаление объектов
  afx_msg VARIANT_BOOL Delete( long obgsRef );
  // koBeginMove       - Начало смещения объекта
  afx_msg VARIANT_BOOL BeginMove( long objRef );
  // koMove            - Объект смещен
  afx_msg VARIANT_BOOL Move( long objRef );
  // koBeginRotate     - Поворот объекта
  afx_msg VARIANT_BOOL BeginRotate( long objRef );
  // koRotate          - Поворот объекта
  afx_msg VARIANT_BOOL Rotate( long objRef );
  // koBeginScale      - Маштабирование объекта
  afx_msg VARIANT_BOOL BeginScale( long objRef );
  // koScale           - Маштабирование объекта
  afx_msg VARIANT_BOOL Scale( long objRef );
  // koBeginTransform  - Трансформация объекта
  afx_msg VARIANT_BOOL BeginTransform( long objRef );
  // koTransform       - Трансформация объекта
  afx_msg VARIANT_BOOL Transform( long objRef );
  // koBeginCopy       - Копирование объекта
  afx_msg VARIANT_BOOL BeginCopy( long objRef );
  // koCopy            - Копирование объекта
  afx_msg VARIANT_BOOL Copy( long objRef );
  // koBeginSymmetry   - Симметрия объекта
  afx_msg VARIANT_BOOL BeginSymmetry( long objRef );
  // koSymmetry        - Симметрия объекта
  afx_msg VARIANT_BOOL Symmetry( long objRef );
  // koBeginProcess    - Начало редактирования\создания объекта
  afx_msg VARIANT_BOOL BeginProcess( long pType, long objRef );
  // koEndProcess      - Конец редактирования\создания объекта
  afx_msg VARIANT_BOOL EndProcess( long objRef );
  // koCreate          - Создание объекта
  afx_msg VARIANT_BOOL CreateObject( long objRef );
  // koUpdateObject    - Редактирование объекта
  afx_msg VARIANT_BOOL UpdateObject( long objRef );
  // koBeginDestroyObject - Начало разрушения объекта  
  afx_msg VARIANT_BOOL BeginDestroyObject( long obj );
  // koDestroyObject - разрушение объекта  
  afx_msg VARIANT_BOOL DestroyObject( long obj );
  // koBeginPropertyChanged - Начало изменения свойств объекта
  afx_msg VARIANT_BOOL BeginPropertyChanged( long objRef );
  // koPropertyChanged - Изменены свойства объета
  afx_msg VARIANT_BOOL PropertyChanged(long objRef);
 
  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
