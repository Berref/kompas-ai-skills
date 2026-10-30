# GetTrianglePoint - Получить точки треугольников, в которые вписаны начало и конец поверхности конического сечения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IConicSurface](iconicsurface.html) > [IConicSurface - методы](iconicsurface_methods.html) |  Scroll [ [ [ ](iequidistantsurface.html "К следующему разделу")](iconicsurface_methods.html "На уровень выше")](iconicsurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconicsurface.html)

Синтаксис Automation:

BOOL GetTrianglePoint( BOOL BeginSide, ksConicSectionTrianglePointEnum PointIndex, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetTrianglePoint( BOOL BeginSide, ksConicSectionTrianglePointEnum PointIndex, double * X, double * Y, double * Z, BOOL * Result );

Входные параметры:

BeginSide | \- TRUE - начальная сторона, \- FALSE - конечная сторона,  
---|---  
PointIndex | \- индекс точки из перечисления [ksConicSectionTrianglePointEnum](ksconicsectiontrianglepointenum.html).  
  
Выходные параметры:

X, Y, Z | \- координаты точки,  
---|---  
  
Подразделы:

(отсутствуют)
