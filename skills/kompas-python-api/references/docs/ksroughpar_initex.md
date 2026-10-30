# InitEx - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Обозначение шероховатости ](ch1721808.html) > [Обозначение шероховатости (Интерфейс ksRoughPar) ](ksroughpar.html) > [ksRoughPar - методы ](ksroughpar_methods.html) |  Scroll [ [ [ ](ksroughpar_setptext.html "К следующему разделу")](ksroughpar_methods.html "На уровень выше")](ksroughpar_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksroughpar.html)

Синтаксис Automation:

BOOL InitEx (int style);

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод обнуляет все параметры.

2\. Если [style](ksroughpar_style.html) = INDICATIN_TEXT_LINE_ARR, то создается динамический массив pText типа TEXT_LINE_ARR, в противном случае создается динамический массив pText типа CHAR_STR_ARR.

Подразделы:

(отсутствуют)
