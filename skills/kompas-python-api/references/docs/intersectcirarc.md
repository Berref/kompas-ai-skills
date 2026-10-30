# IntersectCirArc - Получить координаты точек пересечения окружности и дуги

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectcircir.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectarcline.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectcirarc_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectCirArc](ksmathematic2d_ksintersectcirarc.html).

Синтаксис:

void IntersectCirArc (double xcc, double ycc,

double radc,

double xac, double yac,

double rada,

double fa1, double fa2,

short directa,

int * kp,

double xp, double yp);

Входные параметры:

xcс, ycс | \- координаты центра окружности,  
---|---  
radc | \- радиус окружности,  
xac, yac | \- координаты центра дуги,  
rada | \- радиус дуги,  
fa1, fa2 | \- углы начальной и конечной точек дуги,  
directa | \- направление дуги: 1 - против часовой стрелки, -1 - по часовой стрелке.  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
