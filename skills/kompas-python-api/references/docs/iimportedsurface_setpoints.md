# SetPoints - Установить массив всех точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](imeshpointssurface.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_setpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

BOOL SetPoints( long UPCount,

long VPCount, VARIANT Points );

Синтаксис COM:

HRESULT SetPoints( long UPCount, long VPCount, VARIANT Points, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UPCount | \- количество точек по U,  
---|---  
VPCount | \- количество точек по V,  
Points | \- массив VT_ARRAY | VT_R8 координат точек.  
  
Метод позволяет установить массив точек поверхности.

Подразделы:

(отсутствуют)
