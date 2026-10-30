# AddRow - Добавить строку к табличному атрибуту неопределенной длины

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_delete.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL AddRow( BSTR Password,

long RowNumb );

Синтаксис COM:

HRESULT AddRow( BSTR Password,

long RowNumb,

BOOL * Result );

Входные параметры:

Password | \- пароль,  
---|---  
RowNumb | \- номер строки, после которой нужно вставить строку.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить строку в таблицу атрибута.

Подразделы:

(отсутствуют)
