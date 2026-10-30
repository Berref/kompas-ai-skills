# ksDistancePntLine - Получить расстояние между точкой и прямой, заданной точкой и углом

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntlineforpoint.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntcircle.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntlineseg_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntLine](ksmathematic2d_ksdistancepntline.html).

Синтаксис:

double ksDistancePntLine (double x,

double y,

double x1,

double y1,

double angle);

Входные параметры:

x, y | \- координаты точки,  
---|---  
x1, y1 | \- координаты точки на прямой,  
angle | \- угол наклона прямой.  
  
Возвращаемое значение:

расстояние между точкой и прямой. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
