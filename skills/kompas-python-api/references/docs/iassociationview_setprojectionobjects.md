# SetProjectionObjects - Установить массив SAFEARRAY проецируемых объектов. Вставка или тела

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationviewelements.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_findfaceedges.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

BOOL SetProjectionObjects( VARIANT Objects );

Синтаксис COM:

HRESULT SetProjectionObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- cписок объектов VT_ARRAY | VT_DISPATCH.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
