# Load - Прочитать точки поверхности из файла

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurfaces ](icloudpointssurfaces.html) > [ICloudPointsSurfaces - методы ](icloudpointssurfaces_methods.html) |  Scroll [ [ [ ](iconicsurfaces.html "К следующему разделу")](icloudpointssurfaces_methods.html "На уровень выше")](icloudpointssurfaces_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurfaces.html)

Синтаксис Automation:

LPDISPATCH Load( BSTR FileName );

Синтаксис COM:

HRESULT Load( BSTR FileName, ICloudPointsSurface ** Result );

Возвращаемое значение:

Указатель на интерфейс поверхности по облаку точек [ICloudPointsSurface](icloudpointssurface.html)

Входные параметры:

FileName - имя файла

Метод позволяет создать поверхность по координатам точек, загруженным из файла.

Подразделы:

(отсутствуют)
