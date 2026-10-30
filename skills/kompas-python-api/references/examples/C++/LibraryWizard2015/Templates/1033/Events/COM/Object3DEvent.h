////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обработчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _OBJECT3DEVENT_H
#define _OBJECT3DEVENT_H

#include "CBaseEvent.h"


////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обработчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////
class Obj3DEvent : public CBaseEvent
{
public:
           Obj3DEvent( LPUNKNOWN iContainer = NULL, long objType = 0, LPUNKNOWN iObj = NULL, reference doc = 0 );           
  virtual ~Obj3DEvent();

protected:
  virtual  LPUNKNOWN GetUnknown();

  BEGIN_INTERFACE_PART(Object3DNotify, IObject3DNotify)
		INIT_INTERFACE_PART(Obj3DEvent, Object3DNotify)
    // Начало удаления объекта
    STDMETHOD_(VARIANT_BOOL, BeginDelete)(THIS_ LPUNKNOWN obj);
    // Oбъекты удалены
    STDMETHOD_(VARIANT_BOOL, Delete)(THIS_ LPUNKNOWN obj);
    // Oбъект исключен/включен в расчет
    STDMETHOD_(VARIANT_BOOL, excluded)(THIS_ LPUNKNOWN obj, VARIANT_BOOL excluded);
    // Oбъект скрыт/показан
    STDMETHOD_(VARIANT_BOOL, Hidden)(THIS_ LPUNKNOWN obj, VARIANT_BOOL _hidden);
    // Начало изменения свойств объекта
    STDMETHOD_(VARIANT_BOOL, BeginPropertyChanged)(THIS_ LPUNKNOWN obj);
    // Изменены свойства объекта
    STDMETHOD_(VARIANT_BOOL, PropertyChanged)(THIS_ LPUNKNOWN obj);
    // Начало изменения положения объекта
    STDMETHOD_(VARIANT_BOOL, BeginPlacementChanged)(THIS_ LPUNKNOWN obj);
    // Изменено положение объекта
    STDMETHOD_(VARIANT_BOOL, PlacementChanged)(THIS_ LPUNKNOWN obj);
    // Начало редактирования\создания объекта, false - запрещает процесс.
    STDMETHOD_(VARIANT_BOOL, BeginProcess)( THIS_ long pType, LPUNKNOWN obj );
    // Конец редактирования\создания объекта
    STDMETHOD_(VARIANT_BOOL, EndProcess)( THIS_ long pType );
    // Создание объекта.
    STDMETHOD_(VARIANT_BOOL, CreateObject)( THIS_ LPUNKNOWN obj );
    // Редактирование объекта.
    STDMETHOD_(VARIANT_BOOL, UpdateObject)( THIS_ LPUNKNOWN obj );
    //Обрабатывается ли библиотекой событие с номером notifyType
    STDMETHOD_(VARIANT_BOOL, IsNotifyProcess)( THIS_ int notifyType );

	END_INTERFACE_PART(Object3DNotify)
	
};

CBaseEvent * NewObj3DEvent( reference doc, int objType, LPUNKNOWN iObj = NULL );

/////////////////////////////////////////////////////////////////////////////

#endif /*_OBJECT3DEVENT_H*/
