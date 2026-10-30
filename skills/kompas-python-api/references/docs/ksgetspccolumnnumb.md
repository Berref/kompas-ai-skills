# ksGetSpcColumnNumb - Для данного объекта спецификации по типу колонки и номеру блока получить номер колонки

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspccolumntype.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetcurrentspcobject.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspctablecolumn_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcColumnNumb](ksspecification_ksgetspccolumnnumb.html).

Синтаксис:

int ksGetSpcColumnNumb (reference spcObj,

unsigned int columnType,

unsigned int typeNumb,

unsigned int block);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- тип колонки,  
ispoln | \- номер колонки данного типа, начиная с 1,  
block | \- номер блока исполнений.  
  
Возвращаемое значение:

номер колонки спецификации. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
[Типы колонок спецификации...](ctypes.html)

Подразделы:

(отсутствуют)
