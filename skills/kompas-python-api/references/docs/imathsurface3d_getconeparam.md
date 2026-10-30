# GetConeParam - Получить параметры конической поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getderivativeu.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getboundaryuvnurbs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetConeParam( double * Height, double * Angle, double * Radius );

Синтаксис COM:

HRESULT GetConeParam( double * Height, double * Angle, double * Radius, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Height | \- Высота,  
---|---  
Angle | \- Угол,  
Radius | \- Радиус.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
