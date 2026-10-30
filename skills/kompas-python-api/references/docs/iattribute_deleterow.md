# DeleteRow - Удалить строку табличного атрибута неопределенной длины

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_getkeysinfo.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL DeleteRow( BSTR Password,

long RowNumb );

Синтаксис COM:

HRESULT DeleteRow( BSTR Password,

long RowNumb,

BOOL * Result );

Входные параметры:

Password | \- пароль,  
---|---  
RowNumb | \- номер удаляемой строки.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить строку из таблицы атрибута.

Подразделы:

(отсутствуют)
