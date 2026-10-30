# GetDesignationPoint - Получить координаты точек размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IDesignation3D ](idesignation3d.html) > [IDesignation3D - методы ](idesignation3d_methods.html) |  Scroll [ [ [ ](ibases3d.html "К следующему разделу")](idesignation3d_methods.html "На уровень выше")](idesignation3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idesignation3d.html)

Синтаксис Automation:

BOOL GetDesignationPoint( ksDesignationPointEnum DimensionPoint, long PointIndex, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetDesignationPoint( ksDesignationPointEnum DimensionPoint, long PointIndex, double * X, double * Y, double * Z, BOOL * Result );

Входные параметры:

DimensionPoint | \- тип точки из перечисления [ksDesignationPointEnum,](ksdesignationpointenum.html)  
---|---  
PointIndex | \- индекс точки.  
  
Выходные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
