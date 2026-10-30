# ksGetCurvePerimeter - Получить длину периметра кривой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksviewgetdensity.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksdistancepntpntoncurve.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurveperimeter_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksGetCurvePerimeter](ksmathematic2d_ksgetcurveperimeter.html).

Синтаксис:

double ksGetCurvePerimeter (reference curve,

unsigned char dimension);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
dimension | \- размерность длины.  
  
[Размерности длины...](lentypes.html)

Возвращаемое значение:

длина периметра кривой | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
