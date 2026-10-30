# RemoveProperty - Удалить свойство

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyMng ](ipropertymng.html) > [IPropertyMng - методы ](ipropertymng_methods.html) |  Scroll [ [ [ ](iformatlabelrules.html "К следующему разделу")](ipropertymng_methods.html "На уровень выше")](ipropertymng_getreport.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymng.html)

Синтаксис Automation:

BOOL RemoveProperty ( VARIANT libname, VARIANT val );

Синтаксис COM:

HRESULT RemoveProperty( VARIANT Libname, VARIANT Val, BOOL * ColVal );

Входные параметры:

Libname ( VARIANT) | \- полный путь к библиотеке на диске VT_BSTR, либо указатель на документ VT_DISPATCH. Текущий документ - VT_EMPTY,  
---|---  
val( VARIANT) | \- по интерфейсу свойства - VT_DISPATCH, по индексу в массиве - VT_I4, по идентификатору свойства VT_R8.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
