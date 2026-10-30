# CutObject - Секущий объект для усечения поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ITrimmedSurface ](itrimmedsurface.html) > [ITrimmedSurface - свойства ](itrimmedsurface_props.html) |  Scroll [ [ [ ](itrimmedsurface_operationresult.html "К следующему разделу")](itrimmedsurface_props.html "На уровень выше")](itrimmedsurface_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedsurface.html)

Тип данных: VARIANT

Синтаксис Automation:

CutObject = Object.CutObject | Получить свойство ([* ](1.html))  
---|---  
Object.CutObject = CutObject | Установить свойство ([**](2.html))  
CutObject = Object.GetCutObject() | Получить свойство ([**](2.html))  
CutObject = Object.GetCutObject() | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CutObject( &CutObject ) | Получить свойство  
---|---  
Object.put_CutObject( CutObject ) | Установить свойство  
  
Свойство позволяет устанавливать и получать секущий объект или совокупность объектов. Секущие объекты должны однозначно определять границу отсечения, т.е. линия пересечения должна полностью пересекать усекаемую поверхность. Если объект один, используется тип VARIANT-а VT_DISPATCH, если несколько - тип VARIANT-а VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
