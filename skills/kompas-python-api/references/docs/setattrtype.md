# SetAttrType - Установить описание типа атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](setattrvalue.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](setattrrow.html "К предыдущему разделу")  
---|---  
  
[Пример...](setattrtype_example.html)

Функция устарела, рекомендуется использовать [ksSetAttrType](kssetattrtype.html).

Синтаксис:

int SetAttrType (double attrID,

char *libname,

AttributeType * attrType,

char * password);

Входные параметры:

attrID | \- уникальный номер типа атрибута,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то обрабатывается локальный атрибут текущего документа.  
attrType | \- [Структура типа атрибута](structksattributetype.html),  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
