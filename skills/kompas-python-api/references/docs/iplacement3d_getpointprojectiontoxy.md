# GetPointProjectionToXY - Проекция точки на плоскость xy

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](iplacement3d_initbymatrix3d.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_getpoint3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL GetPointProjectionToXY( double XIn, double YIn, double ZIn, double * XOut, double * YOut );

Синтаксис COM:

HRESULT GetPointProjectionToXY( double XIn, double YIn, double ZIn, double * XOut, double * YOut, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

X | \- координата точки по X,  
---|---  
Y | \- координата точки по Y,  
Z | \- координата точки по Z.  
  
Выходные параметры

XOut | \- координата по X на плоскости XY,  
---|---  
YOut | \- координата по Y на плоскости XY.  
  
Подразделы:

(отсутствуют)
