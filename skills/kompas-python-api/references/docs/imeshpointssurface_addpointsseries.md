# AddPointsSeries - Добавить ряд точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_beginpointsseries.html "К следующему разделу")](bc2291576.html "На уровень выше")](imeshpointssurface_addpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](imeshpointssurface.html)

Синтаксис Automation:

BOOL AddPointsSeries( BOOL AddNewRow,

long IndexAt,

VARIANT Points,

VARIANT Weights );

Синтаксис COM:

HRESULT AddPointsSeries( BOOL AddNewRow,

long IndexAt,

VARIANT Points,

VARIANT Weights,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

AddNewRow | \- TRUE - добавить ряд, \- FALSE - добавить колонку,  
---|---  
IndexAt | \- индекс, перед которым нужно добавить ряд,  
Points | \- массив VT_ARRAY | VT_R8 координат точек,  
Weights | \- массив VT_ARRAY | VT_R8 весов точек.  
  
Подразделы:

(отсутствуют)
