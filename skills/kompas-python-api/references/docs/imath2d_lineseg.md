# LineSeg - Временный математический отрезок

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_movepoint.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_line.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH LineSeg( double X1,

double Y1,

double X2,

double Y2 );

Синтаксис COM:

HRESULT LineSeg( double X1,

double Y1,

double X2,

double Y2,

ICurve2D ** Result );

Входные параметры:

X1, Y1 | \- координаты первой точки отрезка,  
---|---  
X2, Y2 | \- координаты второй точки отрезка.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временный математический отрезок.

Подразделы:

(отсутствуют)
