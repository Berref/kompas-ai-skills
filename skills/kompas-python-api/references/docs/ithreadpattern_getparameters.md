# GetParameters - Получить параметры резьбы для заданного диаметра и шага

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThreadPattern ](ithreadpattern.html) > [IThreadPattern - методы ](ithreadpattern_methods.html) |  Scroll [ [ [ ](ithreadpattern_selectdiameters.html "К следующему разделу")](ithreadpattern_methods.html "На уровень выше")](ithreadpattern_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithreadpattern.html)

Синтаксис Automation:

BSTR GetParameters( long Index, double * NominalDiameter, double * P, double * L, double * L1, double * L2 );

Синтаксис COM:

HRESULT GetParameters( long Index, double * NominalDiameter, double * P, double * L, double * L1, double * L2, BSTR * Result );

Возвращаемое значение:

| \- обозначение резьбы.  
---|---  
  
Входные параметры:

Index | \- индекс списка значений в базе стандартов.  
---|---  
  
Выходные параметры:

NominalDiameter | \- номинальный диаметр,  
---|---  
P | \- шаг резьбы,  
L | \- рабочая длина резьбы,  
L1 | \- длина смещения основной плоскости для внешней резьбы,  
L2 | \- длина смещения основной плоскости для внутренней резьбы.  
  
Подразделы:

(отсутствуют)
