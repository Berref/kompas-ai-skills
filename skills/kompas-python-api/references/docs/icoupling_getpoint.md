# GetPoint - Получить координаты точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ICoupling ](icoupling.html) > [ICoupling - методы ](icouplingmethods.html) |  Scroll [ [ [ ](icoupling_setpoint.html "К следующему разделу")](icouplingmethods.html "На уровень выше")](icoupling_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icoupling.html)

Синтаксис Automation:

BOOL GetPoint( long Index, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( long Index, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

long Index | \- индекс сечения в цепочке.  
---|---  
  
Выходные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
