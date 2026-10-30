# IntersectLinSLinS - Получить координаты точки пересечения двух отрезков

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](ksintersectcurvcurv.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectlinsline.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectlinslins_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectLinSLinS](ksmathematic2d_ksintersectlinslins.html).

Синтаксис:

Void IntersectLinSLinS (double x11, double y11,

double x12, double y12,

double x21, double y21,

double x22, double y22,

int * kp,

double * xp, double *yp);

Входные параметры:

x11, y11 | \- координаты начальной точки первого отрезка,  
---|---  
x12, y12 | \- координаты конечной точки первого отрезка,  
x21, y21 | \- координаты начальной точки второго отрезка,  
x22, y22 | \- координаты конечной точки второго отрезка.  
  
Выходные параметры:

kp | \- число пересечений (0 или 1),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
