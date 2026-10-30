# GetVertexCoordinatesArray - Получить массив координат и весов вершин в виде SAFEARRAY double - VT_ARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - методы ](ispline3d_methods.html) |  Scroll [ [ [ ](ispline3d_invertvector.html "К следующему разделу")](ispline3d_methods.html "На уровень выше")](ispline3d_getvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Синтаксис Automation:

BOOL GetVertexCoordinatesArray( VARIANT * Coordinates,

VARIANT * Weights );

Синтаксис COM:

HRESULT GetVertexCoordinatesArray([out] VARIANT * Coordinates,

[out] VARIANT * Weights,

[out, retval] VARIANT_BOOL * Result);

Входные параметры:

Coordinates | \- массив SafeArray типа VT_ARRAY | VT_R8 координат точек всех вершин,  
---|---  
Weights | \- массив SafeArray типа VT_ARRAY | VT_R8 весов каждой из всех вершин.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

1\. Параметры Coordinates и Weights не являются обязательными. В функцию достаточно передать один из указателей на VARIANT.

2\. Массивы являются согласованными:

Координаты точек в массиве Coordinates лежат в следующей последовательности:  
x0, y0, z0, x1, y1, z1 ...xi, yi, zi,

Веса точек в массиве Weights лежат в последовательности:  
weight0, weight1, ...weighti.

Подразделы:

(отсутствуют)
