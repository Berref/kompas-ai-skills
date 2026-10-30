# IntersectCirLin - Получить координаты точек пересечения окружности и прямой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectcurvcurv.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectcircir.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectcirlin_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectCirLin](ksmathematic2d_ksintersectcirlin.html).

Синтаксис:

void IntersectCirLin (double xc,

double yc,

double rad,

double x,

double y,

double ang,

int *kp,

double xp,

double yp);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус окружности,  
x, y | \- координаты точки на прямой,  
ang | \- угол наклона прямой.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
