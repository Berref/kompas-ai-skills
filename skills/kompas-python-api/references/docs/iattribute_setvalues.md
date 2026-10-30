# SetValues - Установить значения всех ячеек таблицы атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_viewedit.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetValues( BSTR Password,

VARIANT Values );

Синтаксис COM:

HRESULT SetValues( BSTR Password,

VARIANT Values,

BOOL *Result );

Входные параметры:

Password | \- пароль,  
---|---  
Values | \- массив SAFEARRAY типа VT_ARRAY | VT_VARIANT значений ячеек атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить значения всех ячеек таблицы атрибута.

Подразделы:

(отсутствуют)
