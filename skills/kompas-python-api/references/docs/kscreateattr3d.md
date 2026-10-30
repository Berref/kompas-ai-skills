# ksCreateAttr3D - Cоздать атрибут по номеру типа атрибута из библиотеки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](kscreateattr3dex.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](kscreateattrtype.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksCreateAttr3D](ksattributeobject_kscreateattr3d.html).

Синтаксис:

LPATTRIBUTE3D_IFUNC ksCreateAttr3D (LPUNKNOWN pObj, ksAttribute * attr, double attrID, char *libname);

Входные параметры:

[pObj](pobj.html) | \- указатель на объект для которого создается атрибут,  
---|---  
attr | \- указатель на структуру параметров атрибута [ksAttribute](structksattribute.html),  
attrID | \- уникальный номер типа атрибута,  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется в документе.  
  
Возвращаемое значение:

Указатель на интерфейс атрибута [IAttribute3D](ksattribute3d.html) | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html), которая может быть получена с помощью функции [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
