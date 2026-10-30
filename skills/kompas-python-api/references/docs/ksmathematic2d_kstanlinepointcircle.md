# ksTanLinePointCircle - Получить точки касания окружности и прямой, проходящей через заданную точку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kstanlinepointcurve.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kstanlineangcircle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [TanLinePointCircle](tanlinepointcircle.html).

Синтаксис Automation:

BOOL ksTanLinePointCircle (double x,

double y,

double xc,

double yc,

double rad,

LPDISPATCH param);

Входные параметры:

x, y | \- координаты точки,  
---|---  
xc, yc | \- координаты центра окружности,  
rad | \- радиус окружности.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива параметров математической точки типа POINT_ARR [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- точки касания данных объектов обнаружены,  
---|---  
FALSE | \- точки касания не обнаружены.  
  
Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
