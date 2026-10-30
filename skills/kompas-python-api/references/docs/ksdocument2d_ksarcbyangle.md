# ksArcByAngle - Создать дугу по двум точкам и углу раствора

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksarcbypoint.html "К следующему разделу")](bt1730616.html "На уровень выше")](bt1730616.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ArcByAngle](arcbyangle.html).

Синтаксис Automation:

long ksArcByAngle (double xc,

double yc,

double rad,

double f1,

double f2,

short direction,

long style);

Входные параметры:

xc, yc | \- координаты центра дуги,  
---|---  
rad | \- радиус дуги,  
f1, f2 | \- начальный и конечный угол дуги в градусах,  
direction | \- направление отрисовки дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
