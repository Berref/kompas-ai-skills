# ksGetCurveMinMaxParametr - Получить минимальный и максимальный параметр кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksgetcurveperimeter.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksequalpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCurveMinMaxParametr](ksgetcurveminmaxparametr.html).

Синтаксис Automation:

long ksGetCurveMinMaxParametr (long curve,

double *tMin,

double *tMax);

Входные параметры:

curve | \- указатель на кривую.  
---|---  
  
Выходные параметры:

tMin | \- минимальный параметр кривой,  
---|---  
tMax | \- максимальный параметр кривой.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
