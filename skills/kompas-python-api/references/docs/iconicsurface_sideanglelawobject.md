# SideAngleLawObject - Закон. Эскиз с кривой, определяющей функцию y=f(x) угла наклона боковой стороны треугольника сечения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IConicSurface](iconicsurface.html) > [IConicSurface - свойства](iconicsurface_propers.html) |  Scroll [ [ [ ](iconicsurface_sideanglelawtype.html "К следующему разделу")](iconicsurface_propers.html "На уровень выше")](iconicsurface_sideangledirection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconicsurface.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

SideAngleLawObject = Object.SideAngleLawObject( FirstSide ) | Получить свойство ([* ](1.html))  
---|---  
Object.SideAngleLawObject( FirstSide ) = SideAngleLawObject | Установить свойство ([* ](1.html))  
SideAngleLawObject = Object.GetSideAngleLawObject( FirstSide ) | Получить свойство ([**](2.html))  
Object.SetSideAngleLawObject( FirstSide, SideAngleLawObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SideAngleLawObject( FirstSide, &SideAngleLawObject ) | Получить свойство  
---|---  
Object.put_SideAngleLawObject( FirstSide, SideAngleLawObject ) | Установить свойство  
  
Входные параметры:

BOOL FirstSide | \- TRUE - первая сторона, FALSE - вторая сторона.  
---|---  
  
Подразделы:

(отсутствуют)
