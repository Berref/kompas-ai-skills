# ksDistancePntPntOnCurve - Получить расстояние между двумя точками на кривой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksgetcurveperimeter.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntlineseg.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksdistancepntpntoncurve_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksDistancePntPntOnCurve](ksmathematic2d_ksdistancepntpntoncurve.html).

Синтаксис:

double ksDistancePntPntOnCurve (reference curve,

double x1, double y1,

double x2, double y2);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
x1, y1 | \- координаты первой точки,  
x2, y2 | \- координаты второй точки.  
  
Возвращаемое значение:

расстояние между двумя точками на кривой | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если заданные точки не находятся на кривой, то определяется расстояние между их проекциями на кривую.

Подразделы:

(отсутствуют)
