# GetPoint - Получить координаты точки

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZoneParametersByBorderPoints ](izoneparametersbyborderpoints.html) > [IZoneParametersByBorderPoints - методы ](izoneparametersbyborderpoints_methods.html) |  Scroll [ [ [ ](izoneparametersbyborderpoints_setpoint.html "К следующему разделу")](izoneparametersbyborderpoints_methods.html "На уровень выше")](izoneparametersbyborderpoints_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izoneparametersbyborderpoints.html)

Синтаксис Automation:

BOOL GetPoint( BOOL First, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( BOOL First, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

First | \- TRUE - первая вершина, \- FALSE - вторая вершина.  
---|---  
  
Выходные параметры:

X, Y, Z | \- Координаты вершины.  
---|---  
  
Подразделы:

(отсутствуют)
