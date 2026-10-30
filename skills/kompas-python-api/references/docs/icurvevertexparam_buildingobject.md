# BuildingObject - Объект, относительно которого ведется построение

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - свойства ](icurvevertexparam_props.html) |  Scroll [ [ [ ](icurvevertexparam_buildingtype.html "К следующему разделу")](icurvevertexparam_props.html "На уровень выше")](icurvevertexparam_associationvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Тип данных: Указатель на интерфейс модельного объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

BuildingObject = iObject.BuildingObject; | Получить свойство ([* ](1.html))  
---|---  
iObject.BuildingObject = BuildingObject; | Установить свойство ([* ](1.html))  
BuildingObject = iObject.GetBuildingObject(); | Получить свойство ([**](2.html))  
iObject.SetBuildingObject(BuildingObject); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BuildingObject (&BuildingObject) | Получить свойство  
---|---  
iObject->put_BuildingObject (BuildingObject) | Установить свойство  
  
Примечание:

Задать объект, относительно которого ведется построение, можно для типа построения ksLineBuildingType, равного ksLBTParallel и ksLBTPerpendicular.

Подразделы:

(отсутствуют)
