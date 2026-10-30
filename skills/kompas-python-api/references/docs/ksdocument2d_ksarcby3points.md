# ksArcBy3Points - Создать дугу по трем точкам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_kscircle.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_ksarcbypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ArcBy3Points](arcby3points.html).

Синтаксис Automation:

long ksArcBy3Points (double x1,

double y1,

double x2,

double y2,

double x3,

double y3,

long style);

Входные параметры:

x1, y1 | \- координаты начальной точки на дуге,  
---|---  
x2, y2 | \- координаты средней точки на дуге,  
x3, y3 | \- координаты конечной точки на дуге,  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
