# SideFaces - Список направляющих поверхностей стороны треугольника

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IConicSurface](iconicsurface.html) > [IConicSurface - свойства](iconicsurface_propers.html) |  Scroll [ [ [ ](iconicsurface_methods.html "К следующему разделу")](iconicsurface_propers.html "На уровень выше")](iconicsurface_sidebuildingtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconicsurface.html)

Тип данных: VARIANT

Синтаксис Automation:

SideFaces = Object.SideFaces( FirstSide ) | Получить свойство ([* ](1.html))  
---|---  
Object.SideFaces( FirstSide ) = SideFaces | Установить свойство ([* ](1.html))  
SideFaces = Object.GetSideFaces( FirstSide ) | Получить свойство ([**](2.html))  
Object.SetSideFaces( FirstSide, SideFaces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SideFaces( FirstSide, &SideFaces ) | Получить свойство  
---|---  
Object.put_SideFaces( FirstSide, SideFaces ) | Установить свойство  
  
Входные параметры:

BOOL FirstSide | \- TRUE - первая сторона, FALSE - вторая сторона.  
---|---  
  
Примечание

Поверхности передаются в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
