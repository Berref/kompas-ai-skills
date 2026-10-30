# ArcBy3Points - Создать дугу окружности по трем точкам

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](arcbypoint.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](arcbyangle.html "К предыдущему разделу")  
---|---  
  
[Пример...](arc_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksArcBy3Points.](ksdocument2d_ksarcby3points.html)

Синтаксис:

reference ArcBy3Points (double x1,

double y1,

double x2,

double y2,

double x3,

double y3,

int style);

Входные параметры:

x1, y1 | \- координаты начальной точки на дуге,  
---|---  
x2, y2 | \- координаты средней точки на дуге,  
x3, y3 | \- координаты конечной точки на дуге,  
style | \- [стиль линии](lstyles.html).  
  
Возвращаемое значение:

указатель на дугу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объект создается в текущем слое текущего вида.

Подразделы:

(отсутствуют)
