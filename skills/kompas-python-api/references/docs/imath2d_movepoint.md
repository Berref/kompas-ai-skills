# MovePoint - Сместить точку

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_nurbs.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_lineseg.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

BOOL MovePoint( double * X,

double * Y,

Angle,

double Len );

Синтаксис COM:

HRESULT MovePoint( double * X,

double * Y,

double Angle,

double Len,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки,  
---|---  
Angle | \- угол смещения,  
Len | \- расстояние смещения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
