# Angle - Угол поворота вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_background.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: double

Синтаксис Automation:

Angle = iObject.Angle | Получить свойство ([* ](1.html))  
---|---  
iObject.Angle = Angle | Установить свойство ([* ](1.html))  
iObject.Angle = Angle | Получить свойство ([**](2.html))  
iObject.SetAngle (Angle) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Angle (&Angle) | Получить свойство  
---|---  
iObject->put_Angle (Angle) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить угол поворота вида.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
