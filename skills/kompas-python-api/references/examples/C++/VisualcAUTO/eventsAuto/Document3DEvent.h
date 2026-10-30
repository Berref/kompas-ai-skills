////////////////////////////////////////////////////////////////////////////////
//
// Document3DEvent  - обрабокчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOCUMENT3DEVENT_H
#define _DOCUMENT3DEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000 

/*
enum ksDocument3DNotifyEnum
{
  d3BeginRebuild            = 1, 
  d3Rebuild                 = 2, 
  d3BeginChoiceMaterial     = 3, 
  d3СhoiceMaterial          = 4, 
  d3BeginChoiceMarking      = 5, 
  d3СhoiceMarking           = 6,
  d3BeginSetPartFromFile    = 7,
  d3BeginCreatePartFromFile = 8   
};
*/    

////////////////////////////////////////////////////////////////////////////////
//
// Document3DEvent  - обрабокчик событий от 3D документа
//
////////////////////////////////////////////////////////////////////////////////
class Document3DEvent : public BaseEvent
{
public:
  Document3DEvent( LPUNKNOWN pObject, 
                   LPDISPATCH doc,
                   bool m_selfAdvise = true );           
  virtual ~Document3DEvent();

protected:
  // d3BeginRebuild - Начало перестроения модели
  afx_msg VARIANT_BOOL BeginRebuild();
  // d3Rebuild - Модель перестроена
  afx_msg VARIANT_BOOL Rebuild();
  // d3BeginChoiceMaterial - Начало выбора материала
  afx_msg VARIANT_BOOL BeginChoiceMaterial();
  // d3СhoiceMaterial - Закончен выбор материала
  afx_msg VARIANT_BOOL ChoiceMaterial( LPCTSTR material, double density );
  // d3BeginChoiceMarking - Начало выбора обозначения
  afx_msg VARIANT_BOOL BeginChoiceMarking();   
  // d3СhoiceMarking - Закончен выбор обозначения
  afx_msg VARIANT_BOOL ChoiceMarking( LPCTSTR marking ); 
  // d3BeginSetPartFromFile    - Начало установки компонента в сборку (до диалога выбора имени)
  afx_msg VARIANT_BOOL BeginSetPartFromFile();
  // d3BeginCreatePartFromFile - Начало создания компонента в сборке (до диалога выбора имени)
  afx_msg VARIANT_BOOL BeginCreatePartFromFile( BOOL part, ksEntity * plane ); 
  // d3CreateEmbodiment - Добавлено новое исполнение
  afx_msg VARIANT_BOOL CreateEmbodiment( LPCTSTR marking );
  // d3DeleteEmbodiment - Удалено исполнение
  afx_msg VARIANT_BOOL DeleteEmbodiment( LPCTSTR marking );
  // d3ChangeCurrentEmbodiment - Исполение установлено текущим
  afx_msg VARIANT_BOOL ChangeCurrentEmbodiment( LPCTSTR marking );
  // d3BeginChoiceProperty - Начало выбора свойства
  afx_msg VARIANT_BOOL BeginChoiceProperty( LPDISPATCH obj, double propID );
  // d3ChoiceProperty - Закончен выбор свойства
  afx_msg VARIANT_BOOL ChoiceProperty( LPDISPATCH obj, double propID );
  // d3BeginRollbackFeatures - Начало отката дерева модели
  afx_msg VARIANT_BOOL BeginRollbackFeatures();
  // d3RollbackFeatures - Завершение отката дерева модели
  afx_msg VARIANT_BOOL RollbackFeatures();
  // d3BedinLoadCombinationChange - Начало переключения типа загрузки
  afx_msg VARIANT_BOOL BedinLoadCombinationChange( long index );
  // d3LoadCombinationChange - Завершение переключения типа загрузки
  afx_msg VARIANT_BOOL LoadCombinationChange( long index );
  // d3BeginDeleteMaterial - Начало удаления материала
  afx_msg VARIANT_BOOL BeginDeleteMaterial();
  // d3DeleteMaterial - Материал удален
  afx_msg VARIANT_BOOL DeleteMaterial();
  // d3BeginDeleteProperty - Начало удаления значения свойства
  afx_msg VARIANT_BOOL BeginDeleteProperty(LPDISPATCH obj, double propID);
  // d3DeleteProperty - Завершение удаления свойства
  afx_msg VARIANT_BOOL DeleteProperty( LPDISPATCH obj, double propID );


  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
