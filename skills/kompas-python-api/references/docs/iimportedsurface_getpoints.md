# GetPoints - Получить массив всех точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IImportedSurface ](iimportedsurface.html) > [IImportedSurface - методы ](iimportedsurface_methods.html) |  Scroll [ [ [ ](iimportedsurface_setpoint.html "К следующему разделу")](iimportedsurface_methods.html "На уровень выше")](iimportedsurface_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iimportedsurface.html)

Синтаксис Automation:

VARIANT GetPoints( long * UPCount, long * VPCount );

Синтаксис COM:

HRESULT GetPoints( long * UPCount, long * VPCount, VARIANT * Result );

Возвращаемое значение:

Массив VT_ARRAY | VT_R8 точек поверхности

Выходные параметры:

UPCount | \- количество точек по U,  
---|---  
VPCount | \- количество точек по V.  
  
Подразделы:

(отсутствуют)
