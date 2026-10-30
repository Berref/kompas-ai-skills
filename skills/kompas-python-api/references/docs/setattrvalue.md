# SetAttrValue - Установить значение атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](vieweditattr.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](setattrtype.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrvalue_setattrvalue_getattrrow_setattrrow_example.html)

Замечание. Функция устарела, вместо неё использовать [ksSetAttrValue](kssetattrvalue.html).

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksSetAttrValue](ksattributeobject_kssetattrvalue.html).

Синтаксис:

int SetAttrValue (reference pAttr,

unsigned int rowNumb,

unsigned int columnNumb,

unsigned char *flagVisible,

void *value,

unsigned int size, char * password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
columnNumb | \- номер колонки,  
flagVisible | \- флаг видимости ячейки (одно значение, если не запись и массив значений, если запись),  
value | \- указатель на область памяти, откуда копируется значение ячейки,  
size | \- размер выделенной памяти под value,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfo](structcolumninfo.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
