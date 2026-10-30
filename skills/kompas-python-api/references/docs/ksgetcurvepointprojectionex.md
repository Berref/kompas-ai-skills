# ksGetCurvePointProjectionEx - Расcчитать координаты проекции точки на кривую

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](ksiscurveclosed.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksgetcurvepointprojection.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksGetCurvePointProjectionEx](ksmathematic2d_ksgetcurvepointprojectionex.html).

Синтаксис:

int ksGetCurvePointProjectionEx (reference curve,

double x,

double y,

double *kx,

double *ky,

double *t);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
x, y | \- координаты проецируемой точки.  
  
Выходные параметры:

kx, ky | \- координаты проекции точки на кривую,  
---|---  
t | \- параметр кривой.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. См. также [ksGetCurvePointProjection](ksgetcurvepointprojection.html)

2\. При выполнении функции ksGetCurvePointProjectionEx проекция на кривую из данной точки может быть не найдена, например, если проекция находится на продолжении кривой. В таком случае возвращаются координаты ближайшей к проекции начальной или конечной точки кривой.

3\. В функцию ksGetCurvePointProjectionEx нужно передавать координаты в системе координат кривой, то есть в системе координат макроэлемента, которому принадлежит кривая. Возвращаются координаты также в системе координат кривой.

Подразделы:

(отсутствуют)
