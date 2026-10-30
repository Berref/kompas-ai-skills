# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ICloudPointsSurface ](icloudpointssurface.html) > [ICloudPointsSurface - свойства ](icloudpointssurface_props.html) |  Scroll [ [ [ ](icloudpointssurface_buildingtype.html "К следующему разделу")](icloudpointssurface_props.html "На уровень выше")](icloudpointssurface_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icloudpointssurface.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( Index ) | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( Index ) = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( Index ) | Получить свойство ([**](2.html))  
Object.SetAssociationObject( Index, AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( Index, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( Index, AssociationObject ) | Установить свойство  
  
Входные параметры:

long Index - индекс точки, для которой нужно установить опорный объект

Подразделы:

(отсутствуют)
