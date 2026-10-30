// SelectMngEvent.h : header file
//
#ifndef _SPECIFICATIONEVENT_H
#define _SPECIFICATIONEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обработчик событий от менеджера селектирования документа
//
////////////////////////////////////////////////////////////////////////////////
class SpecificationEvent : public BaseEvent
{
//  CString libName;

// Attributes
public:
	SpecificationEvent( reference doc );           
  virtual ~SpecificationEvent();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectMngEvent)
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(SelectMngEvent)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
 virtual   LPUNKNOWN GetUnknown();
 virtual   void      ShowEventName( LPCTSTR eventName );
 virtual   CString   EventCaption();
// Implementation

	BEGIN_INTERFACE_PART( SpecificationNotify, ISpecificationNotify )
		INIT_INTERFACE_PART( SpecificationEvent, SpecificationNotify )
      // ssTuningSpcStyleBeginChange - Начало изменения настроек спецификации
      STDMETHOD_( VARIANT_BOOL, TuningSpcStyleBeginChange ) ( THIS_ LPSTR libName, long numb );
      // ssTuningSpcStyleChange - Настроейки спецификации изменились
      STDMETHOD_( VARIANT_BOOL, TuningSpcStyleChange ) ( THIS_ LPSTR libName, long numb, VARIANT_BOOL isOk );
      // ssChangeCurrentSpcDescription - Изменилось текущее описание спецификации
      STDMETHOD_( VARIANT_BOOL, ChangeCurrentSpcDescription ) ( THIS_ LPSTR libName, long numb );
      // ssSpcDescriptionAdd - Добавилось описание спецификации
      STDMETHOD_( VARIANT_BOOL, SpcDescriptionAdd ) ( THIS_ LPSTR libName, long numb );
      // ssSpcDescriptionRemove - Удалилось описание спецификации
      STDMETHOD_( VARIANT_BOOL, SpcDescriptionRemove ) ( THIS_ LPSTR libName, long numb );
      // ssSpcDescriptionBeginEdit - Начало редактирования описания спецификации
      STDMETHOD_( VARIANT_BOOL, SpcDescriptionBeginEdit ) ( THIS_ LPSTR libName, long numb );
      // ssSpcDescriptionEdit - Отредактировали описание спецификации
      STDMETHOD_( VARIANT_BOOL, SpcDescriptionEdit ) ( THIS_ LPSTR libName, long numb, VARIANT_BOOL isOk );
      // ssSynchronizationBegin - Начало синхронизации
      STDMETHOD_( VARIANT_BOOL, SynchronizationBegin ) ( THIS_ );
      // ssSynchronization - Синхронизация проведена
      STDMETHOD_( VARIANT_BOOL, Synchronization ) ( THIS_ );
      // ssBeginCalcPositions - Начало  расчета позиций
      STDMETHOD_( VARIANT_BOOL, BeginCalcPositions ) ( THIS_ );
      // ssCalcPositions - Проведен расчет позиций
      STDMETHOD_( VARIANT_BOOL, CalcPositions ) ( THIS_ );
      // ssBeginCreateObject - Начало создания объекта СП (до диалога выбора раздела )
      STDMETHOD_( VARIANT_BOOL, BeginCreateObject) ( THIS_ long typeObj);
      //Обрабатывается ли библиотекой событие с номером notifyType
      STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );
	END_INTERFACE_PART( SpecificationNotify )

};

BaseEvent* NewSpecificationEvent( reference doc );


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
