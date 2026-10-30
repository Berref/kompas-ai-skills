# ksAnnParEllipseArc - Создать объект "Аннотационная дуга эллипса"

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Аннотационные объекты ](ann_objects_fncts_common.html) |  Scroll [ [ [ ](ksannpoint.html "К следующему разделу")](ann_objects_fncts_common.html "На уровень выше")](ksannellipsearc.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksAnnParEllipseArc](ksdocument2d_ksannparellipsearc.html).

Синтаксис:

reference LIB_FUNC ksAnnParEllipseArc ( EllipseArcParam1 * par,

unsigned char term1,

unsigned char term2 );

Входные параметры:

par | \- указатель на структуру параметров дуги эллипса [EllipseArcParam1](structellipsearcparam1.html),  
---|---  
term1, term2 | \- [типы значков](marktypes.html) на концах ломаной.  
  
Возвращаемое значение:

указатель на аннотационную дугу эллипса | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Аннотационные объекты можно создавать только в составе макро. Допускается создание аннотационных объектов во временной группе для последующего добавления в макро.

2\. При разрушении макро аннотационные объекты превращаются в геометрические.

Подразделы:

(отсутствуют)
