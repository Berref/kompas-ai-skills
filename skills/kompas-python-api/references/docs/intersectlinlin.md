# IntersectLinLin - Получить координаты точки пересечения двух прямых

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectlinsarc.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectcurvcurvex.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectlinlin_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectLinLin](ksmathematic2d_ksintersectlinlin.html).

Синтаксис:

void IntersectLinLin (double x1, double y1,

double angle1,

double x2, double y2,

double angle2,

int *kp,

double *xp, double *yp);

Входные параметры:

x1, y1 | \- координаты точки на первой прямой,  
---|---  
angle1 | \- угол наклона первой прямой,  
x2, y2 | \- координаты точки на второй прямой,  
angle2 | \- угол наклона второй прямой,  
  
Выходной параметр:

kp | \- число пересечений (0 или 1),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
