# Arc - Временная математическая дуга

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_bezier.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Arc( double Xc,

double Yc,

double Radius,

double Angle1,

double Angle2, 

BOOL direction);

Синтаксис COM:

HRESULT Arc( double X,

double Y,

double Angle,

BOOL direction,

ICurve2D ** Result );

Входные параметры:

X, Y | \- координаты точки, через которую проходит прямая,  
---|---  
Angle | \- угол между прямой и осью ОХ,  
Direction | \- направление дуги (TRUE - по часовой стрелке, FALSE - против часовой стрелки).  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую дугу.

Подразделы:

(отсутствуют)
