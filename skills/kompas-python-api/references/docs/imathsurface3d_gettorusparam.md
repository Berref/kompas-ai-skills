# GetTorusParam - Получить параметры тора

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_neardirectpointprojection.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_gettangentvectorv.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetTorusParam( double * Radius, double * GeneratrixRadius );

Синтаксис COM:

RESULT GetTorusParam( double * Radius, double * GeneratrixRadius, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Radius | \- Радиус,  
---|---  
GeneratrixRadius | \- Радиус образующей.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
