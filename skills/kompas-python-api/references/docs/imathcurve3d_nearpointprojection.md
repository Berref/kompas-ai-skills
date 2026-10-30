# NearPointProjection - Получить ближайшую проекцию точки на кривую

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelCurve3D ](imodelcurve3d.html) > [Интерфейс IMathCurve3D ](imathcurve3d.html) > [IMathCurve3D - методы ](imathcurve3d_metods.html) |  Scroll [ [ [ ](bc2229904.html "К следующему разделу")](imathcurve3d_metods.html "На уровень выше")](imathcurve3d_gettangentvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathcurve3d.html)

Синтаксис Automation:

BOOL NearPointProjection( double X, double Y, double Z, double * T, BOOL Ext );

Синтаксис COM:

HRESULT NearPointProjection( double X, double Y, double Z, double * T, BOOL Ext, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты исходной пространственной точки,  
---|---  
Ext | \- если проекция точки вне кривой,  
TRUE | \- проецировать на продолжение кривой,  
FALSE | \- найти ближайшую граничную точку кривой. Если проекция точки внутри кривой, значение этого параметра не учитывается.  
  
Выходные параметры:

T | \- параметрические координаты точки на кривой.  
---|---  
  
Подразделы:

(отсутствуют)
