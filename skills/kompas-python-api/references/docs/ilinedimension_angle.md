# Angle - Угол наклона размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс ILineDimension ](ilinedimension.html) > [ILineDimension - свойства ](ilinedimension_props.html) |  Scroll [ [ [ ](ilinedimension_orientation.html "К следующему разделу")](ilinedimension_props.html "На уровень выше")](ilinedimension_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimension.html)

Тип данных: double

Синтаксис Automation:

Angle = Object.Angle | Получить свойство([* ](1.html))  
---|---  
Object.Angle = Angle | Установить свойство ([* ](1.html))  
Angle = Object.GetAngle() | Получить свойство ([**](2.html))  
Object.SetAngle( Angle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Angle( &Angle ) | Получить свойство([* ](1.html))  
---|---  
Object.put_Angle( Angle ) | Установить свойство ([* ](1.html))  
  
Примечание:

1\. Свойство позволяет задавать угол наклона выносных линий размера.

2\. Свойство используется при создании размера, параллельного объекту. Свойство [ILineDimension::Orientation](ilinedimension_orientation.html) должно быть равно ksLinDParallel.

Подразделы:

(отсутствуют)
