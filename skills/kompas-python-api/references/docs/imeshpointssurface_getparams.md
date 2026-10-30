# GetParams - Получить параметры поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_getpoint.html "К следующему разделу")](bc2291576.html "На уровень выше")](imeshpointssurface_endpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](imeshpointssurface.html)

Синтаксис Automation:

BOOL GetParams( BOOL * ClosedV,

BOOL * ClosedU,

long * DegreeV,

long * DegreeU,

long * PointsVCount,

long * PointsUCount,

VARIANT * Points,

VARIANT * Weights );

Синтаксис COM:

HRESULT GetParams( BOOL * ClosedV,

BOOL * ClosedU,

long * DegreeV,

long * DegreeU,

long * PointsVCount,

long * PointsUCount,

VARIANT * Points,

VARIANT * Weights,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

ClosedV | признак замкнутости поверхности по V,  
---|---  
ClosedU | признак замкнутости поверхности по U,  
DegreeV | порядок сплайна по V,  
DegreeU | порядок сплайна по U,  
PointsVCount | количество точек по V,  
PointsUCount | количество точек по U,  
Points | массив VT_ARRAY | VT_R8 координат точек,  
Weights | массив VT_ARRAY | VT_R8 весов точек.  
  
Подразделы:

(отсутствуют)
