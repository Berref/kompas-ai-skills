# SelectP - Cписок шагов резьбы для данного диаметра

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThreadPattern ](ithreadpattern.html) > [IThreadPattern - методы ](ithreadpattern_methods.html) |  Scroll [ [ [ ](ithreadpattern_selectparameters.html "К следующему разделу")](ithreadpattern_methods.html "На уровень выше")](ithreadpattern_selectdiameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithreadpattern.html)

Синтаксис Automation:

VARIANT SelectP( double NominalDiameter);

Синтаксис COM:

HRESULT SelectP( double NominalDiameter, VARIANT * Result );

Возвращаемое значение:

Массив SafeAttray типа (VT_ARRAY | VT_R8)

со списком значений шагов для заданного диаметра и текущего стандарта.

Входные параметры:

NominalDiameter | \- номинальный диаметр резьбы.  
---|---  
  
Подразделы:

(отсутствуют)
