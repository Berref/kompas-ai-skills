// SelectMngEvent.h : header file
//
#ifndef _SELECTMNGEVENT_H
#define _SELECTMNGEVENT_H

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
class SelectMngEvent : public BaseEvent
{
//  CString libName;
  int docType;
// Attributes
public:
	SelectMngEvent( reference doc );           
  virtual ~SelectMngEvent();

// Operations
public:
  void      ShowEventName( LPCTSTR eventName, VARIANT & obj );
	virtual   CString   EventCaption();
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
// Implementation

	BEGIN_INTERFACE_PART( SelectionMngNotify, ISelectionMngNotify )
		INIT_INTERFACE_PART( SelectionEvent, SelectionMngNotify)
    // ksmSelect      - Объект селектирован
    STDMETHOD_(VARIANT_BOOL, Select)( THIS_ VARIANT obj );
  
    // ksmUnselect    - Объект расселектирован
    STDMETHOD_(VARIANT_BOOL, Unselect)( THIS_ VARIANT obj );

    // ksmUnselectAll - Все объекты расселектированы
    STDMETHOD_(VARIANT_BOOL, UnselectAll)( THIS_ );

    //Обрабатывается ли библиотекой событие с номером notifyType
    STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );

	END_INTERFACE_PART( SelectionMngNotify )

};

BaseEvent* NewSelectMngEvent( reference doc );


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
