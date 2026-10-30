# BuildingType - Способы построения элемента у крайних сечений

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ILoft ](iloft.html) > [ILoft - свойства ](iloft_propers.html) |  Scroll [ [ [ ](iloft_closed.html "К следующему разделу")](iloft_propers.html "На уровень выше")](iloft_buildingobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloft.html)

Тип данных: Значение из перечисления [ksLoftBuildingType](ksloftbuildingtype.html).

Синтаксис Automation:

BuildingType = Object.BuildingType( BeginSection ) | Получить свойство ([* ](1.html))  
---|---  
Object.BuildingType( BeginSection ) = BuildingType | Установить свойство ([* ](1.html))  
BuildingType = Object.GetBuildingType( BeginSection ) | Получить свойство ([**](2.html))  
Object.SetBuildingType( BeginSection, BuildingType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BuildingType( BeginSection, &BuildingType ) | Получить свойство  
---|---  
Object.put_BuildingType( BeginSection, BuildingType ) | Установить свойство  
  
Входные параметры:

BOOL BeginSection | \- TRUE у начального сечения, \- FALSE - у конечного сечения.  
---|---  
  
Подразделы:

(отсутствуют)
