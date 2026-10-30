# GetNurbsParams - Получить параметры NURBS-поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс INurbsSurface ](inurbssurface.html) > [INurbsSurface - методы ](inurbssurface_methods.html) |  Scroll [ [ [ ](inurbssurface_initparambyface.html "К следующему разделу")](inurbssurface_methods.html "На уровень выше")](inurbssurface_getboundary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbssurface.html)

Синтаксис Automation:

BOOL GetNurbsParams( BOOL ClosedV, BOOL ClosedU,

long * DegreeV, long * DegreeU, long * NPV, long * NPU,

VARIANT * Points, VARIANT * Weights, VARIANT * KnotsV, VARIANT * KnotsU );

Синтаксис COM:

HRESULT GetNurbsParams( BOOL ClosedV, BOOL ClosedU,

long * DegreeV, long * DegreeU, long * NPV, long * NPU,

VARIANT * Points, VARIANT * Weights, VARIANT * KnotsV, VARIANT * KnotsU, BOOL * Res );

Выходные параметры:

ClosedV | \- TRUE - получение параметров для замкнутого по V представления, \- FALSE - получение параметров для разомкнутого по V представления,  
---|---  
ClosedU | \- TRUE - получение параметров для замкнутого по U представления, \- FALSE - получение параметров для разомкнутого по U представления.  
  
Входные параметры:

DegreeV | \- порядок NURBS по V (степень полинома + 1), от 3 до 10,  
---|---  
DegreeU | \- порядок NURBS по U (степень полинома + 1), от 3 до 10,  
NPV | \- количество точек по V,  
NPU | \- количество точек по U,  
Points | \- массив SafeArray точек VT_ARRAY | VT_R8,  
Weights | \- веса,  
KnotsV | \- массив SafeArray узлов точек по V VT_ARRAY | VT_R8,  
KnotsU | \- массив SafeArray узлов точек по U VT_ARRAY | VT_R8.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Подразделы:

(отсутствуют)
