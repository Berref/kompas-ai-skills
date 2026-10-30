# ksIntersectCirLin - Получить координаты точек пересечения окружности и прямой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectcurvcurv.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectcircir.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectCirLin](intersectcirlin.html).

Синтаксис Automation:

BOOL ksIntersectCirLin (double xc,

double yc,

double rad,

double xl,

double yl,

double angle,

LPDISPATCH param);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
rad | \- радиус окружности,  
x1, y1 | \- координаты точки на прямой,  
angle | \- угол наклона прямой.  
  
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
