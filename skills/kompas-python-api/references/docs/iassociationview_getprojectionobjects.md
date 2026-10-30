# GetProjectionObjects - Получить массив SAFEARRAY проецируемых объектов. Вставка или тела

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_findface.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_restorestyles.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

VARIANT GetProjectionObjects( IKompasDocument3D * Document3D );

Синтаксис COM:

HRESULT GetProjectionObjects( IKompasDocument3D * Document3D, VARIANT * Result );

Входные параметры:

Document3D | \- документ [IKompasDocument3D](ikompasdocument3d.html).  
---|---  
  
Возвращаемое значение:

| \- Список объектов в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
