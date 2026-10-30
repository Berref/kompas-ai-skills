# GetLoftPoint - Получить координаты точки в плоскости эскиза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_getpointprojectiontoxy.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_getlocation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL GetLoftPoint( double X, double Y);

Синтаксис COM:

HRESULT GetLoftPoint([out] double * X, [out] double * Y, [out, retval] VARIANT_BOOL * PVal);

Выходные параметры:

X | \- значение координаты точки по оси X,  
---|---  
Y | \- значение координаты точки по оси Y.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
