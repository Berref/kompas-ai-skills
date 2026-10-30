# ksPointFromMtr - Пересчитать координаты точки из локальной СК в СК вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](kspointintomtr.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksmakeenclosecontours.html "К предыдущему разделу")  
---|---  
  
[Пример...](kspointfrommtr_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksPointFromMtr.](ksdocument2d_kspointfrommtr.html)

Синтаксис:

int ksPointFromMtr (double x, double y, double *xn, double *yn);

Входные параметры:

x, y | \- координаты точки в локальной системе координат,  
---|---  
  
Выходные параметры:

xn, yn | \- координаты точки в СК вида.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
