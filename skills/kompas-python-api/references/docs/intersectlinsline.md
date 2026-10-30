# IntersectLinSLine - Получить координаты точки пересечения отрезка и прямой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectlinslins.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectlinscir.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectlinsline_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectLinSLine](ksmathematic2d_ksintersectlinsline.html).

Синтаксис:

void IntersectLinSLine (double x1,

double y1,

double x2,

double y2,

double x,

double y,

double ang,

int *kp,

double *xp,

double *yp);

Входные параметры:

x1, y1 | \- координаты начальной точки отрезка,  
---|---  
x2, y2 | \- координаты конечной точки отрезка,  
x, y | \- координаты точки на прямой,  
ang | \- угол наклона прямой.  
  
Выходные параметры:

kp | \- число пересечений (0 или 1),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
