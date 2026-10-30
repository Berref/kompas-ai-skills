# AddPoints - Добавить точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurface ](icloudpointssurface.html) > [ICloudPointsSurface - методы ](icloudpointssurface_methods.html) |  Scroll [ [ [ ](icloudpointssurface_clearpoints.html "К следующему разделу")](icloudpointssurface_methods.html "На уровень выше")](icloudpointssurface_addpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurface.html)

Синтаксис Automation:

BOOL AddPoints( VARIANT Points );

Синтаксис COM:

HRESULT AddPoints( VARIANT Points,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Points: массив VT_ARRAY | VT_R8 координат точек

Подразделы:

(отсутствуют)
