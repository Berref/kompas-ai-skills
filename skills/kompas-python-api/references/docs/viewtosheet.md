# ViewToSheet - Пересчитать координаты точки из СК текущего вида в СК листа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](intrsec_fncts_common.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](tand.html "К предыдущему разделу")  
---|---  
  
[Пример...](getviewnumber_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksViewToSheet](ksdocument2d_ksviewtosheet.html).

Синтаксис:

int ViewToSheet (double x, double y, double * outX, double * outY);

Входные параметры:

x, y | \- координаты точки в системе координат вида.  
---|---  
  
Выходные параметры:

outX, outY | \- координаты точки в системе координат листа.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
