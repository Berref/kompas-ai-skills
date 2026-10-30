# Scale - Масштаб вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_variable.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_objectcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: double

Синтаксис Automation:

Scale = iObject.Scale | Получить свойство ([* ](1.html))  
---|---  
iObject.Scale = Scale | Установить свойство ([* ](1.html))  
Scale = iObject.GetScale() | Получить свойство ([**](2.html))  
iObject.SetScale (Scale) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Scale (&Scale) | Получить свойство  
---|---  
iObject->put_Scale (Scale) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить масштаб вида.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
