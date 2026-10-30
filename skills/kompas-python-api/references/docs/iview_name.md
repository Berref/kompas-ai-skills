# Name - Имя вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_number.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_layers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Name = iObject.Name | Получить свойство ([* ](1.html))  
---|---  
iObject.Name = Name | Установить свойство ([* ](1.html))  
Name = iObject.GetName() | Получить свойство ([**](2.html))  
iObject.SetName (Name) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Name (&Name) | Получить свойство  
---|---  
iObject->put_Name (Name) | Установить свойство  
  
Примечание:

1\. Для нового вида, полученного методом [IViews::Add](iviews_add.html), имя должно быть обязательно установлено до вызова метода [IDrawingObject::Update](idrawingobject_update.html).

2\. Свойство вступает в силу после вызова метода IDrawingObject::Update.

Подразделы:

(отсутствуют)
