# GetPoint - Получить параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurface ](icloudpointssurface.html) > [ICloudPointsSurface - методы ](icloudpointssurface_methods.html) |  Scroll [ [ [ ](icloudpointssurface_setpoint.html "К следующему разделу")](icloudpointssurface_methods.html "На уровень выше")](icloudpointssurface_deletepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurface.html)

Синтаксис Automation:

BOOL GetPoint( long Index,

double * X,

double * Y,

double * Z );

Синтаксис COM:

HRESULT GetPoint( long Index,

double * X,

double * Y,

double * Z,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index - индекс точки

Выходные параметры:

X, Y, Z - координаты точки

Метод позволяет получить координаты точки.

Подразделы:

(отсутствуют)
