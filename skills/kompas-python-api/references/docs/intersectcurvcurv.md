# IntersectCurvCurv - Получить координаты точек пересечения двух кривых

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления пересечений ](intrsec_fncts_common.html) |  Scroll [ [ [ ](intersectcurvcurvex.html "К следующему разделу")](intrsec_fncts_common.html "На уровень выше")](intersectcirlin.html "К предыдущему разделу")  
---|---  
  
[Пример...](intersectcurvcurv_example.html)

Синтаксис:

void IntersectCurvCurv (reference p1, reference p2, int *kp, double xp, double yp, int MaxCount);

Входные параметры:

p1 | \- указатель на первую кривую,  
---|---  
p2 | \- указатель на вторую кривую,  
MaxCount | \- максимальное число выдаваемых точек пересечений.  
  
Выходные параметры:

kp | \- число пересечений,  
---|---  
xp, yp | \- координаты точки пересечения.  
  
Подразделы:

(отсутствуют)
