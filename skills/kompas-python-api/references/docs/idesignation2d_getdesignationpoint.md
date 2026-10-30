# GetDesignationPoint - Получить координаты точек размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IDesignation2D ](idesignation2d.html) > [IDesignation2D - методы ](idesignation2d_methods.html) |  Scroll [ [ [ ](iassociationtable.html "К следующему разделу")](idesignation2d_methods.html "На уровень выше")](idesignation2d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idesignation2d.html)

Синтаксис Automation:

BOOL GetDesignationPoint( ksDesignationPointEnum DimensionPoint, long PointIndex, double * X, double * Y );

Синтаксис COM:

HRESULT GetDesignationPoint( ksDesignationPointEnum DimensionPoint, long PointIndex, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

DimensionPoint | \- тип точки из перечисления [ksDesignationPointEnum,](ksdesignationpointenum.html)  
---|---  
PointIndex | \- индекс точки.  
  
Выходные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Подразделы:

(отсутствуют)
