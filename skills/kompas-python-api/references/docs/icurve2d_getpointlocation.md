# GetPointLocation - Положение точки относительно кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_getselfintersectpoints.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_getnurbsparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

ksPointLocationTypeEnum GetPointLocation( double X, double Y );

Синтаксис COM:

HRESULT GetPointLocation( double X, double Y, ksPointLocationTypeEnum * Result );

Возвращаемое значение:

Result | \- положение двумерной точки относительно двумерной кривой [ksPointLocationTypeEnum](kspointlocationtypeenum.html).  
---|---  
  
Входные параметры:

X | \- первая координата точки,  
---|---  
Y | \- вторая координата точки.  
  
Подразделы:

(отсутствуют)
