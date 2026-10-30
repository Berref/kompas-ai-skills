# Symmetry - Симметрия точки относительно оси

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](service.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_rotate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

BOOL Symmetry( double * X,

double * Y,

LPDISPATCH Curve );

Синтаксис COM:

HRESULT Symmetry( double * X,

double * Y,

ICurve2D * Curve,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки,  
---|---  
Curve | \- ось (математическая прямая или отрезок).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить координаты точки, симметричной относительно заданной оси.

Подразделы:

(отсутствуют)
