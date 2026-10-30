# Ellipse - Временный математический эллипс

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_ellipsearc.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_circle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Ellipse( double Xc,

double Yc,

double A,

double B,

double Angle );

Синтаксис COM:

HRESULT Ellipse( double Xc,

double Yc,

double A,

double B,

double Angle,

ICurve2D ** Result );

Входные параметры:

Xc, Yc | \- координаты центра эллипса,  
---|---  
А, В | \- длина полуосей эллипса,  
Angle | \- угол наклона эллипса к оси ОХ.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временный математический эллипс.

Подразделы:

(отсутствуют)
