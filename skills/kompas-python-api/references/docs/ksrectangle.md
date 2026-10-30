# ksRectangle - Построить прямоугольник

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksregularpolygon.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kspointsoncurvebystep.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksrectangle_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksRectangle](ksdocument2d_ksrectangle.html).

Синтаксис:

reference ksRectangle (RectangleParam * par,

unsigned char centre);

Входные параметры:

par | \- указатель на [структуру параметров прямоугольника RectangleParam](structrectangleparam.html),  
---|---  
centre | \- признак построения обозначения центра: 0 - нет осей, 1 - значок осей (маленький "крестик"), 2 - горизонтальная ось, 3 - обе оси.  
  
Возвращаемое значение:

указатель на прямоугольник | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
