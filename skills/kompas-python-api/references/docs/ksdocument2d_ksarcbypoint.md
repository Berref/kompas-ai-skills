# ksArcByPoint - Создать дугу по центру и конечным точкам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksarcby3points.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_ksarcbyangle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ArcByPoint](arcbypoint.html).

Синтаксис Automation:

long ksArcByPoint (double xc,

double yc,

double rad,

double x1,

double y1,

double x2,

double y2,

short direction,

long style);

Входные параметры:

xc, yc | \- координаты центра дуги,  
---|---  
rad | \- радиус дуги,  
x1, y1 | \- координаты начальной точки дуги,  
x2, y2 | \- координаты конечной точки дуги,  
direction | \- направление отрисовки дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
