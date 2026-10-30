# ksCreateAttr - Создать атрибут объекта

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](kscreateattrtype.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](kschoiceattr3d.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscreateattr_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html).

Синтаксис:

reference ksCreateAttr (reference pObj,

ksAttribute * attr,

double attrID,

char *libname);

Входные параметры:

pObj | \- указатель на объект (группа, вид, отдельный объект), атрибут которого создается. Если pObj = 0, то создается атрибут документа,  
---|---  
attr | \- указатель на структуру параметров атрибута [ksAttribute](structksattribute.html),  
attrID | \- уникальный номер типа атрибута,  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа.  
  
Возвращаемое значение:

указатель на атрибут | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Указатель на объект reference pObj может быть получен следующими способами:

– с помощью функций Итератора [CreateIterator](createiterator.html), [MoveIterator](moveiterator.html).

– с помощью функций создания объектов, возвращающих указатель reference на созданный объект, например, reference LineSeg.

2\. Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html), которая может быть получена с помощью функции [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html), или с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
