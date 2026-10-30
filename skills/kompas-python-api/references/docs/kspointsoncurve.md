# ksPointsOnCurve - Получить массив равномерно расположенных по кривой точек

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](kstancurvcurv.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](kspointintomtr.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurveperpendicular_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksPointsOnCurve](ksmathematic2d_kspointsoncurve.html).

Синтаксис:

reference ksPointsOnCurve (reference curve, int count);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
count | \- количество точек.  
  
Возвращаемое значение:

\- указатель на массив равномерно расположенных на указанной кривой точек. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
