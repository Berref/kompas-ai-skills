# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) > [Параметры объектов спецификации ](ck1727663.html) > [Стиль спецификации (Интерфейс ksSpcStyleParam) ](ksspcstyleparam.html) > [ksSpcStyleParam - методы ](ksspcstyleparam_gettuning.html) |  Scroll [ [ [ ](ksspctuningstyleparam.html "К следующему разделу")](ksspcstyleparam_gettuning.html "На уровень выше")](ksspcstyleparam_gettuning.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcstyleparam.html)

Синтаксис Automation:

BOOL Init();

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод обнуляет все параметры.

2\. Создается динамический массив arrColumn типа SPCSTYLECOLUMN_ARR.

3\. Создается динамический массив arrAdditionalColumn типа SPCSTYLECOLUMN_ARR.

4\. Создается динамический массив arrSection типа SPCSTYLESEC_ARR.

Подразделы:

(отсутствуют)
