# ksGetCurvePoint - Преобразовать параметр кривой t в координаты вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksgetcurvepointprojection.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksgetcurveperpendicular.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCurvePoint](ksgetcurvepoint.html).

Синтаксис Automation:

long ksGetCurvePoint (long curve,

double t,

double *x,

double *y);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
t | \- параметр кривой.  
  
Выходные параметры:

kx, ky | \- координаты проекции точки на кривую,  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

См. также [ksMathematic2D::ksGetCurvePointProjectionEx](ksmathematic2d_ksgetcurvepointprojectionex.html).

Подразделы:

(отсутствуют)
