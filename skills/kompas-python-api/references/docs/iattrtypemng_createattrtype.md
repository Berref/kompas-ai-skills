# CreateAttrType - Создать тип атрибута в заданной библиотеке

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttrTypeMng ](iattrtypemng.html) > [IAttrTypeMng - методы ](iattrtypemng_methods.html) |  Scroll [ [ [ ](iattrtypemng_getattrtype.html "К следующему разделу")](iattrtypemng_methods.html "На уровень выше")](iattrtypemng_choiceattrtypes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattrtypemng.html)

Синтаксис Automation:

LPDISPATCH CreateAttrType( VARIANT Libname );

Синтаксис COM:

HRESULT CreateAttrType( VARIANT Libname,

IAttributeType ** Result );

Входные параметры:

Libname | \- имя библиотеки типов атрибутов.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс типа атрибута [IAttributeType](iattributetype.html).  
---|---  
  
Примечание:

Метод позволяет создать тип атрибута в библиотеке Libname.

Подразделы:

(отсутствуют)
