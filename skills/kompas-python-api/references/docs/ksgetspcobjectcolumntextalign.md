# ksGetSpcObjectColumnTextAlign - Получить выравнивание для текста колонки объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectcolumnvalues.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectcolumntextw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectColumnTextAlign](ksspecification_ksgetspcobjectcolumntextalign.html).

Синтаксис:

int ksGetSpcObjectColumnTextAlign (reference spcObj,

int columnNumber,

int lineIndex);

Входной параметр:

spcObj | \- указатель на объект спецификации,  
---|---  
columnNumber | \- номер колонки, начиная с 1,  
lineIndex | \- индекс строки текста.  
  
Возвращаемое значение:

| \- Способ выравнивания в ячейке.  
---|---  
  
Примечания:

Значение переменной align может принимать значения:

– 0 - Выравнивание влево,

– 1 - Выравнивание по центру,

– 2 - Выравнивание вправо,

– 3 - Выравнивание по ширине.

Подразделы:

(отсутствуют)
