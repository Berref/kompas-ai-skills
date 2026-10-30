# ClosedU - Признак замкнутости поверхности по направлению U

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - свойства ](imeshpointssurface_props.html) |  Scroll [ [ [ ](imeshpointssurface_closedv.html "К следующему разделу")](imeshpointssurface_props.html "На уровень выше")](imeshpointssurface_checkselfintersection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imeshpointssurface.html)

Тип данных: BOOL

Синтаксис Automation:

ClosedU = Object.ClosedU | Получить свойство ([* ](1.html))  
---|---  
Object.ClosedU = ClosedU | Установить свойство ([* ](1.html))  
ClosedU = Object.GetClosedU() | Получить свойство ([**](2.html))  
Object.SetClosedU( ClosedU ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ClosedU( &ClosedU ) | Получить свойство  
---|---  
Object.put_ClosedU( ClosedU ) | Установить свойство  
  
Свойство позволяет замкнуть поверхность в направлении U.

Примечание:

Замыкание по тому или иному направлению возможно, если количество точек в этом направлении - три или больше.

Подразделы:

(отсутствуют)
