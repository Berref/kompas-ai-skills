# CurveIntersection - Расчет пересечений c кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Твердое тело ](bc2297187.html) > [Интерфейс IBody7 ](ibody7.html) > [IBody7 - методы ](ibody7_methods.html) |  Scroll [ [ [ ](ibody7_getgabarit.html "К следующему разделу")](ibody7_methods.html "На уровень выше")](ibody7_checkintersectionwithbodyex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibody7.html)

Синтаксис Automation:

BOOL CurveIntersection( IMathCurve3D * Curve, VARIANT * Faces, VARIANT * Points );

Синтаксис COM:

HRESULT CurveIntersection( IMathCurve3D * Curve, VARIANT * Faces, VARIANT * Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Curve | \- Указатель на математическую кривую I[MathCurve3D](imathcurve3d.html).  
---|---  
  
Выходные параметры:

Faces | \- список граней, пересекаемых кривой VT_APPAY | VT_DISPATCH,  
---|---  
Points | \- координаты точек пересечения VT_APPAY | VT_R8.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
