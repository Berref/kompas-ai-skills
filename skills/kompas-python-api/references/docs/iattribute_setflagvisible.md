# SetFlagVisible - Установить значения видимости колонок в виде массива SAFEARRAY VT_ARRAY | VT_BOOL

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setkeysinfo.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setcolumnkey.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetFlagVisible( BSTR Password,

VARIANT Values );

Синтаксис COM:

HRESULT SetFlagVisible( BSTR Password,

VARIANT Values,

BOOL *Result );

Входные параметры:

Password | \- пароль,  
---|---  
Values | \- массив SAFEARRAY типа VT_ARRAY | VT_BOOL значений видимости колонок атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить значения видимости колонок атрибута.

Подразделы:

(отсутствуют)
