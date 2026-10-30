# ksMovePointOnCurveEx - Переместить точку на расстояние len по кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksgetcurveperpendicularbyt.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kslinepointtangentcurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksMovePointOnCurveEx](ksmovepointoncurveex.html).

Синтаксис Automation:

BOOL ksMovePointOnCurveEx( long curve, double* x, double* y, double* t, double len, long dir, long ext );

Входные параметры:

curve | \- указатель на кривую,  
---|---  
len | \- расстояние, на которое нужно сместить точку,  
dir | \- направление продвижения точки: 1 - в направлении построения кривой -1 - в обратном направлении,  
ext | \- учитывать продолжение кривой.  
  
Выходной параметр:

x, y | \- координаты точки.  
---|---  
t | \- параметр кривой.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

•Если в функцию перелается указатель на параметр кривой t, он используется в качестве начального параметра кривой для сдвига.

•Если указатель не передается, начальный параметр кривой определяется по координатам x, y.

Подразделы:

(отсутствуют)
