# SetPoint - Установить параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurface ](icloudpointssurface.html) > [ICloudPointsSurface - методы ](icloudpointssurface_methods.html) |  Scroll [ [ [ ](iconicsurface.html "К следующему разделу")](icloudpointssurface_methods.html "На уровень выше")](icloudpointssurface_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurface.html)

Синтаксис Automation:

BOOL SetPoint( long Index, double X, double Y, double Z );

Синтаксис COM:

HRESULT SetPoint( long Index, double X, double Y, double Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс точки,  
---|---  
X, Y, Z | \- координаты точки.  
  
Метод позволяет установить параметры точки.

Подразделы:

(отсутствуют)
