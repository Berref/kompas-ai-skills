# DimensionType - Тип размера (Выносные линии от центра\Параллельные выносные линии)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IArcDimension ](iarcdimension.html) > [IArcDimension - свойства ](iarcdimension_props.html) |  Scroll [ [ [ ](iarcdimension_direction.html "К следующему разделу")](iarcdimension_props.html "На уровень выше")](iarcdimension_baseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcdimension.html)

Тип данных: BOOL

Значения свойства:

true | \- выносные линии от центра;  
---|---  
false | \- параллельные выносные линии.  
  
Синтаксис Automation:

DimensionType = Object.DimensionType | Получить свойство([* ](1.html))  
---|---  
Object.DimensionType = DimensionType | Установить свойство ([* ](1.html))  
DimensionType = Object.GetDimensionType() | Получить свойство ([**](2.html))  
Object.SetDimensionType( DimensionType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DimensionType( &DimensionType ) | Получить свойство([* ](1.html))  
---|---  
Object.put_DimensionType( DimensionType ) | Установить свойство ([* ](1.html))  
  
Примечание:

Свойство позволяет задать направление выносных линий – от центра или параллельные выносные линии, проведенному в середину дуги. Если угол раствора дуги больше 180 градусов, возможно создание размера только с выносными линиями от центра.

Подразделы:

(отсутствуют)
