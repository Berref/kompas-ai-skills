# GetAttrType - Получить описание типа атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrvalue.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getattrtabinfo.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrtype_example.html)

Функция устарела, рекомендуется использовать [ksGetAttrType](ksgetattrtype.html).

Синтаксис:

int GetAttrType (double attrID, char *libname, AttributeType * attrType);

Входной параметр:

attrID | \- уникальный номер типа атрибута,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута из текущего документа.  
  
Выходной параметр:

attrType | \- указатель на [структуру типа атрибута...](structksattributetype.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
