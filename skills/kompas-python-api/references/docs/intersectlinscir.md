# IntersectLinSCir - Получить координаты точек пересечения отрезка и окружности

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectlinsline.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectlinsarc.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectlinscir_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectLinSCir](ksmathematic2d_ksintersectlinscir.html).

Синтаксис:

void IntersectLinSCir (double x1, double y1,

double x2, double y2,

double xc, double yc,

double rad,

int * kp,

double xp, double yp);

Входные параметры:

x1, y1 | \- координаты начальной точки отрезка,  
---|---  
x2, y2 | \- координаты конечной точки отрезка,  
xc, yc | \- координаты центра окружности,  
rad | \- радиус окружности.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
