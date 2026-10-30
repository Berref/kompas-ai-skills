# GetpTextline - Получить указатель на интерфейс динамического массива текста линии-выноски ksDynamicArray типа TEXT_LINE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия - выноска (Интерфейс ksLeaderParam) ](ksleaderparam.html) > [ksLeaderParam - методы ](ksleaderparam_methods.html) |  Scroll [ [ [ ](ksleaderparam_init.html "К следующему разделу")](ksleaderparam_methods.html "На уровень выше")](ksleaderparam_getppolyline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksleaderparam.html)

Синтаксис Automation:

LPDISPATCH GetpTextline();

Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа POLYLINE_ARR.  
---|---  
  
Примечание:

Различают четыре разных текста для линии-выноски, их строки лежат в следующей последовательности:

•текст над полкой. Если свойство [cText0](ksleaderparam_ctext0.html) = 0, то этот текст отсутствует;

•текст под полкой. Если свойство [cText1](ksleaderparam_ctext1.html) = 0, то этот текст отсутствует;

•текст над ножкой. Если свойство [cText2](ksleaderparam_ctext2.html) = 0, то этот текст отсутствует;

•текст под ножкой. Если свойство [cText3](ksleaderparam_ctext3.html) = 0, то этот текст отсутствует.

Смотрите также: [ksTextLineParam](kstextlineparam.html)

Подразделы:

(отсутствуют)
