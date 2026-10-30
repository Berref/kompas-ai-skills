# SetpTextline - Установить указатель на интерфейс динамического массива обозначения клеймения ksDynamicArray

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения параметров клеймения (Интерфейс ksBrandLeaderParam) ](ksbrandleaderparam.html) > [ksBrandLeaderParam - методы ](ksbrandleaderparam_methods.html) |  Scroll [ [ [ ](ksmarkerleaderparam.html "К следующему разделу")](ksbrandleaderparam_methods.html "На уровень выше")](ksbrandleaderparam_setppolyline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbrandleaderparam.html)

Синтаксис Automation:

BOOL SetpTextline (LPDISPATCH pTextline);

Входной параметр:

pTextline | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа POLYLINE_AR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Если свойство [ksBrandLeaderParam::style1](ksbrandleaderparam_style1.html) = INDICATIN_TEXT_LINE_ARR, то динамический массив ksDynamicArray - типа TEXT_LINE_ARR (динамический массив строк текста), в остальных случаях - типа CHAR_STR_ARR (динамический массив строк символов текста клеймения).

2\. Различают три разных текста для обозначения клеймения, их строки лежат в следующей последовательности:

•текст над полкой. Если свойство [cText0](ksbrandleaderparam_ctext0.html) = 0, то этот текст отсутствует;

•текста над "ножкой". Если свойство [cText1](ksbrandleaderparam_ctext1.html) = 0, то этот текст отсутствует;

•текст под "ножкой". Если свойство свойство [cText2](ksbrandleaderparam_ctext2.html) = 0, то этот текст отсутствует.

Смотрите также:

[ksTextLineParam](kstextlineparam.html)

[ksChar255](kschar255.html)

Подразделы:

(отсутствуют)
