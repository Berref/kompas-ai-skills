# ksRegularPolygon - Создать правильный многоугольник с заданными параметрами

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](line.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](ksrectangle.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksregularpolygon_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksRegularPolygon](ksdocument2d_ksregularpolygon.html).

Синтаксис:

reference ksRegularPolygon (RegularPolygonParam * par,

unsigned char centre);

Входные параметры:

centre | \- признак построения обозначения центра: 0 - нет осей, 1 - значок осей (маленький "крестик"), 2 - горизонтальная ось, 3 - обе оси.  
---|---  
  
Выходные параметры:

par | \- указатель на [структуру параметров правильного многоугольника.](structregularpolygonparam.html)  
---|---  
  
Возвращаемое значение:

указатель на многоугольник | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
