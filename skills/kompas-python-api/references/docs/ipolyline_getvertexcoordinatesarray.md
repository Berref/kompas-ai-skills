# GetVertexCoordinatesArray - Получить массив координат и радиусов вершин в виде SAFEARRAY double - VT_ARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - методы ](ipolyline_methods.html) |  Scroll [ [ [ ](ipolyline_readfromfile.html "К следующему разделу")](ipolyline_methods.html "На уровень выше")](ipolyline_flush.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Синтаксис Automation:

BOOL GetVertexCoordinatesArray( VARIANT * Coordinates,

VARIANT * Radiuses );

Синтаксис COM:

HRESULT GetVertexCoordinatesArray([out] VARIANT * Coordinates,

[out] VARIANT * Radiuses,

[out, retval] VARIANT_BOOL * Result);

Входные параметры:

Coordinates | \- массив SafeArray типа VT_ARRAY | VT_R8 координат точек всех вершин,  
---|---  
Radiuses | \- массив SafeArray типа VT_ARRAY | VT_R8 радиусов при вершинах кривой.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

1\. Параметры Coordinates и Radiuses не являются обязательными. В функцию достаточно передать один из указателей на VARIANT.

2\. Массивы являются согласованными:

Координаты точек в массиве Coordinates лежат в следующей последовательности:  
x0, y0, z0, x1, y1, z1 ...xi, yi, zi,

Радиусы при вершинах кривой в массиве Radiuses лежат в последовательности:  
radius0, radius1, ...radiusi.

Подразделы:

(отсутствуют)
