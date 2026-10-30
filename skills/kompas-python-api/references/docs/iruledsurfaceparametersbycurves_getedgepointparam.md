# GetEdgePointParam - Получение параметров точки ребра

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurfaceParametersByCurves](iruledsurfaceparametersbycurves.html) > [IRuledSurfaceParametersByCurves - методы](iruledsurfaceparametersbycurves_methods.html) |  Scroll [ [ [ ](iruledsurfaceparametersbycurves_getedgepointparams.html "К следующему разделу")](iruledsurfaceparametersbycurves_methods.html "На уровень выше")](iruledsurfaceparametersbycurves_deleteedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iruledsurfaceparametersbycurves.html)

Синтаксис Automation:

BOOL GetEdgePointParam( long EdgeIndex, BOOL StartPoint, double * X, double * Y, double * Z, double * T, IModelObject * * Segment, IModelObject * * AssociateVertex );

Синтаксис COM:

HRESULT GetEdgePointParam( long EdgeIndex, BOOL StartPoint, double * X, double * Y, double * Z, double * T, IModelObject * * Segment, IModelObject * * AssociateVertex, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

EdgeIndex | \- индекс ребра,  
---|---  
StartPoint | \- признак начала ребра.  
  
Выходные параметры

StartPoint | \- признак начала ребра,  
---|---  
X, Y, Z | \- новые координаты точки,  
T | \- параметр кривой,  
Segment | \- сегмент кривой [IModelObject](imodelobject.html),  
AssociateVertex | \- ассоциативная вершина [IModelObject](imodelobject.html).  
  
Подразделы:

(отсутствуют)
