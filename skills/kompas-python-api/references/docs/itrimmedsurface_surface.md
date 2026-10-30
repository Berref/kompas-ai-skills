# Surface - Усекаемая поверхность

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ITrimmedSurface ](itrimmedsurface.html) > [ITrimmedSurface - свойства ](itrimmedsurface_props.html) |  Scroll [ [ [ ](itrimmedsurface_methods.html "К следующему разделу")](itrimmedsurface_props.html "На уровень выше")](itrimmedsurface_sense.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedsurface.html)

Тип данных: VARIANT

Синтаксис Automation:

Surface = Object.Surface | Получить свойство ([* ](1.html))  
---|---  
Object.Surface = Surface | Установить свойство ([* ](1.html))  
Surface = Object.GetSurface() | Получить свойство ([**](2.html))  
Object.SetSurface( Surface ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Surface( &Surface ) | Получить свойство  
---|---  
Object.put_Surface( Surface ) | Установить свойство  
  
Свойство позволяет устанавливать и получать усекаемую поверхность. В качестве усекаемой поверхности может использоваться связная совокупность граней одного тела или одной поверхности. Если грань одна, используется тип VARIANT-а VT_DISPATCH, если несколько - тип VARIANT-а VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
