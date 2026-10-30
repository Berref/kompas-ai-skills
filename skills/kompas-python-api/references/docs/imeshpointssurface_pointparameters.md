# PointParameters - Интерфейс параметров точки поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - свойства ](imeshpointssurface_props.html) |  Scroll [ [ [ ](imeshpointssurface_pointtype.html "К следующему разделу")](imeshpointssurface_props.html "На уровень выше")](imeshpointssurface_columnscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imeshpointssurface.html)

Тип данных: указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

PointParameters = Object.PointParameters( UIndex, VIndex ) | Получить свойство ([* ](1.html))  
---|---  
PointParameters = Object.GetPointParameters( UIndex, VIndex ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PointParameters( UIndex, VIndex, &PointParameters ) | Получить свойство  
---|---  
  
Входные параметры:

long UIndex | \- индекс точки по U,  
---|---  
long VIndex | \- индекс точки по V.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
