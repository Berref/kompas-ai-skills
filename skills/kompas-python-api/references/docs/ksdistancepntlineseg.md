# ksDistancePntLineSeg - Получить расстояние между точкой и отрезком

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntpntoncurve.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntlineforpoint.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntlineseg_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntLineSeg](ksmathematic2d_ksdistancepntlineseg.html).

Синтаксис:

double ksDistancePntLineSeg (double x, double y,

double x1, double y1,

double x2, double y2);

Входные параметры:

x, y | \- координаты точки,  
---|---  
x1, y1 | \- координаты начальной точки отрезка,  
x2, y2 | \- координаты конечной точки отрезка.  
  
Возвращаемое значение:

расстояние между точкой и отрезком. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
