# SetBaseObjectPoint - Установить координаты точек базового объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс ILineSegmentAndPointDimension ](ilinesegmentandpointdimension.html) > [ILineSegmentAndPointDimension - методы ](ilinesegmentandpointdimension_methods.html) |  Scroll [ [ [ ](iradialdimension.html "К следующему разделу")](ilinesegmentandpointdimension_methods.html "На уровень выше")](ilinesegmentandpointdimension_setbaseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegmentandpointdimension.html)

Синтаксис Automation :

BOOL SetBaseObjectPoint( long PointIndex, double X, double Y );

Синтаксис COM :

HRESULT SetBaseObjectPoint( long PointIndex, double X, double Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PointIndex | \- индекс точки базового объекта,  
---|---  
X, Y | \- координаты точки.  
  
Подразделы:

(отсутствуют)
