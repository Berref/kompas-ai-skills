# SelectParameters - Установить параметры резьбы для заданного диаметра и шага

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThreadPattern ](ithreadpattern.html) > [IThreadPattern - методы ](ithreadpattern_methods.html) |  Scroll [ [ [ ](ithreads.html "К следующему разделу")](ithreadpattern_methods.html "На уровень выше")](ithreadpattern_selectp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithreadpattern.html)

Синтаксис Automation:

BSTR SelectParameters( double NominalDiameter, double P, double * L, double * L1, double * L2 );

Синтаксис COM:

HRESULT SelectParameters( double NominalDiameter, double P, double * L, double * L1, double * L2, BSTR * Result );

Возвращаемое значение:

Обозначение резьбы.

Входные параметры:

NominalDiameter | \- номинальный диаметр,  
---|---  
P | \- шаг резьбы.  
  
Выходные параметры:

L | \- рабочая длина резьбы,  
---|---  
L1 | \- длина смещения основной плоскости для внешней резьбы,  
L2 | \- длина смещения основной плоскости для внутренней резьбы.  
  
Подразделы:

(отсутствуют)
