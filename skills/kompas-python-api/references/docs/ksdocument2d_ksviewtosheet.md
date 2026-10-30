# ksViewToSheet - Пересчитать точку из CK текущего вида в CK листа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_rasterformatparam.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kstextex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ViewToSheet](viewtosheet.html).

Синтаксис Automation:

long ksViewToSheet (double x,

double y,

double* outX,

double* outY);

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
