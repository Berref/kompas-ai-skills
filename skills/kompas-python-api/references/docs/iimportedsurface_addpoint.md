# AddPoint - Добавить точку в создаваемый ряд

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_addpointsseries.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL AddPoint( double X,

double Y,

double Z );

Синтаксис COM:

HRESULT AddPoint( double X,

double Y,

double Z,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Примечание:

Метод должен вызываться между вызовами методов [IImportedSurface::BeginPointsSeries](iimportedsurface_beginpointsseries.html) и [IImportedSurface::EndPointsSeries](iimportedsurface_endpointsseries.html).

Подразделы:

(отсутствуют)
