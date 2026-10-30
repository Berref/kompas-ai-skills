# GetPoint3D - Получить пространственную точку по точке на плоскости xy

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](iplacement3d_getpointprojectiontoxy.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_getvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL GetPoint3D( double XIn, double YIn, double * XOut, double * YOut, double * ZOut );

Синтаксис COM:

HRESULT GetPoint3D( double XIn, double YIn, double * XOut, double * YOut, double * ZOut, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

XIn | \- координата по X на плоскости XY,  
---|---  
YIn | \- координата по Y на плоскости XY.  
  
Выходные параметры

YIn | \- координата по X в пространстве,  
---|---  
YOut | \- координата по Y в пространстве,  
ZOut | \- координата по Z в пространстве.  
  
Подразделы:

(отсутствуют)
