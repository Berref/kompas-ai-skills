# LineSeg - Создать отрезок прямой линии

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](point.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](line.html "К предыдущему разделу")  
---|---  
  
[Пример...](lineseg_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksLineSeg](ksdocument2d_kslineseg.html).

Синтаксис:

reference LineSeg (double x1,

double y1,

double x2,

double y2,

unsigned int style);

Входные параметры:

x1, y1 | \- координаты первой точки отрезка,  
---|---  
x2, y2 | \- координаты второй точки отрезка,  
style | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на отрезок | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
