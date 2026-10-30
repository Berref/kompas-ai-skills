# GetpTextline - Получить указатель на интерфейс динамического массива текста обозначения позиции ksDynamicArray

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения позиции (Интерфейс ksPosLeaderParam) ](ksposleaderparam.html) > [ksPosLeaderParam - методы ](ksposleaderparam_methods.html) |  Scroll [ [ [ ](ksposleaderparam_init.html "К следующему разделу")](ksposleaderparam_methods.html "На уровень выше")](ksposleaderparam_getppolyline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksposleaderparam.html)

Синтаксис Automation:

LPDISPATCH GetpTextline();

Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа POLYLINE_ARR.  
---|---  
  
Примечания:

1\. Если свойство [ksPosLeaderParam::style](ksposleaderparam_style.html) = INDICATIN_TEXT_LINE_ARR, то динамический массив - типа TEXT_LINE_ARR (динамический массив строк текста), в остальных случаях - типа CHAR_STR_ARR (динамический массив строк обозначения позиции).

2\. Каждая строка соответствует одному номеру позиции.

Смотрите также:

[ksTextLineParam](kstextlineparam.html)

[ksChar255](kschar255.html)

Подразделы:

(отсутствуют)
