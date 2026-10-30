# ksAnnLineSeg - Создать аннотационный отрезок

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Аннотационные объекты ](bt1730611.html) |  Scroll [ [ [ ](ksdocument2d_ksannparellipsearc.html "К следующему разделу")](bt1730611.html "На уровень выше")](ksdocument2d_ksannellipsearc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [AnnLineSeg](annlineseg.html).

Синтаксис Automation:

long ksAnnLineSeg (double x1,

double y1,

double x2,

double y2,

short term1,

short term2,

long style);

Входные параметры:

x1, y1 | \- координаты первой точки отрезка,  
---|---  
x2, y2 | \- координаты второй точки отрезка,  
term1, term2 | \- типы значков на концах линии,  
style | \- стиль линии.  
  
[Системные типы значков...](marktypes.html)

[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на аннотационный отрезок | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
