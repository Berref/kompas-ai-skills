# Y - Координата привязки по Y

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iassociationview.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_x.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: double

Синтаксис Automation:

Y = iObject.Y | Получить свойство ([* ](1.html))  
---|---  
iObject.Y = Y | Установить свойство ([* ](1.html))  
Y = iObject.GetY() | Получить свойство ([**](2.html))  
iObject.SetY (Y) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Y (&Y) | Получить свойство  
---|---  
iObject->put_Y (Y) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить координату привязки вида по оси Y.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
