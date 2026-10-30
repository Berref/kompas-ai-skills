# DeleteAttrType - Удалить описание атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrcolumninfo.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](deleteattr.html "К предыдущему разделу")  
---|---  
  
[Пример...](deleteattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksDeleteAttrType](ksattributeobject_ksdeleteattrtype.html).

Синтаксис:

int DeleteAttrType (double attrID, char *libname, char * password);

Входные параметры:

attrID | \- уникальный номер типа,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута удаляется из текущего документа,  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html), которая может быть получена с помощью функции [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html), или с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
