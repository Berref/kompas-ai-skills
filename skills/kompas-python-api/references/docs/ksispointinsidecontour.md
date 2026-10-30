# ksIsPointInsideContour - Проверить положение точки относительно кривой

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](kslengthfrommtr.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](ksiscurveclosed.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksispointinsidecontour_ksiscurveclosed_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksIsPointInsideContour](ksdocument2d_ksispointinsidecontour.html).

Синтаксис:

int ksIsPointInsideContour (reference p, double x, double y, double precision);

Входные параметры:

p | \- указатель на контур,  
---|---  
x, y | \- координаты точки,  
precision | \- точность проверки (от 1 до 1E-6).  
  
Возвращаемое значение:

0 | \- в случае неудачи,  
---|---  
1 | \- точка вне контура,  
2 | \- точка на контуре,  
3 | \- точка внутри контура.  
  
Подразделы:

(отсутствуют)
