# Circle - Временная математическая окружность

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_ellipse.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_bezier.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Circle( double Xc,

double Yc,

double Radius );

Синтаксис COM:

HRESULT Circle( double Xc,

double Yc,

double Radius,

ICurve2D ** Result );

Входные параметры:

Xc, Yc | \- координаты центра окружности,  
---|---  
Radius | \- радиус окружности.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую окружность.

Подразделы:

(отсутствуют)
