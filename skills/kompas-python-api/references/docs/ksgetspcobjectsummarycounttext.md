# ksGetSpcObjectSummaryCountText - Выдать отображаемый текст объекта СП для колонки количество

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjforgeom.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectnumber.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectSummaryCountText](ksspecification_ksgetspcobjectsummarycounttext.html).

Синтаксис:

reference ksGetSpcObjectSummaryCountText( reference spcObj,

unsigned int ispoln,

unsigned int block );

Входные параметры:

spcObj | объект спецификации,  
---|---  
ispoln | номер колонки типа "количество", начиная с 1 (актуально для СП типа Б),  
blockNumber | номер блока, начиная с 0 (актуально для СП типа A).  
  
Возвращаемое значение:

Динамический массив строк текста TEXT_LINE_ARR | \- в случае успеха,  
---|---  
0 | \- в случае ошибки.  
  
Примечание:

– В разных разделах количество может иметь различный тип.

– В разделе Детали стандартные изделия, например, количество имеет целочисленное значение. При объединении нескольких объектов спецификации в этом случае количество суммируется.

– В разделе Материал количество строковое, и текст возвращается с объекта, у которого задано не пустое значение.

– В разделе Документация также формируется объединенное значение.

– В отличии от [ksGetSpcObjectSummaryCoun](ksgetspcobjectsummarycount.html)t метод может вернуть не пустое значение для строковых колонок.

Подразделы:

(отсутствуют)
