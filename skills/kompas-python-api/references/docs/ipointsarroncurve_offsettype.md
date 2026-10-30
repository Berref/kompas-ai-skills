# OffsetType - Получить способ задания границ

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPointsArrOnCurve ](ipointsarroncurve.html) > [IPointsArrOnCurve - свойства ](ipointsarroncurve_props.html) |  Scroll [ [ [ ](ipointsarroncurve_onoffsets.html "К следующему разделу")](ipointsarroncurve_props.html "На уровень выше")](ipointsarroncurve_offsetdirection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipointsarroncurve.html)

Тип данных: из перечисления [ksPoint3DCurveParamTypeEnum](kspoint3dcurveparamtypeenum.html)

Синтаксис Automation:

OffsetType = Object.OffsetType( FirstPoint ) | Получить свойство ([* ](1.html))  
---|---  
Object.OffsetType( FirstPoint ) = OffsetType | Установить свойство ([* ](1.html))  
OffsetType = Object.GetOffsetType( FirstPoint ) | Получить свойство ([**](2.html))  
Object.SetOffsetType( FirstPoint, OffsetType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_OffsetType( FirstPoint, &OffsetType ) | Получить свойство  
---|---  
Object.put_OffsetType( FirstPoint, OffsetType ) | Установить свойство  
  
Входные параметры:

BOOL FirstPoint | \- для первой точки.  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать способ задания границ.

Подразделы:

(отсутствуют)
