# BlockNumberByIndex - Номер блока

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_columns.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_attacheddocuments.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: long

Синтаксис Automation:

BlockNumber = iObject.BlockNumberByIndex (index) | Получить свойство ([* ](1.html))  
---|---  
BlockNumber = iObject.GetBlockNumberByIndex (index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BlockNumberByIndex (index, &BlockNumber) | Получить свойство  
---|---  
  
Входные параметры:

index | \- индекс объекта в общем массиве объектов спецификации.  
---|---  
  
Примечание:

1\. Свойство позволяет получить номер блока объекта спецификации.

2\. Один и тот же базовый объект спецификации может быть вставлен в спецификации несколько раз в нескольких блоках.

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
