# SetPoint - Установить точку пересечения

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IConicCurve ](iconiccurve.html) > [IConicCurve - методы ](iconiccurve_methods.html) |  Scroll [ [ [ ](idrawingcontour.html "К следующему разделу")](iconiccurve_methods.html "На уровень выше")](iconiccurve_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurve.html)

Синтаксис Automation:

BOOL SetPoint( ksConicCurvePontIndexEnum PointIndex, double X, double Y );

Синтаксис COM:

HRESULT SetPoint( ksConicCurvePontIndexEnum PointIndex, double X, double Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

PointIndex | \- индекс точки из перечисления [ksConicCurvePontIndexEnum](ksconiccurvepontindexenum.html),  
---|---  
X, Y | \- координаты точки.  
  
Подразделы:

(отсутствуют)
