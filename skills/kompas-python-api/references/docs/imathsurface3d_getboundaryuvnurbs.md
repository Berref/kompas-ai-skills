# GetBoundaryUVNurbs - Получить параметры границы поверхности в UV NURBS-представлении

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getconeparam.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getareaex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetBoundaryUVNurbs( BOOL UV, BOOL Closed, long LoopIndex, long EdgeIndex,

long * Degree, VARIANT * Points, VARIANT * Weights, VARIANT * Knots, double *

TMin, double * TMax );

Синтаксис COM:

HRESULT GetBoundaryUVNurbs( BOOL UV, BOOL Closed, long LoopIndex, long EdgeIndex,

long * Degree, VARIANT * Points, VARIANT * Weights, VARIANT * Knots, double *

TMin, double * TMax, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UV | \- TRUE - получить параметры границы поверхности в UV- параметрическом представлении исходной поверхности, \- FALSE - получить параметры границы поверхности в 3D координатах,  
---|---  
Closed | \- TRUE - сомкнуть, если граница разомкнутая, \- FALSE - разомкнуть, если граница замкнутая,  
LoopIndex | \- индекс цикла,  
EdgeIndex | \- индекс ребра в цикле (совпадает с индексом ребра в коллекции ориентированных ребер).  
  
Выходные параметры:

Degree | \- порядок NURBS (степень полинома + 1), от 3 до 10,  
---|---  
Points | \- массив параметров UV или координат вершин - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
Weights | \- веса точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
Knots | \- узлы точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
TMin, TMax | \- минимальный и максимальный параметры.  
  
Примечание:

1\. Если признак UV равен TRUE, то в массиве points возвращаются параметры UV для Nurbs-представления границы. Параметры в массиве лежат в следующей последовательности:  
u0, v0, u1, v1, ... ui, vi.

2\. Если признак UV равен FALSE, то в массиве points возвращаются координаты вершин Nurbs-представления границы. Координаты точек в полученном массиве лежат в следующей последовательности:  
x0, y0, z0, x1, y1, z1, ...xi, yi, zi.

3\. Если индекс ребра равен -1, формируется Nurbs-представление контура границы.

4\. Если индекс >= 0 то формируется Nurbs-представление ребра, входящего в цикл, параметр unclamped при этом игнорируется.

Подразделы:

(отсутствуют)
