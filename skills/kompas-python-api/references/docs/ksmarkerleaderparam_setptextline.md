# SetpTextline - Установить указатель на интерфейс динамического массива текста обозначения маркировки ksDynamicArray

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения маркировки (Интерфейс ksMarkerLeaderParam) ](ksmarkerleaderparam.html) > [ksMarkerLeaderParam - методы ](ksmarkerleaderparam_methods.html) |  Scroll [ [ [ ](kscutlineparam.html "К следующему разделу")](ksmarkerleaderparam_methods.html "На уровень выше")](ksmarkerleaderparam_setppolyline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmarkerleaderparam.html)

Синтаксис Automation:

BOOL SetpTextline (LPDISPATCH pTextline);

Входной параметр:

pTextline | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Если свойство [ksMarkerLeaderParam::style1](ksmarkerleaderparam_style1.html) = INDICATIN_TEXT_LINE_ARR, то динамический массив ksDynamicArray - типа TEXT_LINE_ARR (динамический массив строк текста), в остальных случаях - типа CHAR_STR_ARR (динамический массив строк символов текста маркировки).

2\. Различают три разных текста для обозначения маркировки, их строки лежат в следующей последовательности:

•текст над полкой. Если свойство [cText0](ksmarkerleaderparam_ctext0.html) = 0, то этот текст отсутствует;

•[текста над "ножкой". Если свойство ](ksmarkerleaderparam_ctext1.html)cText1 = 0, то этот текст отсутствует;

•текст под "ножкой". Если свойство [cText2](ksmarkerleaderparam_ctext2.html) = 0, то этот текст отсутствует.

Смотрите также:

[ksTextLineParam](kstextlineparam.html)

[ksChar255](kschar255.html)

Подразделы:

(отсутствуют)
