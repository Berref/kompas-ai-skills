# Color - Цвет вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_comment.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_background.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: long

Синтаксис Automation:

Color = iObject.Color | Получить свойство ([* ](1.html))  
---|---  
iObject.Color = Color | Установить свойство ([* ](1.html))  
Color = iObject.GetColor() | Получить свойство ([**](2.html))  
iObject.SetColor( Color ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Color( &Color ) | Получить свойство  
---|---  
iObject->put_Color( Color ) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить цвет вида.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
