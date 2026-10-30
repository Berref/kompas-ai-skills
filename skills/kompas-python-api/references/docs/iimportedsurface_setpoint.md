# SetPoint - Установить параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_setpoints.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_getpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL SetPoint( long UIndex,

long VIndex,

double X,

double Y,

double Z );

Синтаксис COM:

HRESULT SetPoint( long UIndex,

long VIndex,

double X,

double Y,

double Z,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UIndex | \- индекс точки по U,  
---|---  
VIndex | \- индекс точки по V,  
X, Y, Z | \- координаты точки.  
  
Метод позволяет установить параметры точки.

Подразделы:

(отсутствуют)
