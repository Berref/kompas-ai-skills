# GetAttrType - Получить тип атрибута из заданной библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttrTypeMng ](iattrtypemng.html) > [IAttrTypeMng - методы ](iattrtypemng_methods.html) |  Scroll [ [ [ ](iattrtypemng_getattrtypes.html "К следующему разделу")](iattrtypemng_methods.html "На уровень выше")](iattrtypemng_createattrtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattrtypemng.html)

Синтаксис Automation:

LPDISPATCH GetAttrType( double AttrID,

VARIANT Libname );

Синтаксис COM:

HRESULT GetAttrType( double AttrID,

VARIANT Libname,

IAttributeType ** Result );

Входные параметры:

AttrID | \- уникальный номер типа атрибута,  
---|---  
Libname | \- имя библиотеки типов атрибутов.  
  
Возвращаемое значение:

| \- указатель на интерфейс типа атрибута [IAttributeType](iattributetype.html).  
---|---  
  
Примечание:

Метод позволяет получить тип атрибута из библиотеки Libname.

Подразделы:

(отсутствуют)
