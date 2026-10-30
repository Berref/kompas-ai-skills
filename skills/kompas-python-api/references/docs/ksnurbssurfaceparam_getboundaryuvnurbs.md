# GetBoundaryUVNurbs - Получить параметры NURBS-представления границы поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_getclose.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

BOOL GetBoundaryUVNurbs (BOOL uv,

BOOL closed,

long loopIndex,

long * degree,

long edgeIndex,

VARIANT * points,

VARIANT * weights,

VARIANT * knots,

double * tMin,

double * tMax)

Синтаксис COM:

BOOL GetBoundaryUVNurbs (BOOL uv,

BOOL closed,

long loopIndex,

long edgeIndex,

long * degree,

VARIANT * points,

VARIANT * weights,

VARIANT * knots,

double * tMin,

double * tMax)

Входные параметры:

Uv | \- TRUE - получить параметры границы поверхности в UV- параметрическом представлении исходной поверхности, \- FALSE - получить параметры границы поверхности в 3D координатах,  
---|---  
Closed | \- TRUE - сомкнуть, если граница разомкнутая, \- FALSE - разомкнуть, если граница замкнутая,  
loopIndex | \- индекс цикла,  
edgeIndex | \- индекс ребра в цикле (совпадает с индексом ребра в коллекции ориентированных ребер).  
  
Выходные параметры:

degree | \- порядок NURBS (степень полинома + 1), от 3 до 10,  
---|---  
points | \- массив параметров UV или координат вершин - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
weights | \- веса точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
knots | \- узлы точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
tMin, tMax | \- минимальный и максимальный параметры.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

•Если признак UV равен TRUE, то в массиве points возвращаются параметры UV для Nurbs-представления границы. Параметры в массиве лежат в следующей последовательности:

u0, v0, u1, v1, ... ui, vi.

•Если признак UV равен FALSE, то в массиве points возвращаются координаты вершин Nurbs-представления границы. Координаты точек в полученном массиве лежат в следующей последовательности:

x0, y0, z0, x1, y1, z1, ...xi, yi, zi.

•Если индекс ребра равен -1, формируется Nurbs-представление контура границы.

•Если индекс >= 0, то формируется Nurbs-представление ребра, входящего в цикл; параметр unclamped при этом игнорируется.

Подразделы:

(отсутствуют)
