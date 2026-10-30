# Clear - Очистить коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNodes ](imarknodes.html) > [IMarkNodes - методы ](imarknodes_methods.html) |  Scroll [ [ [ ](ibuildingaxis.html "К следующему разделу")](imarknodes_methods.html "На уровень выше")](imarknodes_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknodes.html)

Синтаксис Automation:

BOOL Clear();

Синтаксис COM:

HRESULT Clear( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить дополнительные узлы для марок, при этом узлы удаляются из коллекции. Из объекта узлы будут удалены после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
