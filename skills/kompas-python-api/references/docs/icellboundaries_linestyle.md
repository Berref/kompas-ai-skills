# LineStyle - Стиль линии границы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ICellBoundaries ](icellboundaries.html) > [ICellBoundaries - свойства ](icellboundaries_props.html) |  Scroll [ [ [ ](icellboundaries_linevisible.html "К следующему разделу")](icellboundaries_props.html "На уровень выше")](icellboundaries_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icellboundaries.html)

Тип данных: из перечисления [ksCurveStyleEnum](kscurvestyleenum.html)

Входные параметры:

index | \- граница, для которой можно установить видимость (из перечисления [ksCellBoundariesEnum)](kscellboundariesenum.html).  
---|---  
  
Синтаксис Automation:

LineStyle = Object.LineStyle( index ) | Получить свойство([* ](1.html))  
---|---  
Object.LineStyle( index ) = LineStyle | Установить свойство ([* ](1.html))  
LineStyle = Object.GetLineStyle( index ) | Получить свойство ([**](2.html))  
Object.SetLineStyle( index, LineStyle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LineStyle( index, &LineStyle ) | Получить свойство  
---|---  
Object.put_LineStyle( index, LineStyle ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать стиль линии границы ячейки.

Подразделы:

(отсутствуют)
