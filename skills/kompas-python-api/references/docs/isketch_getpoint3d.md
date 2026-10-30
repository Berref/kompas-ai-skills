# GetPoint3D - Получить пространственную точку по точке на плоскости XY

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_rotateaxis.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_getpointprojectiontoxy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL GetPoint3D( double XIn, double YIn, double * XOut, double * YOut, double * ZOut );

Синтаксис COM:

HRESULT GetPoint3D( double XIn, double YIn, double * XOut, double * YOut, double * ZOut, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

XIn, YIn | \- координаты эскиза.  
---|---  
  
Выходные параметры:

XIn, YIn, ZIn | \- координаты 3D точки.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
