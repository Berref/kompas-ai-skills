# ksGetCurveMinMaxParametr - Получить минимальный и максимальный параметр кривой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](ksgetcurveperpendicular.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksequalpoints.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksGetCurveMinMaxParametr](ksmathematic2d_ksgetcurveminmaxparametr.html).

Синтаксис:

int ksGetCurveMinMaxParametr (reference curve,double *tMin,double *tMax);

Входные параметры:

curve | \- указатель на кривую,  
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
