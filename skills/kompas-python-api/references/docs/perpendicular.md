# Perpendicular - Получить координаты точки пересечения отрезка и перпендикуляра к нему, проходящего через заданную точку

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](tan_couple_fncts_common.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](ksintersectcurvcurvex.html "К предыдущему разделу")  
---|---  
  
[Пример...](perpendicular_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksPerpendicular](ksmathematic2d_ksperpendicular.html).

Синтаксис:

void Perpendicular (double x, double y, double x1, double y1,

double x2, double y2, double *xp, double *yp);

Входные параметры:

x, y | \- координаты точки,  
---|---  
x1, y1 | \- координаты начальной точки отрезка,  
x2, y2 | \- координаты конечной точки отрезка.  
  
Выходные параметры:

xp, yp | \- координаты точки пересечения отрезка и перпендикуляра к нему, проходящего через заданную точку.  
---|---  
  
Подразделы:

(отсутствуют)
