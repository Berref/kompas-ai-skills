# ksIntersectCirArc - Получить координаты точек пересечения окружности и дуги

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectcircir.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksintersectarclin.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectCirArc](intersectcirarc.html).

Синтаксис Automation:

BOOL ksIntersectCirArc (double xcc,

double ycc,

double radc,

double xac,

double yac,

double rada,

double fa1,

double fa2,

short directa,

LPDISPATCH param);

Входные параметры:

xcс, ycс | \- координаты центра окружности,  
---|---  
radc | \- радиус окружности,  
xac, yac | \- координаты центра дуги,  
rada | \- радиус дуги,  
fa1, fa2 | \- углы начальной и конечной точек дуги,  
directa | \- направление дуги: 1 - против часовой стрелки, -1 - по часовой стрелке.  
  
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
