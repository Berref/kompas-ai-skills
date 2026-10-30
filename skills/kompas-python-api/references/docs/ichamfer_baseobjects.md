# BaseObjects - Массив ребер и граней, на которых строится фаска

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IChamfer ](ichamfer.html) > [IChamfer - свойства ](ichamfer_propers.html) |  Scroll [ [ [ ](ichamfer_buildingtype.html "К следующему разделу")](ichamfer_propers.html "На уровень выше")](ichamfer_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichamfer.html)

Тип данных: VARIANT

Синтаксис Automation:

BaseObjects = Object.BaseObjects | Получить свойство ([* ](1.html))  
---|---  
Object.BaseObjects = BaseObjects | Установить свойство ([* ](1.html))  
BaseObjects = Object.GetBaseObjects() | Получить свойство ([**](2.html))  
Object.SetBaseObjects( BaseObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObjects( &BaseObjects ) | Получить свойство  
---|---  
Object.put_BaseObjects( BaseObjects ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать опорный объект или массив опорных объектов, участвующих в операции фаска.

Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
