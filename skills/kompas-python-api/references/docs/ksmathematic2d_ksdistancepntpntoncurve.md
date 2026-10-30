# ksDistancePntPntOnCurve - Получить расстояние между двумя точками на кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksdistancet1t2oncurve.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksdistancepntpnt.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksDistancePntPntOnCurve](ksdistancepntpntoncurve.html).

Синтаксис Automation:

double ksDistancePntPntOnCurve (long curve,

double x1,

double y1,

double x2,

double y2);

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
