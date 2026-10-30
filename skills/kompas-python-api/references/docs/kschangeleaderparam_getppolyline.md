# GetpPolyline - Получить указатель на интерфейс динамического массива ответвлений линии-выноски ksDynamicArray типа POLYLINE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Знак изменения (Интерфейс ksChangeLeaderParam) ](kschangeleaderparam.html) > [ksChangeLeaderParam - методы ](kschangeleaderparam_methods.html) |  Scroll [ [ [ ](kschangeleaderparam_getptextline.html "К следующему разделу")](kschangeleaderparam_methods.html "На уровень выше")](kschangeleaderparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschangeleaderparam.html)

Синтаксис Automation:

LPDISPATCH GetpPolyline();

Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа TEXT_LINE_ARR.  
---|---  
  
Примечание:

В общем случае одно ответвление - это ломаная линия. Первый узел - базовая точка (ее в массив помещать не нужно, т.к. она общая для всех ответвлений), остальные узлы - изломы (могут отсутствовать), последний узел - конец ответвления (указывает на объект).

Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
