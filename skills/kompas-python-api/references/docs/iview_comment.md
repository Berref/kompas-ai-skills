# Comment - Примечание

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_current.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_color.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: BSTR

Синтаксис Automation:

Comment = iObject.Comment | Получить свойство ([* ](1.html))  
---|---  
iObject.Comment = Comment | Установить свойство ([* ](1.html))  
Comment = iObject.GetComment() | Получить свойство ([**](2.html))  
iObject.SetComment (Comment) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Comment (&Comment) | Получить свойство  
---|---  
iObject->put_Comment (Comment) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить примечание.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
