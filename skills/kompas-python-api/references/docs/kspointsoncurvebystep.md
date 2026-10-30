# ksPointsOnCurveByStep - Получить массив точек, расположенных на кривой с заданным шагом

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksrectangle.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](ksparellipsearc.html "К предыдущему разделу")  
---|---  
  
[Пример...](kspointsoncurvebystep_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksPointsOnCurveByStep](ksmathematic2d_kspointsoncurvebystep.html).

Синтаксис:

reference ksPointsOnCurveByStep (reference curve,

double step);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
step | \- шаг точек вдоль кривой.  
  
Возвращаемое значение:

указатель на динамический массив математических точек [ksDynamicArray](ksdynamicarray.html) типа POINT_ARR. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
