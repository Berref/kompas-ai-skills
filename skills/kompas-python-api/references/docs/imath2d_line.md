# Line - Временная математическая прямая

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_lineseg.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_ellipsearc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Line( double X,

double Y,

double Angle );

Синтаксис COM:

HRESULT Line( double X,

double Y,

double Angle,

ICurve2D ** Result );

Входные параметры:

X, Y | \- координаты точки, через которую проходит прямая,  
---|---  
Angle | \- угол наклона прямой к оси ОХ.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую прямую.

Подразделы:

(отсутствуют)
