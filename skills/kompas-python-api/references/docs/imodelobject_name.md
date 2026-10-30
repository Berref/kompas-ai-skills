# Name - Имя элемента трехмерной модели

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject ](imodelobject.html) > [IModelObject - свойства ](imodelobject_props.html) |  Scroll [ [ [ ](imodelobject_owner.html "К следующему разделу")](imodelobject_props.html "На уровень выше")](imodelobject_modelobjecttype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject.html)

Тип данных: строка

Синтаксис Automation:

Name = iObject.Name | Получить свойство([* ](1.html))  
---|---  
iObject.Name = Name | Установить свойство ([* ](1.html))  
Name = iObject.GetName( ) | Получить свойство ([**](2.html))  
iObject.SetName( Name ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Name( &Name ) | Получить свойство  
---|---  
iObject->put_Name( Name ) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить имя трехмерной модели.

2\. Свойство вступает в силу после вызова метода [IModelObject::Update](imodelobject_update.html).

3\. Не все объекты имеют имя, например, ребра.

Подразделы:

(отсутствуют)
