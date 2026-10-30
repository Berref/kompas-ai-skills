# BuildingObject - Направляющий объект построения элемента у крайних сечений

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ILoft ](iloft.html) > [ILoft - свойства ](iloft_propers.html) |  Scroll [ [ [ ](iloft_buildingtype.html "К следующему разделу")](iloft_propers.html "На уровень выше")](iloft_axisline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloft.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html).

Синтаксис Automation:

BuildingObject = Object.BuildingObject( BeginSection ) | Получить свойство ([* ](1.html))  
---|---  
Object.BuildingObject( BeginSection ) = BuildingObject | Установить свойство ([* ](1.html))  
BuildingObject = Object.GetBuildingObject( BeginSection ) | Получить свойство ([**](2.html))  
Object.SetBuildingObject( BeginSection, BuildingObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BuildingObject( BeginSection, &BuildingObject ) | Получить свойство  
---|---  
Object.put_BuildingObject( BeginSection, BuildingObject ) | Установить свойство  
  
Входные параметры:

BOOL BeginSection | \- TRUE у начального сечения, \- FALSE - у конечного сечения.  
---|---  
  
Подразделы:

(отсутствуют)
