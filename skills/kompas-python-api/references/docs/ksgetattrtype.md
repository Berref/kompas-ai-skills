# ksGetAttrType - Получить описание типа табличного атрибута из библиотеки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetattrtypeinfo.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetattrroww.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrType](ksattributeobject_ksgetattrtype.html).

Синтаксис:

int ksGetAttrType (double attrID, char * libname, ksAttributeType * attrType);

Входной параметр:

attrID | \- уникальный номер типа атрибута,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута из текущего документа.  
  
Выходной параметр:

attrType | \- указатель на [структуру типа атрибута AttributeType...](structksattributetype.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html), которая может быть получена с помощью функции [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html), или с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
