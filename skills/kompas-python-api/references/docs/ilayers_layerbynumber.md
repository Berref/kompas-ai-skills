# LayerByNumber - Слой, заданный по номеру

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс ILayers ](ilayers.html) > [ILayers - свойства ](ilayers_props.html) |  Scroll [ [ [ ](ilayers_methods.html "К следующему разделу")](ilayers_props.html "На уровень выше")](ilayers_layer.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayers.html)

Тип данных: указатель на интерфейс слоя [ILayer](ilayer.html)

Синтаксис Automation:

Layer = iObject.LayerByNumber (Number) | Получить свойство ([* ](1.html))  
---|---  
Layer = iObject.GetLayerByNumber (Number) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LayerByNumber (Number, &Layer) | Получить свойство  
---|---  
  
Входные параметры:

number | \- номер слоя; тип long.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
