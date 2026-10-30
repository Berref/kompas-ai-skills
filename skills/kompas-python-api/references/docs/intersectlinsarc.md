# IntersectLinSArc - Получить координаты точек пересечения отрезка и дуги

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectlinscir.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectlinlin.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectlinsarc_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectLinSArc](ksmathematic2d_ksintersectlinsarc.html).

Синтаксис:

void IntersectLinSArc (double x1, double y1,

double x2, double y2,

double xc, double yc,

double rad,

double f1, double f2,

short direct,

int * kp,

double xp, double yp);

Входные параметры:

x1, y1 | \- координаты начальной точки отрезка,  
---|---  
x2, y2 | \- координаты конечной точки отрезка,  
xc, yc | \- координаты центра дуги,  
rad | \- радиус дуги,  
f1, f2 | \- углы начальной и конечной точек дуги,  
direct | \- направление дуги: \- 1 - против часовой стрелки, \- 1 - по часовой стрелке.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
