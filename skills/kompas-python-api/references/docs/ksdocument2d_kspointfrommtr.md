# ksPointFromMtr - Пересчитать координаты точки из локальной системы координат в СК вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kspointintomtr.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksplacementex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksPointFromMtr](kspointfrommtr.html).

Синтаксис Automation:

long ksPointFromMtr (double x, double y, double* xn, double* yn);

Входные параметры:

x, y | \- координаты точки в локальной системе координат.  
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
