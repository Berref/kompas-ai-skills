# GetNurbsParams - Получить параметры Nurbs-поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getpoint.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetNurbsParams( BOOL ClosedV, BOOL ClosedU, long * DegreeV, long * DegreeU, long * NPV, long * NPU, VARIANT * Points, VARIANT * Weights, VARIANT * KnotsV, VARIANT * KnotsU );

Синтаксис COM:

HRESULT GetNurbsParams( BOOL ClosedV, BOOL ClosedU, long * DegreeV, long * DegreeU, long * NPV, long * NPU, VARIANT * Points, VARIANT * Weights, VARIANT * KnotsV, VARIANT * KnotsU, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ClosedV | \- TRUE - получение параметров для замкнутого по V представления, FALSE - получение параметров для разомкнутого по V представления,  
---|---  
ClosedU |  TRUE - получение параметров для замкнутого по V представления, FALSE - получение параметров для разомкнутого по V представления.  
  
Выходные параметры:

DegreeV | \- порядок NURBS по V (степень полинома + 1), от 3 до 10,  
---|---  
DegreeU | \- порядок NURBS по U (степень полинома + 1), от 3 до 10  
NPV | \- количество точек по V,  
NPU | \- количество точек по U,  
Points | \- массив SafeArray точек VT_ARRAY | VT_R8,  
Weights | \- веса,  
KnotsV | \- массив SafeArray узлов точек по V VT_ARRAY | VT_R8,  
KnotsU | \- массив SafeArray узлов точек по U VT_ARRAY | VT_R8.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
