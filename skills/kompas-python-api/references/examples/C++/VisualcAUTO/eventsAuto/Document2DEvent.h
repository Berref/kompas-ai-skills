////////////////////////////////////////////////////////////////////////////////
//
// Document2DEvent  - обрабокчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _DOCUMENT2DEVENT_H
#define _DOCUMENT2DEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000 

/*
enum ksDocument2DNotifyEnum
{
  d2BeginRebuild        = 1, 
  d2Rebuild             = 2, 
  d2BeginChoiceMaterial = 3, 
  d2СhoiceMaterial      = 4,  
  d2BeginInsertFragment = 5
};
*/    

////////////////////////////////////////////////////////////////////////////////
//
// Document2DEvent  - обрабокчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////
class Document2DEvent : public BaseEvent
{
public:
  Document2DEvent( LPUNKNOWN pObject, 
                   LPDISPATCH doc,
                   bool m_selfAdvise = true );           
  virtual ~Document2DEvent();

protected:
  // d3BeginRebuild - Начало перестроения модели
  afx_msg VARIANT_BOOL BeginRebuild();
  // d3Rebuild - Модель перестроена
  afx_msg VARIANT_BOOL Rebuild();
  // d3BeginChoiceMaterial - Начало выбора материала
  afx_msg VARIANT_BOOL BeginChoiceMaterial();
  // d3СhoiceMaterial - Закончен выбор материала
  afx_msg VARIANT_BOOL ChoiceMaterial( LPCTSTR material, double density );
  // d2BeginInsertFragment - Начало вставки фрагмента (до диалога выбора имени)
  afx_msg VARIANT_BOOL BeginInsertFragment();
  // d2LocalFragmentEdit - Редактирование локального фрагмента
  afx_msg VARIANT_BOOL LocalFragmentEdit(LPDISPATCH pDoc, VARIANT_BOOL newFrw);
  // d2BeginChoiceProperty - Начало выбора свойства
  afx_msg VARIANT_BOOL BeginChoiceProperty( long objRef, double propID );
  // d2ChoiceProperty - Закончен выбор свойства
  afx_msg VARIANT_BOOL ChoiceProperty( long objRef, double propID );
  // d2BeginDeleteProperty - Начало удаления значения свойства
  afx_msg VARIANT_BOOL BeginDeleteProperty( long objRef, double propID );
  // d2DeleteProperty - Завершение удаления свойства
  afx_msg VARIANT_BOOL DeleteProperty( long objRef, double propID );

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
