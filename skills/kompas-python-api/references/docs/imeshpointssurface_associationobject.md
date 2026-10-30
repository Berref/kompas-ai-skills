# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IMeshPointsSurface ](imeshpointssurface.html) > [IMeshPointsSurface - свойства ](imeshpointssurface_props.html) |  Scroll [ [ [ ](imeshpointssurface_buildingtype.html "К следующему разделу")](imeshpointssurface_props.html "На уровень выше")](imeshpointssurface_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imeshpointssurface.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( UIndex, VIndex ) | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( UIndex, VIndex ) = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( UIndex, VIndex ) | Получить свойство ([**](2.html))  
Object.SetAssociationObject( UIndex, VIndex, AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( UIndex, VIndex, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( UIndex, VIndex, AssociationObject ) | Установить свойство  
  
Входные параметры:

long UIndex | \- индекс точки по U,  
---|---  
long VIndex | \- индекс точки по V.  
  
Подразделы:

(отсутствуют)
