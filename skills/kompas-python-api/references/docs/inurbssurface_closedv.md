# ClosedV - Признак замкнутости поверхности по V

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс INurbsSurface ](inurbssurface.html) > [INurbsSurface - свойства ](inurbssurface_props.html) |  Scroll [ [ [ ](inurbssurface_methods.html "К следующему разделу")](inurbssurface_props.html "На уровень выше")](inurbssurface_closedu.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbssurface.html)

Тип данных: BOOL

Синтаксис Automation:

ClosedV = Object.ClosedV | Получить свойство ([* ](1.html))  
---|---  
Object.ClosedV = ClosedV | Установить свойство ([* ](1.html))  
ClosedV = Object.GetClosedV() | Получить свойство ([**](2.html))  
Object.SetClosedV( ClosedV ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ClosedV( &ClosedV ) | Получить свойство  
---|---  
Object.put_ClosedV( ClosedV ) | Установить свойство  
  
Примечание:

Свойство позволяет получить признак замкнутости поверхности по V.

Свойство позволяет также преобразовать представление поверхности из замкнутого по V представления в разомкнутое по V и наоборот, из разомкнутого представления в замкнутое. См. также [INurbsSurface::ClosedU](inurbssurface_closedu.html).

Подразделы:

(отсутствуют)
