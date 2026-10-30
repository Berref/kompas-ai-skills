# NearPointProjection - Получить ближайшую проекцию точки на поверхность

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_pointprojection.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_neardirectpointprojection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL NearPointProjection( double X, double Y, double Z, double * ParamU, double * ParamV, BOOL Ext );

Синтаксис COM:

HRESULT NearPointProjection( double X, double Y, double Z, double * ParamU, double * ParamV, BOOL Ext, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- если проекция точки попала на саму поверхность или если ext равен TRUЕ,  
---|---  
FALSE | \- если проекция точки не попала на саму поверхность.  
  
Входные параметры:

X, Y, Z | \- координаты исходной пространственной точки,  
---|---  
Ext | \- если проекция точки вне поверхности; \- TRUE проецировать на продолжение поверхности, \- FALSE найти ближайшую граничную точку поверхности.  
  
Выходные параметры:

ParamU, ParamV | \- параметрические координаты точки на поверхности.  
---|---  
  
Подразделы:

(отсутствуют)
