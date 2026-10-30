# GetDistancePointPoint - Получить расстояние между двумя точками на кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_getdistancetopoint.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_couplingcurvcurv.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

double GetDistancePointPoint( double X1,

double Y1,

double X2,

double Y2 );

Синтаксис COM:

HRESULT GetDistancePointPoint( double X1,

double Y1,

double X2,

double Y2,

double * Result );

Входные параметры:

X1, Y1 | \- координаты первой точки,  
---|---  
X2, Y2 | \- координаты второй точки.  
  
Возвращаемое значение:

| \- Расстояние между двумя точками.  
---|---  
  
Примечание:

Метод позволяет получить расстояние между двумя точками на кривой.

Подразделы:

(отсутствуют)
