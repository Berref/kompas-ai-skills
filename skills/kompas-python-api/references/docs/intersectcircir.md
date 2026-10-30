# IntersectCirCir - Получить координаты точек пересечения двух окружностей

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectcirlin.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectcirarc.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectcircir_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksIntersectCirCir](ksmathematic2d_ksintersectcircir.html).

Синтаксис:

void IntersectCirCir (double xc1,double yc1,

double rad1, double xc2,

double yc2, double rad2,

int *kp, double xp, double yp);

Входные параметры:

xc1, yc1 | \- координаты центра первой окружности,  
---|---  
rad1 | \- радиус первой окружности,  
xc2, yc2 | \- координаты центра второй окружности,  
rad2 | \- радиус второй окружности,  
  
Выходные параметры:

kp | \- число пересечений (от 0 до 2),  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
