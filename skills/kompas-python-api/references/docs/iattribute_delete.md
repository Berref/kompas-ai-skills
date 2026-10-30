# Delete - Удалить атрибут

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_deleterow.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_addrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL Delete( BSTR Password,

VARIANT Objects );

Синтаксис COM:

HRESULT Delete( BSTR Password,

VARIANT Objects

BOOL * Result );

Входные параметры:

Password | \- пароль,  
---|---  
Objects | \- массив SAFEARRAY типа VT_ARRAY | VT_DISPATCH объектов, у которых надо удалить атрибут.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить атрибут у объектов.

Подразделы:

(отсутствуют)
