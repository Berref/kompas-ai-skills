# PointProjection - Проекция точки на кривую

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_tangent.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_pointon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL PointProjection( double X,

double Y,

double * Kx,

double * Ky,

double * T,

double * Angle );

Синтаксис COM:

HRESULT PointProjection( double X,

double Y,

double * Kx,

double * Ky,

double * T,

double * Angle,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки.  
---|---  
  
Выходные параметры:

Kx, Ky | \- координаты проекции точки,  
---|---  
Т | \- параметр кривой,  
Angle | \- угол нормали.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет построить проекцию точки на кривую.

Подразделы:

(отсутствуют)
