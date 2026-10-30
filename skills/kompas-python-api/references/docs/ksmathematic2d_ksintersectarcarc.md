# ksIntersectArcArc - Получить координаты точек пересечения двух дуг окружностей

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectarclin.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksgetcurveperpendicularbyt.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [IntersectArcArc](intersectarcarc.html).

Синтаксис Automation:

BOOL ksIntersectArcArc (double xac,

double yac,

double rada,

double fa1,

double fa2,

short directa,

double xbc,

double ybc,

double radb,

double fb1,

double fb2,

short directb,

LPDISPATCH param);

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
