# NearDirectPointProjection - Проекция точки на кривую

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_nearpointprojection.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_gettorusparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL NearDirectPointProjection( double X, double Y, double Z, double VX, double VY, double VZ, BOOL Extended, double * U, double * V );

Синтаксис COM:

HRESULT NearDirectPointProjection( double X, double Y, double Z, double VX, double VY, double VZ, BOOL Extended, double * U, double * V, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки,  
---|---  
VX, VY, VZ | \- направление вектора,  
Extended | \- TRUE - учитывать продолжение.  
  
Выходные параметры:

U, V | \- параметрические координаты точки на поверхности.  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
