# DeletePointsSeries - Удалить ряд точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_endpointsseries.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_clearpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL DeletePointsSeries( BOOL UV,

long Index );

Синтаксис COM:

HRESULT DeletePointsSeries( BOOL UV,

long Index,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UV | \- TRUE - удалять по U, \- FALSE - по V,  
---|---  
Index | \- индекс удаляемого ряда.  
  
Подразделы:

(отсутствуют)
