# Load - Прочитать поверхность из файла

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurfaces ](iimportedsurfaces.html) > [IImportedSurfaces - методы ](iimportedsurfaces_methods.html) |  Scroll [ [ [ ](imeshpointssurfaces.html "К следующему разделу")](iimportedsurfaces_methods.html "На уровень выше")](iimportedsurfaces_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurfaces.html)

Синтаксис Automation:

VARIANT Load( BSTR FileName,

BOOL SewSurfaces );

Синтаксис COM:

HRESULT Load( BSTR FileName,

BOOL SewSurfaces,

VARIANT * Result );

Возвращаемое значение:

Массив VT_ARRAY | VT_DISPATCH поверхностей;

Входные параметры:

FileName | \- имя файла,  
---|---  
SewSurfaces | \- сшивать поверхности.  
  
Метод позволяет загрузить поверхности из файла .igs или .sat.

Подразделы:

(отсутствуют)
