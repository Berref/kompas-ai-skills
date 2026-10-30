# AnnArcByPoint - Создать аннотационную дугу по точкам

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Аннотационные объекты ](ann_objects_fncts_common.html) |  Scroll [ [ [ ](annlineseg.html "К следующему разделу")](ann_objects_fncts_common.html "На уровень выше")](ann_objects_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](annlineseg_annarcbypoint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksAnnArcByPoint](ksdocument2d_ksannarcbypoint.html).

Синтаксис:

reference AnnArcByPoint (double xc, double yc, double rad,

double x2, double y2,

short direction,

unsigned char term1, unsigned char term2,

unsigned short style);

Входные параметры:

xc, yc | \- координаты центра дуги,  
---|---  
rad | \- радиус дуги,  
x1, y1 | \- координаты начальной точки дуги,  
x2, y2 | \- координаты конечной точки дуги,  
direction | \- направление отрисовки дуги: 1 - против часовой стрелки, -1 - по часовой стрелке,  
term1, term2 | \- [типы значков](marktypes.html) на концах дуги,  
style | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на аннотационную дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
