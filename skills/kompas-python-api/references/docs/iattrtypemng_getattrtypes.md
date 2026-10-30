# GetAttrTypes - Возвращает массив типов атрибутов, находящихся в заданной библиотеке типов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttrTypeMng ](iattrtypemng.html) > [IAttrTypeMng - методы ](iattrtypemng_methods.html) |  Scroll [ [ [ ](iattribute.html "К следующему разделу")](iattrtypemng_methods.html "На уровень выше")](iattrtypemng_getattrtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattrtypemng.html)

Синтаксис Automation:

VARIANT GetAttrTypes( VARIANT Libname );

Синтаксис COM:

HRESULT GetAttrTypes( VARIANT Libname,

VARIANT * Result );

Входные параметры:

Libname | \- имя библиотеки типов атрибутов.  
---|---  
  
Возвращаемое значение:

| \- массив SAFEARRAY типа VT_ARRAY | VT_DISPATCH указателей на интерфейсы типов атрибутов, находящихся в заданной библиотеке.  
---|---  
  
Примечание:

Метод позволяет получить массив типов атрибутов из заданной библиотеки. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
