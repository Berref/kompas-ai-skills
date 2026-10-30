# SetAttrRow - Установить строку табличного атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](setattrtype.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](moveattriterator.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrvalue_setattrvalue_getattrrow_setattrrow_example.html)

Замечание. Функция устарела, вместо неё использовать [ksSetAttrRow](kssetattrrow.html).

Синтаксис:

int SetAttrRow (reference pAttr,

unsigned int rowNumb,

unsigned char *flagVisible,

void *value,

unsigned int size,

char * password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
flagVisible | \- указатель на массив флагов видимости ячеек строки,  
value | \- указатель на область памяти, откуда копируются данные,  
size | \- размер выделенной под value памяти,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfo](structcolumninfo.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
