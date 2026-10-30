# ksPointsOnCurveByStep - Получить массив точек, расположенных на кривой с заданным шагом

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksrotate.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kspointsoncurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksPointsOnCurveByStep](kspointsoncurvebystep.html).

Синтаксис Automation:

LPDISPATCH ksPointsOnCurveByStep (long curve,

double step);

Входные параметры:

curve | \- указатель на кривую,  
---|---  
step | \- шаг точек вдоль кривой.  
  
Возвращаемое значение:

| \- указатель на динамический массив математических точек [ksDynamicArray](ksdynamicarray.html) типа POINT_ARR.  
---|---  
  
Подразделы:

(отсутствуют)
