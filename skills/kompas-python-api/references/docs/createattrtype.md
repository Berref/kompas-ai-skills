# CreateAttrType - Создать описание типа атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](deleteattr.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](createattriterator.html "К предыдущему разделу")  
---|---  
  
[Пример...](createattrtype_example.html)

Синтаксис:

double CreateAttrType (AttributeType * attrType, char * libname);

Входные параметры:

attrType | \- указатель на структура параметров типа атрибута [ksAttributeType](structksattributetype.html).  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута создается в текущем документе.  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция устарела, рекомендуется использовать [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
