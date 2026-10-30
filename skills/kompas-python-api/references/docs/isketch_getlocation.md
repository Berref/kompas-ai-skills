# GetLocation - Получить смещение системы координат эскиза относительно проекции системы координат модели на плоскость эскиза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_getloftpoint.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_endedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL GetLocation( double X, double Y);

Синтаксис COM:

HRESULT GetLocation([out] double * X, [out] double * Y, [out, retval] VARIANT_BOOL * PVal);

Выходные параметры:

X | \- смещение системы координат эскиза по оси X,  
---|---  
Y | \- смещение системы координат эскиза по оси Y.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
