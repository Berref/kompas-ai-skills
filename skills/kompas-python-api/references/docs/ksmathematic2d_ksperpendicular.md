# ksPerpendicular - Получить координаты точки пересечения отрезка и перпендикуляра к нему, проходящего через заданную точку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kspointsoncurve.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksmovepointoncurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [Perpendicular](perpendicular.html).

Синтаксис Automation:

BOOL ksPerpendicular (double x,

double y,

double x1,

double y1,

double x2,

double y2,

double* xp,

double* yp);

Входные параметры:

x, y | \- координаты произвольной точки,  
---|---  
x1, y1 | \- координаты начальной точки отрезка,  
x2, y2 | \- координаты конечной точки отрезка.  
  
Выходные параметры:

xp, yp | \- координаты точки пересечения отрезка и перпендикуляра к нему, проходящего через заданную точку.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
