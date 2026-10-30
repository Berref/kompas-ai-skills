# SetEdgePointParam - Изменение положения точки ребра линейчатой поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - методы ](iruledsurface_methods.html) |  Scroll [ [ [ ](iruledsurfacemovement.html "К следующему разделу")](iruledsurface_methods.html "На уровень выше")](iruledsurface_getedgepointparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iruledsurface.html)

Синтаксис Automation:

BOOL SetEdgePointParam( long EdgeIndex,

BOOL StartPoint,

double X,

double Y,

double Z,

double * T,

IModelObject * Segment,

IModelObject * AssociateVertex );

Синтаксис COM:

HRESULT SetEdgePointParam( long EdgeIndex,

BOOL StartPoint,

double X,

double Y,

double Z,

double * T,

IModelObject * Segment,

IModelObject * AssociateVertex,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

EdgeIndex | \- индекс ребра,  
---|---  
StartPoint | \- начальная или конечная вершина ребра,  
X, Y, Z | \- координаты точки,  
T | \- параметр точки на кривой,  
Segment | \- сегмент направляющей, на котором находится точка,  
AssociateVertex | \- вершина направляющей, с которой связана вершина ребра.  
  
Метод позволяет задать положение вершины ребра линейчатой поверхности на направляющей.

Подразделы:

(отсутствуют)
