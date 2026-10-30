# ksIntersectArcLin - Получить координаты точек пересечения дуги окружности и прямой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectcirarc.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectarcarc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectArcLine](intersectarcline.html).

Синтаксис Automation:

BOOL ksIntersectArcLin (double xc,

double yc,

double rad,

double f1,

double f2,

long n,

double x,

double y,

double ang,

LPDISPATCH param);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус окружности,  
f1, f2 | \- углы начальной и конечной точек дуги,  
n | \- направление дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
x, y | \- координаты точки на прямой,  
ang | \- угол наклона прямой.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива параметров математической точки типа POINT_ARR [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- пересечение данных объектов обнаружено,  
---|---  
FALSE | \- пересечение не обнаружено.  
  
Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
