# ksGetCurvePointProjection - Получить координаты проекции точки на кривую

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksgetcurvepointprojectionex.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksgetcurvepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCurvePointProjection](ksgetcurvepointprojection.html).

Синтаксис Automation:

long ksGetCurvePointProjection (long curve,

double x,

double y,

double* kx,

double* ky);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
x, y | \- координаты проецируемой точки.  
  
Выходные параметры:

kx, ky | \- координаты проекции точки на кривую.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. См. также [ksMathematic2D::ksGetCurvePointProjectionEx](ksmathematic2d_ksgetcurvepointprojectionex.html).

2\. При выполнении метода ksGetCurvePointProjection проекция на кривую из данной точки может быть не найдена, например, если проекция находится на продолжении кривой. В таком случае возвращаются координаты ближайшей к проекции начальной или конечной точки кривой.

3\. В метод ksGetCurvePointProjection нужно передавать координаты в системе координат кривой, то есть в системе координат макроэлемента, которому принадлежит кривая. Возвращаются координаты также в системе координат кривой.

Подразделы:

(отсутствуют)
