# CurveIntersection - Расчет пересечений c кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getarea.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL CurveIntersection( IMathCurve3D * Curve, BOOL ExtensionSurface, BOOL ExtensionCurve, VARIANT * Points );

Синтаксис COM:

HRESULT CurveIntersection( IMathCurve3D * Curve, BOOL ExtensionSurface, BOOL ExtensionCurve, VARIANT * Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Curve | \- указатель на кривую [IMathCurve3D](imathcurve3d.html),  
---|---  
ExtensionSurface | \- учитывать продолжение поверхности,  
ExtensionCurve |  \- учитывать продолжение кривой.  
  
Выходные параметры:

Points | \- координаты точек пересечений.  
---|---  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
