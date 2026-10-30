# BeginPointsSeries - Начать добавление нового ряда точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_clearpointsseries.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_addpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL BeginPointsSeries( BOOL UV,

long IndexAt );

Синтаксис COM:

HRESULT BeginPointsSeries( BOOL UV,

long IndexAt,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UV | \- TRUE - добавлять по U, \- FALSE - по V,  
---|---  
IndexAt | \- индекс ряда, перед которым добавлять новый ряд.  
  
Подразделы:

(отсутствуют)
