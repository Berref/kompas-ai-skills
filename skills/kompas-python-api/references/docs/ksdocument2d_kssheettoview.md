# ksSheetToView - Пересчитать точку из системы координат листа в CK текущего вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksspecificationonsheet.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kssetobjectstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [SheetToView](sheettoview.html).

Синтаксис Automation:

long ksSheetToView (double x,

double y,

double* outX,

double* outY);

Входные параметры:

x, y | \- координаты точки в системе координат листа.  
---|---  
  
Выходные параметры:

outX, outY | \- координаты точки в системе координат вида.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
