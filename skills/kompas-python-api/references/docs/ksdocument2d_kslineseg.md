# ksLineSeg - Создать отрезок

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksparellipsearc.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_ksline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [LineSeg](lineseg.html).

Синтаксис Automation:

long ksLineSeg (double x1,

double y1,

double x2,

double y2,

long style);

Входные параметры:

x1, y1 | \- координаты первой точки отрезка,  
---|---  
x2, y2 | \- координаты второй точки отрезка,  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на отрезок | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
