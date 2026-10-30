# ksDistancePntArc - Получить расстояние между точкой и дугой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntcircle.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](kscalcmassinertiaproperties.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntlineseg_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntArc](ksmathematic2d_ksdistancepntarc.html).

Синтаксис:

double ksDistancePntArc (double x, double y,

double xac, double yac,

double rada,

double fa1, double fa2,

short directa);

Входные параметры:

x, y | \- координаты точки,  
---|---  
xac, yac | \- координаты центра дуги,  
rada | \- радиус дуги,  
fa1, fa2 | \- начальный и конечный углы дуги,  
directa | \- направление дуги: 1 - против часовой стрелки, -1 – по часовой стрелке.  
  
Возвращаемое значение:

расстояние между точкой и дугой. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
