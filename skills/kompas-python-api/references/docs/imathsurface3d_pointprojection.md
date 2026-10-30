# PointProjection - Проекция точки на поверхность

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](isurfacecontainer.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_nearpointprojection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation :

VARIANT PointProjection( double X, double Y, double Z, double VX, double VY, double VZ, BOOL Extended );

Синтаксис COM:

HRESULT PointProjection( double X, double Y, double Z, double VX, double VY, double VZ, BOOL Extended, VARIANT * Result );

Возвращаемое значение:

| Массив Safearray VT_ARRAY | VT_R8 параметрических координат точек поверхности в последовательности U1, V1, U2, V2....  
---|---  
  
Входные параметры:

X, Y, Z | \- координаты точки,  
---|---  
VX, VY, VZ | \- направление вектора,  
Extended | \- TRUE - учитывать продолжение.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
