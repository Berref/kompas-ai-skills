# GetCenterPoint - Угол вектора производной в указанной точке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - методы ](ispline3d_methods.html) |  Scroll [ [ [ ](ispline3d_getvector.html "К следующему разделу")](ispline3d_methods.html "На уровень выше")](ispline3d_flush.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Синтаксис Automation:

BOOL GetCenterPoint( long PointIndex, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetCenterPoint( long PointIndex, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

PointIndex | \- индекс точки.  
---|---  
  
Выходные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
