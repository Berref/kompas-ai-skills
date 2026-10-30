# Angle - Угол вращения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IRotated ](irotated.html) > [IRotated - свойства ](irotated_props.html) |  Scroll [ [ [ ](irotated_angleobject.html "К следующему разделу")](irotated_props.html "На уровень выше")](irotated_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irotated.html)

Тип данных: double

Синтаксис Automation:

Angle = Object.Angle( Normal ) | Получить свойство ([* ](1.html))  
---|---  
Object.Angle( Normal ) = Angle | Установить свойство ([* ](1.html))  
Angle = Object.GetAngle( Normal ) | Получить свойство ([**](2.html))  
Object.SetAngle( Normal, Angle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Angle( Normal, &Angle ) | Получить свойство  
---|---  
Object.put_Angle( Normal, Angle ) | Установить свойство  
  
Входные параметры:

BOOL Normal | \- направление.  
---|---  
  
Примечания:

1\. Для вращения в двух направлениях угол требуется задать дважды — для прямого и обратного направления.

2\. Если используется тип направления Средняя плоскость, то угол задается один раз. При этом он воспринимается системой как общий угол (т.е. в каждую сторону откладывается его половина).

Подразделы:

(отсутствуют)
