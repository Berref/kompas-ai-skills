# ksGetCurvePoint - Преобразовать параметр кривой t в координаты вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](ksgetcurvepointprojection.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksgetcurveperpendicular.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksGetCurvePoint](ksmathematic2d_ksgetcurvepoint.html).

Синтаксис:

int ksGetCurvePoint (reference curve,

double t,

double *kx,

double *ky);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
t | \- параметр кривой.  
  
Выходные параметры:

kx, ky | \- координаты проекции точки на кривую,  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

См. также [ksGetCurvePointProjectionEx](ksgetcurvepointprojectionex.html)

Подразделы:

(отсутствуют)
