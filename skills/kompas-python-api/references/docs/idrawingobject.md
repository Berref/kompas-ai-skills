# Интерфейс IDrawingObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) |  Scroll [ [ [ ](bb2327204.html "К следующему разделу")](view_layers.html "На уровень выше")](iviews_addstandartviews.html "К предыдущему разделу")  
---|---  
  
Базовый интерфейс для всех графических объектов.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IDrawingObject1](idrawingobject1.html)

Примечание:

1\. Данный интерфейс является базовым для графических объектов.

2\. Интерфейс можно получить из коллекции графических объектов [IDrawingObjects](idrawingobjects.html) с помощью свойства [IDrawingObjects::Item](idrawingobjects_item.html).

3\. Имея интерфейс IDrawingObject, можно подписаться на события [ksDrawingObjectNotify](ksdrawingobjectnotify.html).

4\. Данный интерфейс может быть получен с помощью метода IUnknown QueryInterface от интерфейса конкретного объекта, например, от интерфейса вида [IView](iview.html), слоя [ILayer](ilayer.html).

5\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& IID, void** pif) ](recomendation.html)у данного интерфейса можно получить дополнительный интерфейс для графических объектов [IDrawingObject1](idrawingobject1.html).

Подразделы:

[Интерфейс событий для объектов графического документа](bb2327204.html)

[IDrawingObject - свойства ](idrawingobject_props.html)

[IDrawingObject - методы ](idrawingobject_methods.html)
