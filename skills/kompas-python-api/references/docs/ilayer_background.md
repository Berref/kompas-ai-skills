# Background - Состояние слоя - фоновый

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс ILayer ](ilayer.html) > [ILayer - свойства ](ilayer_props.html) |  Scroll [ [ [ ](ilayer_color.html "К следующему разделу")](ilayer_props.html "На уровень выше")](ilayer_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayer.html)

Тип данных: BOOL

Синтаксис Automation:

Background = iObject.Background | Получить свойство ([* ](1.html))  
---|---  
iObject.Background = Background | Установить свойство ([* ](1.html))  
Background = iObject.GetBackground() | Получить свойство ([**](2.html))  
iObject.SetBackground (Background) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Background (&Background) | Получить свойство  
---|---  
iObject->put_Background (Background) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить свойство слоя - фоновый.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
