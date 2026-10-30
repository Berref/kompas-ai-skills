# AnnLineSeg - Построить аннотационный отрезок

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Аннотационные объекты ](ann_objects_fncts_common.html) |  Scroll [ [ [ ](ksanncircle.html "К следующему разделу")](ann_objects_fncts_common.html "На уровень выше")](annarcbypoint.html "К предыдущему разделу")  
---|---  
  
[Пример...](annlineseg_annarcbypoint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksAnnLineSeg](ksdocument2d_ksannlineseg.html).

Синтаксис:

reference AnnLineSeg (double x1, double y1,

double x2, double y2,

unsigned char term1, unsigned char term2,

unsigned short style);

Входные параметры:

x1, y1 | \- координаты первой точки отрезка,  
---|---  
x2, y2 | \- координаты второй точки отрезка,  
term1, term2 | \- [типы значков](marktypes.html) на концах линии,  
style | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на аннотационный отрезок | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
