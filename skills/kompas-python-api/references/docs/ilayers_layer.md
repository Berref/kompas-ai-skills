# Layer - Слой, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс ILayers ](ilayers.html) > [ILayers - свойства ](ilayers_props.html) |  Scroll [ [ [ ](ilayers_layerbynumber.html "К следующему разделу")](ilayers_props.html "На уровень выше")](ilayers_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayers.html)

Тип данных: указатель на интерфейс слоя [ILayer](ilayer.html)

Синтаксис Automation:

Layer = iObject.Layer (Index) | Получить свойство ([* ](1.html))  
---|---  
Layer = iObject.GetLayer (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Layer (Index, &Layer) | Получить свойство  
---|---  
  
Входные параметры:

index | \- индекс слоя в коллекции; тип VARIANT.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс элемента в массиве, ссылка на слой, имя слоя.

Подразделы:

(отсутствуют)
