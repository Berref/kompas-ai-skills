# ksGetCurvePerpendicular - Получить угол нормали к кривой в заданной точке

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksgetcurvepoint.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksgetcurveperimeter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCurvePerpendicular](ksgetcurveperpendicular.html).

Синтаксис Automation:

double ksGetCurvePerpendicular (long curve,

double x,

double y);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
x, y | \- координаты точки.  
  
Возвращаемое значение:

| \- угол нормали к кривой в заданной точке (в градусах).  
---|---  
  
Примечание:

Если указанная точка не находится на кривой, она проецируется на кривую.

Подразделы:

(отсутствуют)
