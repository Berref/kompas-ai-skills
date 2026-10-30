# EllipseArc - Временная математическая дуга эллипса

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_line.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_ellipse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH EllipseArc( double Xc,

double Yc,

double A,

double B,

double Angle,

double Angle1,

double Angle2,

BOOL direction) ;

Синтаксис COM:

HRESULT EllipseArc( double Xc,

double Yc,

double A,

double B,

double Angle,

double Angle1,

double Angle2,

BOOL direction,

ICurve2D ** Result );

Входные параметры:

Xc, Yc | \- координаты центра дуги эллипса,  
---|---  
А, В | \- длина полуосей дуги эллипса,  
Angle | \- угол наклона дуги эллипса к оси ОХ.  
Angle1 | \- начальный угол дуги к оси А,  
Angle2 | \- конечный угол дуги к оси А,  
Direction | \- направление дуги (TRUE - по часовой стрелке, FALSE - против часовой стрелки).  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую дугу эллипса.

Подразделы:

(отсутствуют)
