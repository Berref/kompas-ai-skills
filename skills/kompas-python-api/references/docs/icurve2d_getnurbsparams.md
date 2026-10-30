# GetNurbsParams - Получить параметры в NURBS-представлении

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_getpointlocation.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_getmetriclength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL GetNurbsParams( BOOL UnClamped,

VARIANT * Points,

VARIANT * Weights,

VARIANT * Knots,

double * TMin,

double * TMax );

Синтаксис COM:

HRESULT GetNurbsParams( BOOL UnClamped,

VARIANT * Points,

VARIANT * Weights,

VARIANT * Knots,

double * TMin,

double * TMax,

BOOL * Result );

Входные параметры:

UnClamped | \- TRUE - вернуть параметры точек для замкнутого представления, \- FALSE - вернуть параметры точек для разомкнутого представления.  
---|---  
  
Выходные параметры:

Points | \- SAFEARRAY координат точек VT_ARRAY | VT_R8,  
---|---  
Weights | \- SAFEARRAY весов точек VT_ARRAY | VT_R8,  
Knots | \- SAFEARRAY узлов точек VT_ARRAY | VT_R8,  
TMin | \- минимальный параметр кривой,  
TMax | \- максимальный параметр кривой.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить параметры кривой в NURBS-представлении.

Подразделы:

(отсутствуют)
