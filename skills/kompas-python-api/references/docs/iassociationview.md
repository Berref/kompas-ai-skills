# Интерфейс IAssociationView

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iassociationview_props.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_y.html "К предыдущему разделу")  
---|---  
  
Интерфейс ассоциативного вида графического документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IView](iview.html)

[IAssociationView](iassociationview.html)

[IHatchParam](ihatchparam.html)

[IAssociationViewElements](iassociationviewelements.html)

Описание:

Типы видов описаны в перечислении [LtViewType](ltviewtype.html).

Примечание:

1\. Данный интерфейс можно получить следующими способами:

•через коллекцию видов [IViews](iviews.html),

•с помощью метода IUnknown QueryInterface от интерфейса [IView](iview.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить дополнительные интерфейсы:

•[IHatchParam](ihatchparam.html)

•[IAssociationViewElements](iassociationviewelements.html).

Подразделы:

[IAssociationView - свойства ](iassociationview_props.html)

[IAssociationView - методы ](iassociationview_methods.html)
