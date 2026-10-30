# GetProperties - Получить массив свойств

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyMng ](ipropertymng.html) > [IPropertyMng - методы ](ipropertymng_methods.html) |  Scroll [ [ [ ](ipropertymng_getreport.html "К следующему разделу")](ipropertymng_methods.html "На уровень выше")](ipropertymng_getproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymng.html)

Синтаксис Automation:

VARIANT GetProperties ( VARIANT libname );

Синтаксис COM:

HRESULT GetProperties( VARIANT Libname, VARIANT * Res );

Входные параметры:

Libname ( VARIANT) | \- полный путь к библиотеке на диске VT_BSTR, либо указатель на документ VT_DISPATCH. Текущий документ - VT_EMPTY.  
---|---  
  
Возвращаемое значение:

| \- Массив библиотек VARIANT типа VT_ARRAY | VT_DISPATCH.  
---|---  
  
Примечание:

Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
