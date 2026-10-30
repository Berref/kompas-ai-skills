////////////////////////////////////////////////////////////////////////////////
//
// SpcObjectEvent - обрабокчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _SPCOBJECTEVENT_H
#define _SPCOBJECTEVENT_H

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
enum ksSpcObjectNotifyEnum
{
  soBeginDelete      =  1, 
  soDelete           =  2, 
  soCellDblClick     =  3, 
  soCellBeginEdit    =  4, 
  soChangeCurrent    =  5, 
  soDocumentBeginAdd =  6,
  soDocumentAdd      =  7, 
  soDocumentRemove   =  8, 
  soBeginGeomChange  =  9, 
  soGeomChange       = 10, 
  soBeginProcess    =  11, 
  soEndProcess      =  12, 
  soCreateObject    =  13, 
  soUpdateObject    =  14, 
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// SpcObjectEvent - обрабокчик событий объектов документа спецификации
//
////////////////////////////////////////////////////////////////////////////////
class SpcObjectEvent : public BaseEvent
{
public:
  SpcObjectEvent( LPUNKNOWN object, 
                  LPDISPATCH doc, 
                  long objType, 
                  bool m_selfAdvise = true );           
  virtual ~SpcObjectEvent(); 

protected:
  // soBeginDelete - Начало удаления объекта
  VARIANT_BOOL BeginDelete( long objRef);
  // soDelete - Удаление объекта  
  VARIANT_BOOL Delete( long objRef );
  // soCellDblClick - Двойной клик в ячейке 
  VARIANT_BOOL CellDblClick(long objRef, long number);
  // soCellBeginEdit - Начало редактирования в ячейке   
  VARIANT_BOOL CellBeginEdit(long objRef, long number); 
  // soChangeCurrent - Изменился текущий объект  
  VARIANT_BOOL ChangeCurrent( long objRef );
  // soDocumentBeginAdd - Начало добавления документа
  VARIANT_BOOL DocumentBeginAdd( long objRef );
  // soDocumentAdd - Добавление документа в объекте СП   
  VARIANT_BOOL DocumentAdd( long objRef, LPCTSTR docName ); 
  // soDocumentRemove - Удаление документа из объекта СП  
  VARIANT_BOOL DocumentRemove( long objRef, LPCTSTR docName );
  // soBeginGeomChange - Начало измения геометрии объекта СП
  VARIANT_BOOL BeginGeomChange( long objRef );
  // soGeomChange - Геометрия объекта СП изменилась    
  VARIANT_BOOL GeomChange( long objRef );   
  // soBeginProcess -  Начало редактирования\создания объекта  
  VARIANT_BOOL BeginProcess( long pType, long objRef );
  // soEndProcess - Конец редактирования\создания объекта 
  VARIANT_BOOL EndProcess( long pType );    
  // soCreateObject - Создание объекта 
  VARIANT_BOOL CreateObject( long objRef );  
  // soUpdateObject - Редактирование объекта    
  VARIANT_BOOL UpdateObject( long objRef );   
  //soBeginCopy - Начало копирования объекта
  VARIANT_BOOL BeginCopy(long objRef);
  // soCopy - Копирование объекта
  VARIANT_BOOL Copy(long objRef);

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
