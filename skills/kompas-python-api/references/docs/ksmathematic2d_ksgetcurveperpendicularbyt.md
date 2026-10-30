# ksGetCurvePerpendicularByT - Функция возвращает угол нормали к кривой в заданной точке по параметру кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksintersectarcarc.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksmovepointoncurveex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCurvePerpendicularByT](ksgetcurveperpendicularbyt.html).

Синтаксис Automation:

double ksGetCurvePerpendicularByT( long curve, double t );

Входные параметры:

p | \- указатель на кривую,  
---|---  
t | \- параметр кривой.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива ksDynamicArray углов касательных типа DOUBLE_ARR.  
---|---  
  
Возвращаемое значение:

| \- угол нормали.  
---|---  
  
Подразделы:

(отсутствуют)
