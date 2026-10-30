# Delete - Удалить объект или объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_draw.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_createattr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL Delete( VARIANT Objects );

Синтаксис COM:

HRESULT Delete( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов, которые нужно удалить (VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить объект или объекты.

Подразделы:

(отсутствуют)
