// SelectMngEvent.h : header file
//
#ifndef _SPCOBJECTEVENT_H
#define _SPCOBJECTEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


////////////////////////////////////////////////////////////////////////////////
//
// SpcObjEvent  - обработчик событий 
//
////////////////////////////////////////////////////////////////////////////////
class SpcObjectEvent : public BaseEvent
{
//  CString libName;

// Attributes
public:
	SpcObjectEvent( reference doc, reference obj );           
  virtual ~SpcObjectEvent();

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
 virtual   void      ShowEventName( LPCTSTR eventName, long obj, long number, int type, LPCTSTR docName );
 virtual   CString   EventCaption();
// Implementation

	BEGIN_INTERFACE_PART( SpcObjectNotify, ISpcObjectNotify )
		INIT_INTERFACE_PART( SpcObjectEvent, SpcObjectNotify )
      // soBeginDelete - Начало удаления объекта
      STDMETHOD_( VARIANT_BOOL, BeginDelete ) ( THIS_  long obj );
      // soDelete - Удаление объекта
      STDMETHOD_( VARIANT_BOOL, Delete ) ( THIS_ long obj );
      // soCellDblClick - Двойной клик в ячейке
      STDMETHOD_( VARIANT_BOOL, CellDblClick ) ( THIS_ long objRef, long number );
      // soCellBeginEdit - Начало редактирования в ячейке
      STDMETHOD_( VARIANT_BOOL, CellBeginEdit ) ( THIS_ long objRef, long number );
      // soChangeCurrent - Изменился текущий объект
      STDMETHOD_( VARIANT_BOOL, ChangeCurrent ) ( THIS_ long objRef );
      // soDocumentBeginAdd - Начало добавления документа
      STDMETHOD_( VARIANT_BOOL, DocumentBeginAdd ) ( THIS_ long objRef );
      // soDocumentAdd - Добавление документа в объекте СП
      STDMETHOD_( VARIANT_BOOL, DocumentAdd ) ( THIS_ long objRef, LPSTR docName );
      // soDocumentRemove - Удаление документа из объекта СП
      STDMETHOD_( VARIANT_BOOL, DocumentRemove ) ( THIS_ long objRef, LPSTR docName );
      // soBeginGeomChange - Начало измения геометрии объекта СП
      STDMETHOD_( VARIANT_BOOL, BeginGeomChange ) ( THIS_ long objRef );
      // soGeomChange - Геометрия объекта СП изменилась
      STDMETHOD_( VARIANT_BOOL, GeomChange ) ( THIS_ long objRef );
      // soBeginProcess - Начало редактирования\создания объекта
      STDMETHOD_( VARIANT_BOOL, BeginProcess ) ( THIS_ long pType, long objRef );
      // soEndProcess - Конец редактирования\создания объекта
      STDMETHOD_( VARIANT_BOOL, EndProcess ) ( THIS_ long pType );
      // soCreateObject - Создание объекта
      STDMETHOD_( VARIANT_BOOL, CreateObject ) ( THIS_ long objRef );
      // soUpdateObject - Редактирование объекта
      STDMETHOD_( VARIANT_BOOL, UpdateObject ) ( THIS_ long objRef );
      //Обрабатывается ли библиотекой событие с номером notifyType
      STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );
      //soBeginCopy - Начало копирования объекта
			STDMETHOD_(VARIANT_BOOL, BeginCopy ) ( THIS_ long objRef );
      // soCopy - Копирование объекта
			STDMETHOD_(VARIANT_BOOL, Copy ) ( THIS_ long objRef );

	END_INTERFACE_PART( SpcObjectNotify )

};

BaseEvent* NewSpcObjectEvent( reference doc, int objType );

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
