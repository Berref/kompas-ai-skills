# Background - Состояние вида - фоновый

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_color.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

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
