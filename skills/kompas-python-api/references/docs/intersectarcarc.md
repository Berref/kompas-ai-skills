# IntersectArcArc - Получить координаты точек пересечения двух дуг окружностей

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectarcline.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intrsec_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectarcarc_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectArcArc](ksmathematic2d_ksintersectarcarc.html).

Синтаксис:

void IntersectArcArc (double xac, double yac,

double rada,

double fa1, double fa2,

short directa,

double xbc, double ybc,

double radb,

double fb1, double fb2,

short directb,

int * kp,

double xp[], double yp[]);

Входные параметры:

xac, yac | \- координаты центра первой дуги,  
---|---  
rada | \- радиус первой дуги,  
fa1, fa2 | \- углы начальной и конечной точек первой дуги,  
directa | \- направление первой дуги: 1 - против часовой стрелки, -1 – по часовой стрелке,  
xbc, ybc | \- координаты центра второй дуги,  
radb | \- радиус второй дуги,  
fb1, fb2 | \- углы начальной и конечной точек второй дуги,  
directb | \- направление второй дуги: 1 - против часовой стрелки, -1 – по часовой стрелке.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp[], yp[] | \- массивы координат точки пересечения.  
  
Подразделы:

(отсутствуют)
