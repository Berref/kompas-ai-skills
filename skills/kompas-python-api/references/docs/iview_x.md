# X - Координата привязки по X

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_y.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_visible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: double

Синтаксис Automation:

X = iObject.X | Получить свойство ([* ](1.html))  
---|---  
iObject.X = X | Установить свойство ([* ](1.html))  
X = iObject.GetX() | Получить свойство ([**](2.html))  
iObject.SetX (X) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_X (&X) | Получить свойство  
---|---  
iObject->put_X (X) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить координату привязки вида по оси X.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
