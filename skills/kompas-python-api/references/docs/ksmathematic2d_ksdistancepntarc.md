# ksDistancePntArc - Получить расстояние между точкой и дугой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksdistancepntcircle.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksdistancecurvecurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksDistancePntArc](ksdistancepntarc.html).

Синтаксис Automation:

double ksDistancePntArc (double x,

double y,

double xac,

double yac,

double rada,

double fa1,

double fa2,

short directa);

Входные параметры:

x, y | \- координаты точки,  
---|---  
xac, yac | \- координаты центра дуги,  
rada | \- радиус дуги,  
fa1, fa2 | \- начальный и конечный углы дуги,  
directa | \- направление дуги: 1 - против часовой стрелки, -1 – по часовой стрелке.  
  
Возвращаемое значение:

| \- расстояние между точкой и дугой.  
---|---  
  
Подразделы:

(отсутствуют)
