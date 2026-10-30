# GetSelfIntersectPointsEx - Получить точки самопересечения

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_intersect.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_getselfintersectpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL GetSelfIntersectPointsEx( double Epsilon, VARIANT * Points, VARIANT * T, VARIANT * IntersectForms );

Синтаксис COM:

HRESULT GetSelfIntersectPointsEx( double Epsilon, VARIANT * Points, VARIANT * T, VARIANT *IntersectForms, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Epsilon | \- погрешность вычисления.  
---|---  
  
Выходные параметры:

Points | \- массив SAFEARRAY точек VT_ARRAY | VT_R8,  
---|---  
T | \- массив SAFEARRAY параметров кривой VT_ARRAY | VT_R8,  
IntersectForms | \- массив SAFEARRAY типов самопересечения из перечисления [ksCurvesIntersectFormEnum](kscurvesintectformenum.html) VT_ARRAY | VT_I4.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
