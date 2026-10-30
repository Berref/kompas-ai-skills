# SetColumnKey - Установить ключи колонок

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setflagvisible.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_getkeysinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetColumnKey( BSTR Password,

VARIANT Keys );

Синтаксис COM:

HRESULT SetColumnKey( BSTR Password,

VARIANT Keys,

BOOL *Result );

Входные параметры:

Password | \- пароль,  
---|---  
Keys | \- массив SAFEARRAY типа VT_ARRAY | VT_I4 значений ключей колонок атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить ключи колонок атрибута.

Подразделы:

(отсутствуют)
