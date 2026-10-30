# ksIntersectLinSLinS - Получить координаты точки пересечения двух отрезков

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksmovepointoncurve.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectlinsline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectLinSLinS](intersectlinslins.html).

Синтаксис Automation:

BOOL ksIntersectLinSLinS (double x11,

double y11,

double x12,

double y12,

double x21,

double y21,

double x22,

double y22,

LPDISPATCH param);

Входные параметры:

x11, y11 | \- координаты начальной точки первого отрезка,  
---|---  
x12, y12 | \- координаты конечной точки первого отрезка,  
x21, y21 | \- координаты начальной точки второго отрезка,  
x22, y22 | \- координаты конечной точки второго отрезка.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива параметров математической точки типа POINT_ARR [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- пересечение данных отрезков обнаружено,  
---|---  
FALSE | \- пересечение не обнаружено.  
  
Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
