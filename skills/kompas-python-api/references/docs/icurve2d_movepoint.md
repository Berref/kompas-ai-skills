# MovePoint - Сдвинуть точку на расстояние Lenght по кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_pointon.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_intersectex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL MovePoint( double * X,

double * Y,

double Lenght,

BOOL Direction );

Синтаксис COM:

HRESULT MovePoint( double * X,

double * Y,

double Lenght,

BOOL Direction,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки,  
---|---  
Lenght | \- расстояние, на которое нужно сместить точку,  
Direction | \- направление смещения.  
  
Выходные параметры:

X, Y | \- координаты точки после сдвига.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
