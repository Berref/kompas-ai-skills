# LineVisible - Видимость границы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ICellBoundaries ](icellboundaries.html) > [ICellBoundaries - свойства ](icellboundaries_props.html) |  Scroll [ [ [ ](itablecell.html "К следующему разделу")](icellboundaries_props.html "На уровень выше")](icellboundaries_linestyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icellboundaries.html)

Тип данных: BOOL

Входные параметры:

index | \- граница, для которой можно установить видимость (из перечисления [ksCellBoundariesEnum)](kscellboundariesenum.html).  
---|---  
  
Синтаксис Automation:

LineVisible = Object.LineVisible( index ) | Получить свойство([* ](1.html))  
---|---  
Object.LineVisible( index ) = LineVisible | Установить свойство ([* ](1.html))  
LineVisible = Object.GetLineVisible( index ) | Получить свойство ([**](2.html))  
Object.SetLineVisible( index, LineVisible ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LineVisible( index, &LineVisible ) | Получить свойство  
---|---  
Object.put_LineVisible( index, LineVisible ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать видимость границы ячейки.

Подразделы:

(отсутствуют)
