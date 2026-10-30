# GetPoint - Получить параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_getpoints.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_endpointsseries.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL GetPoint( long UIndex,

long VIndex,

double * X,

double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( long UIndex,

long VIndex,

double * X,

double * Y,

double * Z,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UIndex | \- индекс точки по U,  
---|---  
VIndex | \- индекс точки по V.  
  
Выходные параметры:

X, Y,Z - координаты точки.

Метод позволяет получить параметры точки.

Подразделы:

(отсутствуют)
