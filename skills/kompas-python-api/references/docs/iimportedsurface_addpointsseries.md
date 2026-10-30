# AddPointsSeries - Добавить ряд точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_beginpointsseries.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_addpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL AddPointsSeries( BOOL UV,

long IndexAt,

VARIANT arr );

Синтаксис COM:

HRESULT AddPointsSeries( BOOL UV,

long IndexAt,

VARIANT arr,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Возвращаемое значение:

UV | \- TRUE - добавлять по U, FALSE - по V,  
---|---  
IndexAt | \- индекс, перед которым добавлять,  
arr | \- массив VT_ARRAY | VT_R8 координат точек.  
  
Подразделы:

(отсутствуют)
