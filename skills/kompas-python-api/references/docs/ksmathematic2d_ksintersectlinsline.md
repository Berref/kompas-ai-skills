# ksIntersectLinSLine - Получить координаты точки пересечения отрезка и прямой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectlinslins.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectlinscir.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectLinSLine](intersectlinsline.html).

Синтаксис Automation:

BOOL ksIntersectLinSLine (double x1,

double y1,

double x2,

double y2,

double x,

double y,

double ang,

LPDISPATCH param);

Входные параметры:

x1, y1 | \- координаты начальной точки отрезка,  
---|---  
x2, y2 | \- координаты конечной точки отрезка,  
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
