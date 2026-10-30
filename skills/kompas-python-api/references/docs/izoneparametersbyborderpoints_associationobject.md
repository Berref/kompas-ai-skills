# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZoneParametersByBorderPoints ](izoneparametersbyborderpoints.html) > [IZoneParametersByBorderPoints - свойство ](izoneparametersbyborderpoints_props.html) |  Scroll [ [ [ ](izoneparametersbyborderpoints_buildingtype.html "К следующему разделу")](izoneparametersbyborderpoints_props.html "На уровень выше")](izoneparametersbyborderpoints_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izoneparametersbyborderpoints.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( First ) = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( First ) | Получить свойство ([**](2.html))  
Object.SetAssociationObject( First, AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( First, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( First, AssociationObject ) | Установить свойство  
  
Входные параметры:

BOOL | \- First - TRUE - первая вершина, FALSE - вторая вершина.  
---|---  
  
Подразделы:

(отсутствуют)
