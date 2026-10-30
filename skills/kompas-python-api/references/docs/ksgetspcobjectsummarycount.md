# ksGetSpcObjectSummaryCount - Получить суммарное количество для одинаковых объектов

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcperformancename.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjgeometryex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectSummaryCount](ksspecification_ksgetspcobjectsummarycount.html).

Синтаксис:

double ksGetSpcObjectSummaryCount (reference spcObj,

int ispoln,

int blockNumber );

Входные параметры:

spcObj | \- объект спецификации,  
---|---  
ispoln | \- номер колонки типа "количество", начиная с 1 (актуально для СП типа Б),  
blockNumber | \- номер блока, начиная с 0 (актуально для СП типа A).  
  
Возвращаемое значение:

| \- cуммарное количество.  
---|---  
  
Подразделы:

(отсутствуют)
