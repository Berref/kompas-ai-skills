# ksGetSpcObjectColumnValues - Получить массив значений для определенного типа колонки и исполнения значений для определенного типа колонки и исполнения

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectnumber.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectcolumntextalign.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

reference ksGetSpcObjectColumnVa

lues (reference spcObj,

unsigned int columnType,

unsigned int ispoln,

unsigned int block);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- [тип колонки](ctypes.html),  
ispoln | \- номер колонки данного типа, начиная с 1,  
block | \- номер блока исполнений.  
  
Возвращаемое значение:

динамический массив типа LTVARIANT_ARR | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

Для колонки типа "запись" функция вернет массив значений записи, а для колонки, состоящей из одного элемента - массив из одного элемента соответствующего типа.

Подразделы:

(отсутствуют)
