# Current - Состояние вида - текущий

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_layers.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_comment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

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

1\. Позволяет узнать, является ли вид текущим или сделать его текущим.

2\. Установить свойство "текущий" можно только равным TRUE.

3\. Новый вид всегда создается текущим.

4\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
