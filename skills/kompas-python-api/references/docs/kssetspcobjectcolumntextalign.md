# ksSetSpcObjectColumnTextAlign - Установить выравнивание для текста колонки объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcperformancename.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcobjectcolumntextw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectSummaryCount](ksspecification_ksgetspcobjectsummarycount.html).

Синтаксис:

int ksSetSpcObjectColumnTextAlign (reference spcObj,

int columnNumber,

int lineIndex,

int align );

Входной параметр:

spcObj | \- указатель на объект спецификации,  
---|---  
columnNumber | \- номер колонки, начиная с 1,  
lineIndex | \- индекс строки текста,  
align | \- выравнивание.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Значение переменной align может принимать значения:

– 0 - Выравнивание влево

– 1 - Выравнивание по центру

– 2 - Выравнивание вправо

– 3 - Выравнивание по ширине

Подразделы:

(отсутствуют)
