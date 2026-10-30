# BuildingType - Способ построения сегмента кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - свойства ](icurvevertexparam_props.html) |  Scroll [ [ [ ](icurvevertexparam_index.html "К следующему разделу")](icurvevertexparam_props.html "На уровень выше")](icurvevertexparam_buildingobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Тип данных: из перечисления [ksLineBuildingType](kslinebuildingtype.html)

Синтаксис Automation:

BuildingType = iObject.BuildingType; | Получить свойство ([* ](1.html))  
---|---  
iObject.BuildingType = BuildingType; | Установить свойство ([* ](1.html))  
BuildingType = iObject.GetBuildingType(); | Получить свойство ([**](2.html))  
iObject.SetBuildingType(BuildingType); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BuildingType (&BuildingType) | Получить свойство  
---|---  
iObject->put_BuildingType (BuildingType) | Установить свойство  
  
Примечание:

1\. Для сплайна используются только константы ksLBTByPoint и ksLBTByPoint3DParams.

2\. В случае задания ksLBTByPoint3DParams начинают работать свойства PointType и PointParameters.

Подразделы:

(отсутствуют)
