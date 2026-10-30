# ksCreateAttrType - Создать новый тип атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](kscreateattr3d.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](kscreateattr.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscreateattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksCreateAttrType](ksattributeobject_kscreateattrtype.html).

Синтаксис:

double ksCreateAttrType (ksAttributeType * attrType, char * libname);

Входные параметры:

attrType | \- attrType - указатель на структуру параметров типа атрибута [ksAttributeType](structksattributetype.html),  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута создается в текущем документе.  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
