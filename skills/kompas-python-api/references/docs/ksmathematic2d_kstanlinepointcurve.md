# ksTanLinePointCurve - Получить точки касания кривой и прямой, проведенной через заданную точку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ce1717197.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kstanlinepointcircle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksTanLinePointCurve](kstanlinepointcurve.html).

Синтаксис Automation:

BOOL ksTanLinePointCurve (double x,

double y,

long pCur,

LPDISPATCH param);

Входные параметры:

pCur | \- указатель на кривую,  
---|---  
x, y | \- координаты точки.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) параметров математической точки типа POINT_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- точки касания обнаружены,  
---|---  
FALSE | \- точки касания не обнаружены.  
  
Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
