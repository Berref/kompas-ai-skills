# BeginPointsSeries - Начать добавление нового ряда точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_clearpointsseries.html "К следующему разделу")](bc2291576.html "На уровень выше")](imeshpointssurface_addpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoint.html)

Синтаксис Automation:

BOOL BeginPointsSeries( BOOL AddNewRow,

long IndexAt );

Синтаксис COM:

HRESULT BeginPointsSeries( BOOLAddNewRow,

long IndexAt,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

AddNewRow | TRUE - добавлять ряд, FALSE - добавлять колонку,  
---|---  
IndexAt | \- индекс ряда, перед которым нужно добавить новый ряд.  
  
Подразделы:

(отсутствуют)
