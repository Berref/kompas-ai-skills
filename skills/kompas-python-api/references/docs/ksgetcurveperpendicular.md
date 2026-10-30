# ksGetCurvePerpendicular - Получить угол нормали к кривой в заданной точке

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](ksgetcurvepoint.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksgetcurveminmaxparametr.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurveperpendicular_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksGetCurvePerpendicular](ksmathematic2d_ksgetcurveperpendicular.html).

Синтаксис:

double ksGetCurvePerpendicular (reference curve, double x, double y);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
x, y | \- координаты точки.  
  
Возвращаемое значение:

угол нормали к кривой в заданной точке (в градусах). | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

Если указанная точка не находится на кривой, она проецируется на кривую.

Подразделы:

(отсутствуют)
