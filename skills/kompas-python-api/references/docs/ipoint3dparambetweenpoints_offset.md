# Offset - Величина смещения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamBetweenPoints](ipoint3dparambetweenpoints.html) > [IPoint3DParamBetweenPoints - свойства](ipoint3dparambetweenpoints_propers.html) |  Scroll [ [ [ ](ipoint3dparambetweenpoints_offsettype.html "К следующему разделу")](ipoint3dparambetweenpoints_propers.html "На уровень выше")](ipoint3dparambetweenpoints_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparambetweenpoints.html)

Тип данных: double

Синтаксис Automation:

Offset = Object.Offset | Получить свойство ([* ](1.html))  
---|---  
Object.Offset = Offset | Установить свойство ([* ](1.html))  
Offset = Object.GetOffset() | Получить свойство ([**](2.html))  
Object.SetOffset( Offset ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Offset( &Offset ) | Получить свойство  
---|---  
Object.put_Offset( Offset ) | Установить свойство  
  
Примечание:

1.Для типа смещения ksOffsetByU свойство определяет величину смещения в % от длины кривой (0...100).

2.Для типа смещения ksOffsetByLen свойство определяет длину сегмента.

3.Для типа смещения ksOffsetByAngle свойство определяет центральный угол дуги.

Подразделы:

(отсутствуют)
