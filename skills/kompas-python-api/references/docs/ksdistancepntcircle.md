# ksDistancePntCircle - Получить расстояние между точкой и окружностью

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntline.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntarc.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntlineseg_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntCircle](ksmathematic2d_ksdistancepntcircle.html).

Синтаксис:

double ksDistancePntCircle (double x,

double y,

double xc, double yc,

double rad);

Входные параметры:

x, y | \- координаты точки,  
---|---  
xc, yc | \- координаты центра окружности,  
rad | \- радиус окружности.  
  
Возвращаемое значение:

расстояние между точкой и окружностью. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
