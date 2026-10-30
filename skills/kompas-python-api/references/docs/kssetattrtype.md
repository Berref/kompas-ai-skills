# ksSetAttrType - Изменить тип атрибута в библиотеке типов атрибутов

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](kssetattrvalue.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](kssetattrroww.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssetattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksSetAttrType](ksattributeobject_kssetattrtype.html).

Синтаксис:

double ksSetAttrType (double attrID,

char * libname,

ksAttributeType * attrType,

char * password);

Входные параметры:

attrID | \- уникальный номер типа атрибута,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута изменяется в текущем документе,  
attrType | \- [Указатель на структуру параметров типа атрибута](structksattributetype.html),  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html), которая может быть получена с помощью функции [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html), или с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
