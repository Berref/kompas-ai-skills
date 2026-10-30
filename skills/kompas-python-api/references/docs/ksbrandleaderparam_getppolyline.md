# GetpPolyline - Получить указатель на интерфейс динамического массива ответвлений линии-выноски обозначения клеймения ksDynamicArray типа POLYLINE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения параметров клеймения (Интерфейс ksBrandLeaderParam) ](ksbrandleaderparam.html) > [ksBrandLeaderParam - методы ](ksbrandleaderparam_methods.html) |  Scroll [ [ [ ](ksbrandleaderparam_getptextline.html "К следующему разделу")](ksbrandleaderparam_methods.html "На уровень выше")](ksbrandleaderparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbrandleaderparam.html)

Получить указатель на интерфейс динамического массива ответвлений линии-выноски обозначения клеймения ksDynamicArray типа POLYLINE_ARR.

Синтаксис Automation:

LPDISPATCH GetpPolyline();

Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа POLYLINE_AR.  
---|---  
  
Примечание:

В общем случае одно ответвление - это ломаная линия. Первый узел - базовая точка (ее в массив помещать не нужно, т.к. она общая для всех ответвлений), остальные узлы - изломы (могут отсутствовать), последний узел - конец ответвления (указывает на объект).

Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
