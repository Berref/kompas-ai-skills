# GetPoint - Получить точку пересечения

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IConicCurve ](iconiccurve.html) > [IConicCurve - методы ](iconiccurve_methods.html) |  Scroll [ [ [ ](iconiccurve_setpoint.html "К следующему разделу")](iconiccurve_methods.html "На уровень выше")](iconiccurve_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurve.html)

Синтаксис Automation:

BOOL GetPoint( ksConicCurvePontIndexEnum PointIndex, double * X, double * Y );

Синтаксис COM:

HRESULT GetPoint( ksConicCurvePontIndexEnum PointIndex, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PointIndex | \- индекс точки из перечисления [ksConicCurvePontIndexEnum](ksconiccurvepontindexenum.html).  
---|---  
  
Выходные параметры:

X, Y | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
