# GetDimensionPoint - Получить координаты точек размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Контейнер ](bb2347717.html) > [Интерфейс IDimension2D ](idimension2d.html) > [IDimension2D - методы ](idimension2d_methods.html) |  Scroll [ [ [ ](idimension2d_gettextposition.html "К следующему разделу")](idimension2d_methods.html "На уровень выше")](idimension2d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimension2d.html)

Синтаксис Automation:

BOOL GetDimensionPoint( ksDimensionPointEnum DimensionPoint, long PointIndex, double * X, double * Y );

Синтаксис COM:

HRESULT GetDimensionPoint( ksDimensionPointEnum DimensionPoint, long PointIndex, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

DimensionPoint | \- тип точки из перечисления [ksDimensionPointEnum](ksdimensionpointenum.html),  
---|---  
PointIndex | \- координаты точки.  
  
Выходные параметры:

X,Y | \- координаты точки.  
---|---  
  
Версия Компас v21

Подразделы:

(отсутствуют)
