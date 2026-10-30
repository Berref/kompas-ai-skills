# SetValue - Установить значение ячейки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setvalues.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setrecordflagvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetValue( BSTR Password,

long RowNumb,

long ColumnNumb,

VARIANT Value );

Синтаксис COM:

HRESULT SetValue( BSTR Password,

long RowNumb,

long ColumnNumb,

VARIANT Value,

BOOL* Result );

Входные параметры:

Password | \- пароль,  
---|---  
RowNumb | \- номер строки атрибута,  
ColumnNumb | \- номер столбца атрибута,  
Value | \- значение ячейки атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить значение ячейки атрибута.

Подразделы:

(отсутствуют)
