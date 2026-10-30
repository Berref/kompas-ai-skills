# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия разреза/сечения (Интерфейс ksCutLineParam) ](kscutlineparam.html) > [ksCutLineParam - методы ](kscutlineparam_methods.html) |  Scroll [ [ [ ](kscutlineparam_setpmathpoint.html "К следующему разделу")](kscutlineparam_methods.html "На уровень выше")](kscutlineparam_getptextline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutlineparam.html)

Синтаксис Automation:

BOOL Init();

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод обнуляет все параметры.

2\. Создается динамический массив pTextItem типа TEXT_ITEM_ARR.

3\. Создается динамический массив pMathPoint типа POINT_ARR.

Подразделы:

(отсутствуют)
