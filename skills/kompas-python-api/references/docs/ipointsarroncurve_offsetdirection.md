# OffsetDirection - Направление границы

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPointsArrOnCurve ](ipointsarroncurve.html) > [IPointsArrOnCurve - свойства ](ipointsarroncurve_props.html) |  Scroll [ [ [ ](ipointsarroncurve_offsettype.html "К следующему разделу")](ipointsarroncurve_props.html "На уровень выше")](ipointsarroncurve_offset.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipointsarroncurve.html)

Тип данных: BOOL

Синтаксис Automation:

OffsetDirection = Object.OffsetDirection( FirstPoint ) | Получить свойство ([* ](1.html))  
---|---  
Object.OffsetDirection( FirstPoint ) = OffsetDirection | Установить свойство ([* ](1.html))  
OffsetDirection = Object.GetOffsetDirection( FirstPoint ) | Получить свойство ([**](2.html))  
Object.SetOffsetDirection( FirstPoint, OffsetDirection ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_OffsetDirection( FirstPoint, &OffsetDirection ) | Получить свойство  
---|---  
Object.put_OffsetDirection( FirstPoint, OffsetDirection ) | Установить свойство  
  
Входные параметры:

BOOL FirstPoint | \- для первой точки.  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать направление границы.

Подразделы:

(отсутствуют)
