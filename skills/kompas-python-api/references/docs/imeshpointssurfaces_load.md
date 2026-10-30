# Load - Прочитать поверхность из файла

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurfaces ](imeshpointssurfaces.html) > [IMeshPointsSurfaces - методы ](imeshpointssurfaces_methods.html) |  Scroll [ [ [ ](inurbssurfaces.html "К следующему разделу")](imeshpointssurfaces_methods.html "На уровень выше")](imeshpointssurfaces_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imeshpointssurfaces.html)

Синтаксис Automation:

LPDISPATCH Load( BSTR FileName );

Синтаксис COM:

HRESULT Load( BSTR FileName, IMeshPointsSurface ** Result );

Возвращаемое значение:

Указатель на интерфейс поверхности по сети точек [IMeshPointsSurface](imeshpointssurface.html).

Входные параметры:

FileName - имя файла.

Метод позволяет создать поверхность по координатам точек, загруженным из файла.

Подразделы:

(отсутствуют)
