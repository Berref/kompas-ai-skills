# Rotate - Повернуть точку на угол

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_symmetry.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_polyline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

BOOL Rotate( double * X,

double * Y,

double Xc,

double Yc,

double Angle );

Синтаксис COM:

HRESULT Rotate( double * X,

double * Y,

double Xc,

double Yc,

double Angle,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки, которую нужно повернуть,  
---|---  
Xс, Yс | \- координаты центра поворота,  
Angle | \- угол поворота.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет повернуть точку на угол.

Подразделы:

(отсутствуют)
