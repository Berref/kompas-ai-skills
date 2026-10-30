# PointOn - Получить координаты точки по параметру t

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_pointprojection.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_movepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL PointOn( double T,

double * X,

double * Y );

Синтаксис COM:

HRESULT PointOn( double T,

double * X,

double * Y,

BOOL * Result );

Входные параметры:

Т | \- параметр кривой.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить координаты точки по параметру кривой.

Подразделы:

(отсутствуют)
