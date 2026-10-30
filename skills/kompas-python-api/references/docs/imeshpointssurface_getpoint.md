# GetPoint - Параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - методы ](bc2291576.html) |  Scroll [ [ [ ](imeshpointssurface_initparambyface.html "К следующему разделу")](bc2291576.html "На уровень выше")](imeshpointssurface_getparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](imeshpointssurface.html)

Синтаксис Automation:

BOOL GetPoint( long UIndex,

long VIndex,

double * X,

double * Y,

double * Z,

double * Weight );

Синтаксис COM:

HRESULT GetPoint( long UIndex,

long VIndex,

double * X,

double * Y,

double * Z,

double * Weight,

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

X, Y, Z | \- координаты точки,  
---|---  
Weight | \- вес точки.  
  
Метод позволяет получить параметры точки.

Подразделы:

(отсутствуют)
