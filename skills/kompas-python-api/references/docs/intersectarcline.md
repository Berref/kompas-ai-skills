# IntersectArcLine - Получить координаты точек пересечения дуги окружности и прямой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectcirarc.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectarcarc.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectarcline_example.html)

Синтаксис:

void IntersectArcLine (double xc,

double yc,

double rad,

double f1,

double f2,

int n,

double x,

double y,

double ang,

int *kp,

double xp[],

double yp[]);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус дуги,  
f1, f2 | \- углы начальной и конечной точек дуги,  
n | \- направление дуги,  
x, y | \- координаты точки на прямой,  
ang | \- угол наклона прямой.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
