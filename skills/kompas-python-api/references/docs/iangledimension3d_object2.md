# Object2 - Второй объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IAngleDimension3D ](iangledimension3d.html) > [IAngleDimension3D - свойства ](iangledimension3d_props.html) |  Scroll [ [ [ ](iangledimension3d_methods.html "К следующему разделу")](iangledimension3d_props.html "На уровень выше")](iangledimension3d_object1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimension3d.html)

Тип данных: указатель на интерфейс модельного объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

Object2 = Object.Object2 | Получить свойство ([* ](1.html))  
---|---  
Object.Object2 = Object2 | Установить свойство ([* ](1.html))  
Object2 = Object.GetObject2() | Получить свойство ([**](2.html))  
Object.SetObject2( Object2 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Object2( &Object2 ) | Получить свойство ([* ](1.html))  
---|---  
Object.put_Object2( Object2 ) | Установить свойство ([* ](1.html))  
  
Примечание:

При создании углового размера используются прямолинейные и плоские объекты, которые являются сторонами угла.

Прямолинейные объекты:

•отрезок в эскизе,

•сегмент ломаной,

•вспомогательная ось,

•ребро тела или поверхности.

Плоские объекты:

•координатная плоскость,

•вспомогательная плоскость,

•грань тела или поверхности.

Подразделы:

(отсутствуют)
