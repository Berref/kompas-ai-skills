# ksDistancePntLineForPoint - Получить расстояние между точкой и прямой, заданной двумя точками

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntlineseg.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntline.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntlineforpoint_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntLineForPoint](ksmathematic2d_ksdistancepntlineforpoint.html).

Синтаксис:

double ksDistancePntLineForPoint (double x,

double y,

double x1,

double y1,

double x2,

double y2);

Входные параметры:

x, y | \- координаты точки,  
---|---  
x1, y1 | \- координаты первой точки на прямой,  
x2, y2 | \- координаты второй точки на прямой.  
  
Возвращаемое значение:

расстояние между точкой и прямой. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
