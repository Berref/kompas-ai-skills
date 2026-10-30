# SetpPolyline - Установить указатель на интерфейс динамического массива ответвлений линии-выноски обозначения маркировки ksDynamicArray типа POLYLINE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия - выноска ](ch1767016.html) > [Линия-выноска для обозначения маркировки (Интерфейс ksMarkerLeaderParam) ](ksmarkerleaderparam.html) > [ksMarkerLeaderParam - методы ](ksmarkerleaderparam_methods.html) |  Scroll [ [ [ ](ksmarkerleaderparam_setptextline.html "К следующему разделу")](ksmarkerleaderparam_methods.html "На уровень выше")](ksmarkerleaderparam_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmarkerleaderparam.html)

Синтаксис Automation:

BOOL SetpPolyline (LPDISPATCH pPolyline);

Входной параметр:

pPolyline | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа POLYLINE_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

В общем случае одно ответвление - это ломаная линия. Первый узел - базовая точка (ее в массив помещать не нужно, т.к. она общая для всех ответвлений), остальные узлы - изломы (могут отсутствовать), последний узел - конец ответвления (указывает на объект).

Смотрите также

[ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
