# SetPText - Установить динамический массив строк текста

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Выносной элемент (Интерфейс ksRemoteElementParam) ](ksremoteelementparam.html) > [ksRemoteElementParam - методы ](ksremoteelementparam_methods.html) |  Scroll [ [ [ ](kschangeleaderparam.html "К следующему разделу")](ksremoteelementparam_methods.html "На уровень выше")](ksremoteelementparam_getptext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksremoteelementparam.html)

Синтаксис Automation:

BOOL SetPText (LPDISPATCH strArr)

Входной параметр:

strArr | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Если style == INDICATIN_TEXT_LINE_ARR, то тип динамического массива будет TEXT_LINE_ARR.

2\. Если style == 0, то тип динамического массива будет CHAR_STR_ARR.

Подразделы:

(отсутствуют)
