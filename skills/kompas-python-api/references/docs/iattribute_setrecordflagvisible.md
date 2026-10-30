# SetRecordFlagVisible - Установить значения видимости колонок внутри записи в виде массива SAFEARRAY VT_ARRAY | VT_BOOL

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setvalue.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setpassword.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetRecordFlagVisible( BSTR Password,

long ColumnNumb,

VARIANT Values );

Синтаксис COM:

HRESULT SetRecordFlagVisible( BSTR Password,

long ColumnNumb,

VARIANT Values,

BOOL * Result );

Входные параметры:

Password | \- пароль,  
---|---  
ColumnNumb | \- номер колонки записи,  
Values | \- массив SAFEARRAY типа VT_ARRAY | VT_BOOL значений видимости колонок записи.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить значения видимости колонок записи.

Подразделы:

(отсутствуют)
