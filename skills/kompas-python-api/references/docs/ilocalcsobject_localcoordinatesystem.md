# LocalCoordinateSystem - Тип параметров объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSObject ](ilocalcsobject.html) > [ILocalCSObject - свойства ](ilocalcsobject_props.html) |  Scroll [ [ [ ](iplacement3d.html "К следующему разделу")](ilocalcsobject_props.html "На уровень выше")](ilocalcsobject_modelobjectparamtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsobject.html)

Тип данных: из перечисления [ksModelObjectParamTypeEnum](ksmodelobjectparamtypeenum.html)

Синтаксис Automation:

LocalCoordinateSystem = Object.LocalCoordinateSystem | Получить свойство ([* ](1.html))  
---|---  
LocalCoordinateSystem = Object.GetLocalCoordinateSystem() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LocalCoordinateSystem( &LocalCoordinateSystem ) | Получить свойство  
---|---  
  
Примечание:

Свойство позволяет получить локальную систему координат объекта.

Если свойство возвращает NULL, объект создан в базовой СК объекта. Для переноса объекта в другую СК используется метод [IPart7::TransferObjects](ipart7_transferobjects.html).

Подразделы:

(отсутствуют)
