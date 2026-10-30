# GetArea - Получить площадь грани (ST_MIX_MM..ST_MIX_M единицы измерения)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getareaex.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_curveintersection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

double GetArea( ksLengthUnitsEnum BitVector );

Синтаксис COM:

HRESULT GetArea( ksLengthUnitsEnum BitVector, double * Result ) ;

Возвращаемое значение:

| \- площадь поверхности.  
---|---  
  
Входные параметры:

BitVector | \- единицы измерения в интервале [ST_MIX_MM..ST_MIX_M].  
---|---  
  
Подразделы:

(отсутствуют)
