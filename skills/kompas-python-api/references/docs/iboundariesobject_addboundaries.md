# AddBoundaries - Добавить объекты в границу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IBoundariesObject ](iboundariesobject.html) > [IBoundariesObject - методы ](iboundariesobject_methods.html) |  Scroll [ [ [ ](iboundariesobject_clear.html "К следующему разделу")](iboundariesobject_methods.html "На уровень выше")](iboundariesobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iboundariesobject.html)

Синтаксис Automation:

BOOL AddBoundaries( VARIANT Objects,

BOOL DeleteSource );

Синтаксис COM:

HRESULT AddBoundaries(VARIANT Objects,

BOOL DeleteSource,

BOOL * Result );

Входные параметры:

Objects | \- массив SAFEARRAY | VT_DISPATCH объектов, добавляемых в границу,  
---|---  
DeleteSource | \- TRUE - удалить исходные объекты, \- FALSE - копировать исходные объекты.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить объекты в границу.

Подразделы:

(отсутствуют)
