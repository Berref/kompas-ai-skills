# Интерфейс IViews

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) |  Scroll [ [ [ ](iviews_props.html "К следующему разделу")](idrawingobjects_props.html "На уровень выше")](ilayers_detach.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции видов графического документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[IDrawingObjects](idrawingobjects.html)

[IViews](iviews.html)

Описание:

Типы видов описаны в перечислении [LtViewType](ltviewtype.html).

В документе типа Фрагмент есть только один системный вид.

В документе типа Чертеж обязательно есть системный вид (только один) и могут быть до 254 видов любого типа из перечисления LtViewType, кроме системного.

Примечание:

Данный интерфейс можно получить от интерфейса менеджера видов и слоев [IViewsAndLayersManager](iviewsandlayersmanager.html) с помощью свойства [IViewsAndLayersManager::Views](iviewsandlayersmanager_views.html).

Подразделы:

[IViews - свойства ](iviews_props.html)

[IViews - методы ](iviews_methods.html)
