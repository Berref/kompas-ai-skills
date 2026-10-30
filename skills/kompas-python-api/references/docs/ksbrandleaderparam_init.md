# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения параметров клеймения (Интерфейс ksBrandLeaderParam) ](ksbrandleaderparam.html) > [ksBrandLeaderParam - методы ](ksbrandleaderparam_methods.html) |  Scroll [ [ [ ](ksbrandleaderparam_setppolyline.html "К следующему разделу")](ksbrandleaderparam_methods.html "На уровень выше")](ksbrandleaderparam_getptextline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbrandleaderparam.html)

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
