# DeletePointsSeries - Удалить ряд точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_endpointsseries.html "К следующему разделу")](bc2291576.html "На уровень выше")](imeshpointssurface_clearpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](imeshpointssurface.html)

Синтаксис Automation:

BOOL DeletePointsSeries( BOOL DeleteRow,

long Index );

Синтаксис COM:

HRESULT DeletePointsSeries(BOOL DeleteRow,

long Index,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

DeleteRow | \- TRUE - удаляется ряд, \- FALSE - удаляется колонка,  
---|---  
Index | \- индекс удаляемого ряда.  
  
Подразделы:

(отсутствуют)
