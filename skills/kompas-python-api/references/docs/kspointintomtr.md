# ksPointIntoMtr - Пересчитать координаты точки из СК вида в локальную СК

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](kspointsoncurve.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](kspointfrommtr.html "К предыдущему разделу")  
---|---  
  
[Пример...](kspointintomtr_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksPointIntoMtr](ksdocument2d_kspointintomtr.html).

Синтаксис:

int ksPointIntoMtr (double x, double y, double *xn, double *yn);

Входные параметры:

x, y | \- координаты точки в системе координат вида.  
---|---  
  
Выходные параметры:

xn, yn | \- координаты точки в локальной СК.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
