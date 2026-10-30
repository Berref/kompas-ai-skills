# Delete - Удалить узел

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNode ](imarknode.html) > [IMarkNode - методы ](imarknode_methods.html) |  Scroll [ [ [ ](imarknode_getinsertionpoints.html "К следующему разделу")](imarknode_methods.html "На уровень выше")](imarknode_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknode.html)

Синтаксис Automation:

BOOL Delete();

Синтаксис COM:

HRESULT Delete( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет удалить дополнительные узлы для марок.

2\. Из объекта узлы удалятся после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
