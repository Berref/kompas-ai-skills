# GetGabarit - Получить габарит

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getmetriclength.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getedgescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2 );

Синтаксис COM:

HRESULT GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X1, Y1, Z1, X2, Y2, Z2 | \- координаты вершин габаритного параллелепипеда.  
---|---  
  
Примечание:

Координаты вершин параллелепипеда возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
