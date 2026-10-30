# BasePlane - Базовая плоскость

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ITolerance3D ](itolerance3d.html) > [ITolerance3D - свойства ](itolerance3d_props.html) |  Scroll [ [ [ ](itolerance3d_branchpos.html "К следующему разделу")](itolerance3d_props.html "На уровень выше")](itolerance3d_arrowtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance3d.html)

Тип данных: из перечисления [ksObj3dTypeEnum](obj3dtype.html)

Значения свойства:

o3d_unknown | 0 | Неизвестный  
---|---|---  
o3d_planeXOY | 1 | Плоскость XOY  
o3d_planeXOZ | 2 | Плоскость XOZ  
o3d_planeYOZ | 3 | Плоскость YOZ  
  
Синтаксис Automation:

BasePlane = Object.BasePlane | Получить свойство ([* ](1.html))  
---|---  
Object.BasePlane = BasePlane | Установить свойство ([* ](1.html))  
BasePlane = Object.GetBasePlane() | Получить свойство ([**](2.html))  
Object.SetBasePlane( BasePlane ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BasePlane( &BasePlane ) | Получить свойство  
---|---  
Object.put_BasePlane( BasePlane ) | Установить свойство  
  
Примечание.

Свойство позволяет устанавливать и получать тип плоскости из перечисления [ksObj3dTypeEnum](obj3dtype.html), в которой располагается объект.

Подразделы:

(отсутствуют)
