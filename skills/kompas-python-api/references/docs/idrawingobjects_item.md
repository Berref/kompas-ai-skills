# Item - Объект, заданный по ссылке или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) |  Scroll [ [ [ ](ilayers.html "К следующему разделу")](idrawingobjects_props.html "На уровень выше")](idrawingobjects_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobjects.html)

Тип данных: указатель на интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

Item = iObject.Item | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (&Item) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- индекс объекта в коллекции, тип VARIANT.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс элемента в массиве, reference объекта.

Подразделы:

(отсутствуют)
