# GetCurve2CutPoint - Приближенная точка начала скругления на кривой 2

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IFilletCurve ](ifilletcurve.html) > [IFilletCurve - методы ](ifilletcurve_methods.html) |  Scroll [ [ [ ](ifilletcurve_setcurve1cutpoint.html "К следующему разделу")](ifilletcurve_methods.html "На уровень выше")](ifilletcurve_getcurve1cutpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifilletcurve.html)

Синтаксис Automation:

BOOL GetCurve2CutPoint( double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetCurve2CutPoint( double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X, Y, Z - координаты точки.

Подразделы:

(отсутствуют)
