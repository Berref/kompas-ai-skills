# Name - Имя слоя

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс ILayer ](ilayer.html) > [ILayer - свойства ](ilayer_props.html) |  Scroll [ [ [ ](ilayer_objectcount.html "К следующему разделу")](ilayer_props.html "На уровень выше")](ilayer_current.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayer.html)

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

1\. Позволяет получить и установить имя слоя.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
