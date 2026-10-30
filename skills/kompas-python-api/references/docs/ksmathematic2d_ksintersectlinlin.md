# ksIntersectLinLin - Получить координаты точки пересечения двух прямых

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectlinsarc.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectcurvcurv.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectLinLin](intersectlinlin.html).

Синтаксис Automation:

BOOL ksIntersectLinLin (double x1,

double y1,

double angle1,

double x2,

double y2,

double angle2,

LPDISPATCH param);

Входные параметры:

x1, y1 | \- координаты точки на первой прямой,  
---|---  
angle1 | \- угол наклона первой прямой,  
x2, y2 | \- координаты точки на второй прямой,  
angle2 | \- угол наклона второй прямой,  
  
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
