# ksAnnArcByPoint - Создать аннотационную дугу по точкам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Аннотационные объекты ](bt1730611.html) |  Scroll [ [ [ ](ksdocument2d_ksanncircle.html "К следующему разделу")](bt1730611.html "На уровень выше")](bt1730611.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [AnnArcByPoint](annarcbypoint.html).

Синтаксис Automation:

long ksAnnArcByPoint (double xc,

double yc,

double rad,

double x1,

double y1,

double x2,

double y2,

short direction,

short term1,

short term2,

long style);

Входные параметры:

xc, yc | \- координаты центра дуги,  
---|---  
rad | \- радиус дуги,  
x1, y1 | \- координаты начальной точки дуги,  
x2, y2 | \- координаты конечной точки дуги,  
direction | \- направление отрисовки дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
term1, term2 | типы значков на концах дуги,  
style | стиль линии.  
  
[Системные типы значков...](marktypes.html)

[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на аннотационную дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
