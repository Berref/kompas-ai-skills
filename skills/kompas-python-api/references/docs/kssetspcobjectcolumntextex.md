# ksSetSpcObjectColumnTextEx - Задать текст объекта спецификации для определенного типа колонки и исполнения

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcobjectcolumntextw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcobjectcolumntext.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcObjectColumnTextEx](ksspecification_kssetspcobjectcolumntextex.html).

Синтаксис:

int ksSetSpcObjectColumnTextEx (unsigned int columnType,

unsigned int ispoln,

unsigned int block,

reference p);

Входные параметры:

columnType | тип колонки SPC_CLM_FORMAT...SPC_CLM_USER,  
---|---  
ispoln | номер колонки данного типа, начиная с 1,  
block | номер блока,  
p | динамический массив строк текста TEXT_LINE_ARR.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае ошибки.  
  
Примечание:

Функция работает в режиме создания нового или редактирования существующего объекта спецификации [ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html)

... ksSetSpcObjectColumnTextEx(...); reference spsObj = ksSpcObjectEnd();.

Подразделы:

(отсутствуют)
