# IntersectEx - Пересечение двух кривых

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_movepoint.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_intersect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL IntersectEx( ICurve2D * Curve2, double Epsilon, BOOL TouchInclude, VARIANT * Points, VARIANT * T1, VARIANT * T2, VARIANT *IntersectForms );

Синтаксис COM:

HRESULT IntersectEx( ICurve2D * Curve2, double Epsilon, BOOL TouchInclude, VARIANT * Points, VARIANT * T1, VARIANT * T2, VARIANT * IntersectForms, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Curve2 | \- вторая кривая [ICurve2D](icurve2d.html),  
---|---  
Epsilon | \- погрешность вычисления,  
TouchInclude | \- возвращать точки касания.  
  
Выходные параметры:

Points | \- массив SAFEARRAY точек VT_ARRAY | VT_R8,  
---|---  
T1 | \- массив SAFEARRAY параметров для первой кривой VT_ARRAY | VT_R8,  
T2 | \- массив SAFEARRAY параметров для первой кривой VT_ARRAY | VT_R8,  
IntersectForms | \- массив SAFEARRAY типов самопересечения из перечисления [ksCurvesIntersectFormEnum](kscurvesintectformenum.html) VT_ARRAY | VT_I4.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
