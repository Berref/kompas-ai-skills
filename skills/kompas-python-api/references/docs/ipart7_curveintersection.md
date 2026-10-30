# CurveIntersection - Расчет пересечений c кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_destroysubassembly.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_changeobjectlinks.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL CurveIntersection( IMathCurve3D * Curve, VARIANT * Faces, VARIANT * Points );

Синтаксис COM:

HRESULT CurveIntersection( IMathCurve3D * Curve, VARIANT * Faces, VARIANT * Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Curve | \- Указатель на математическую кривую [IMathCurve3D](imathcurve3d.html).  
---|---  
  
Выходные параметры:

Faces | \- список граней, пересекаемых кривой VT_APPAY | VT_DISPATCH,  
---|---  
Points | \- координаты точек пересечения VT_APPAY | VT_R8.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
