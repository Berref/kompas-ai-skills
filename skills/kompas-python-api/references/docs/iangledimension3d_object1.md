# Object1 - Первый объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IAngleDimension3D ](iangledimension3d.html) > [IAngleDimension3D - свойства ](iangledimension3d_props.html) |  Scroll [ [ [ ](iangledimension3d_object2.html "К следующему разделу")](iangledimension3d_props.html "На уровень выше")](iangledimension3d_length.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimension3d.html)

Тип данных: указатель на интерфейс модельного объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

Object1 = Object.Object1 | Получить свойство ([* ](1.html))  
---|---  
Object.Object1 = Object1 | Установить свойство ([* ](1.html))  
Object1 = Object.GetObject1() | Получить свойство ([**](2.html))  
Object.SetObject1( Object1 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Object1( &Object1 ) | Получить свойство ([* ](1.html))  
---|---  
Object.put_Object1( Object1 ) | Установить свойство ([* ](1.html))  
  
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
