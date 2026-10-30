# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения позиции (Интерфейс ksPosLeaderParam) ](ksposleaderparam.html) > [ksPosLeaderParam - методы ](ksposleaderparam_methods.html) |  Scroll [ [ [ ](ksposleaderparam_setppolyline.html "К следующему разделу")](ksposleaderparam_methods.html "На уровень выше")](ksposleaderparam_getptextline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksposleaderparam.html)

Синтаксис Automation:

BOOL Init();

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод обнуляет все параметры.

2\. Создается динамический массив pText типа CHAR_STR_ARR.

3\. Создается динамический массив pPolyline типа POLYLINE_ARR.

Подразделы:

(отсутствуют)
