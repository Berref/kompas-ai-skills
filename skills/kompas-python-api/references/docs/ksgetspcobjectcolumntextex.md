# ksGetSpcObjectColumnTextEx - Получить текст объекта спецификации для определенного типа колонки и исполнения в виде динамического массива TEXT_LINE_ARR

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectcolumntextw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectcolumntext.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::GetSpcObjectColumnTextEx](ksspecification_getspcobjectcolumntextex.html).

Синтаксис:

reference ksGetSpcObjectColumnTextEx (reference spcObj,

unsigned int columnType,

unsigned int ispoln,

unsigned int block)

Входные параметры:

spcObj | объект спецификации,  
---|---  
columnType | тип колонки SPC_CLM_FORMAT...SPC_CLM_USER,  
ispoln | номер колонки данного типа, начиная с 1,  
block | номер блока.  
  
Возвращаемое значение:

\- динамический массив строк текста TEXT_LINE_ARR, | \- в случае успеха,  
---|---  
0 | \- в случае ошибки.  
  
Примечание:

Если номер блока block = 0 - число исполнений меньше количества исполнений в бланке спецификации (для групповой спецификации 2.113-75 число исполнений меньше 10).

Подразделы:

(отсутствуют)
