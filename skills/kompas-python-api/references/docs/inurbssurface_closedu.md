# ClosedU - Признак замкнутости поверхности по U

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс INurbsSurface ](inurbssurface.html) > [INurbsSurface - свойства ](inurbssurface_props.html) |  Scroll [ [ [ ](inurbssurface_closedv.html "К следующему разделу")](inurbssurface_props.html "На уровень выше")](inurbssurface_boundarycount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbssurface.html)

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
  
Примечание:

Свойство позволяет получить признак замкнутости поверхности по U.

Свойство позволяет также преобразовать представление поверхности из замкнутого по U представления в разомкнутое по U и наоборот, из разомкнутого представления в замкнутое. См также [INurbsSurface::ClosedV](inurbssurface_closedv.html).

Подразделы:

(отсутствуют)
