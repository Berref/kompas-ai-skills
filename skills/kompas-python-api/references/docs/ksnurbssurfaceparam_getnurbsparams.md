# GetNurbsParams - Получить параметры NURBS-поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_getperiodic.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_getminmaxparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

BOOL GetNurbsParams( BOOL unClampedV,

BOOL unClampedU,

long * degreeV,

long * degreeU,

long * nPV, long * nPU,

VARIANT * points,

VARIANT * weights,

VARIANT * knotsV,

VARIANT * knotsU );

Синтаксис COM:

BOOL GetNurbsParams( BOOL unClampedV,

BOOL unClampedU,

long * degreeV,

long * degreeU

long * nPV,

long * nPU,

VARIANT * points,

VARIANT * weights,

VARIANT * knotsV,

VARIANT * knotsU );

Входные параметры:

unClampedV | \- TRUE - вернуть параметры для замкнутого по V представления, \- FALSE - вернуть параметры для разомкнутого по V представления,  
---|---  
unClampedU | \- TRUE вернуть параметры для замкнутого по U представления, \- FALSE вернуть параметры для разомкнутого по U представления.  
  
Выходные параметры:

degreeV, degreeU | \- порядок NURBS (степень полинома + 1) по V и U, от 3 до 10,  
---|---  
nPV, nPU | \- количество точек по V и U,  
points | \- массив координат вершин - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
weights | \- веса в вершинах - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
knotsV, knotsU | \- узлы точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8.  
  
Подразделы:

(отсутствуют)
