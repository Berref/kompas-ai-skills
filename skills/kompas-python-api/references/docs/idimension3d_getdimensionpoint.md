# GetDimensionPoint - Получить координаты точек размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IDimension3D ](idimension3d.html) > [IDimension3D - методы ](idimension3d_methods.html) |  Scroll [ [ [ ](idimension3d_gettextposition.html "К следующему разделу")](idimension3d_methods.html "На уровень выше")](idimension3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimension3d.html)

Синтаксис Automation:

BOOL GetDimensionPoint( ksDimensionPointEnum DimensionPoint, long PointIndex, double * X, double * Y, double * Z );

Синтаксис COM :

HRESULT GetDimensionPoint( ksDimensionPointEnum DimensionPoint, long PointIndex, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

DimensionPoint | \- тип точки из перечисления [ksDimensionPointEnum](ksdimensionpointenum.html),  
---|---  
PointIndex | \- координаты точки.  
  
Выходные параметры:

X,Y, Z | \- координаты точки.  
---|---  
  
Версия Компас v21

Подразделы:

(отсутствуют)
