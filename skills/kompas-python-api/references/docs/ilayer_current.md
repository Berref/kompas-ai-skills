# Current - Состояние слоя - текущий

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс ILayer ](ilayer.html) > [ILayer - свойства ](ilayer_props.html) |  Scroll [ [ [ ](ilayer_name.html "К следующему разделу")](ilayer_props.html "На уровень выше")](ilayer_comment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayer.html)

Тип данных: BOOL

Синтаксис Automation:

Current = iObject.Current | Получить свойство ([* ](1.html))  
---|---  
iObject.Current = Current | Установить свойство ([* ](1.html))  
Current = iObject.GetCurrent() | Получить свойство ([**](2.html))  
iObject.SetCurrent (Current) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Current (&Current) | Получить свойство  
---|---  
iObject->put_Current (Current) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить состояние слоя - текущий.

2\. Установить свойство текущий можно только равным TRUE. Новый слой всегда создается текущим.

3\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
