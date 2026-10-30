# BaseSurface - Базовая поверхность для эквидистантной поверхности (грань или совокупность граней)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IEquidistantSurface ](iequidistantsurface.html) > [IEquidistantSurface - свойства ](iequidistantsurface_props.html) |  Scroll [ [ [ ](iequidistantsurface_direction.html "К следующему разделу")](iequidistantsurface_props.html "На уровень выше")](iequidistantsurface_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iequidistantsurface.html)

Тип данных: VARIANT

Синтаксис Automation:

BaseSurface = Object.BaseSurface | Получить свойство ([* ](1.html))  
---|---  
Object.BaseSurface = BaseSurface | Установить свойство ([* ](1.html))  
BaseSurface = Object.GetBaseSurface() | Получить свойство ([**](2.html))  
Object.SetBaseSurface( BaseSurface ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseSurface( &BaseSurface ) | Получить свойство  
---|---  
Object.put_BaseSurface( BaseSurface ) | Установить свойство  
  
Примечание:

В качестве базовой поверхности могут использоваться следующие объекты:

•грань тела или поверхности;

•связная совокупность граней одного тела или поверхности.

Связная совокупность граней — множество граней, каждая из которых имеет общее ребро хотя бы еще с одной гранью этого множества, причем одно ребро одновременно принадлежит не более чем двум граням.

Подразделы:

(отсутствуют)
