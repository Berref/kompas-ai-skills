# ArcByPoint - Создать дугу по центру и конечным точкам

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](circle.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](arcby3points.html "К предыдущему разделу")  
---|---  
  
[Пример...](arc_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksArcByPoint](ksdocument2d_ksarcbypoint.html).

Синтаксис:

ArcByPoint (double xc,

double yc,

double rad,

double x1,

double y1,

double x2,

double y2,

short direction,

unsigned short style);

Входные параметры:

xc, yc | \- координаты центра дуги,  
---|---  
rad | \- радиус дуги,  
x1, y1 | \- координаты начальной точки дуги,  
x2, y2 | \- координаты конечной точки дуги,  
direction | \- направление отрисовки дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
type | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объект создается в текущем слое текущего вида.

Подразделы:

(отсутствуют)
