# GetPointProjectionToXY - Проекция точки на плоскость XY

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_getpoint3d.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_getloftpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL GetPointProjectionToXY( double XIn, double YIn, double ZIn, double * XOut, double * YOut );

Синтаксис COM:

HRESULT GetPointProjectionToXY( double XIn, double YIn, double ZIn, double * XOut, double * YOut, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

XIn, YIn, ZIn | \- координаты 3D точки.  
---|---  
  
Выходные параметры:

XOut, YOut | \- координаты проекционной точки.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
