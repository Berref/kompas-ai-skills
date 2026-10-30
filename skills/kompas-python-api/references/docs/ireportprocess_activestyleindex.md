# ActiveStyleIndex - Активный стиль отчета

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Отчет ](ba1711159.html) > [Интерфейс IReportProcess ](ireportprocess.html) > [IReportProcess - свойства ](ireportprocess_props.html) |  Scroll [ [ [ ](ireportprocess_reportfilter.html "К следующему разделу")](ireportprocess_props.html "На уровень выше")](ireportprocess_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ireportprocess.html)

Тип данных: VARIANT

Синтаксис Automation:

ActiveStyleIndex = Object.ActiveStyleIndex | Получить свойство ([* ](1.html))  
---|---  
Object.ActiveStyleIndex = ActiveStyleIndex | Установить свойство ([* ](1.html))  
ActiveStyleIndex = Object.GetActiveStyleIndex() | Получить свойство ([**](2.html))  
Object.SetActiveStyleIndex( ActiveStyleIndex ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ActiveStyleIndex( &ActiveStyleIndex ) | Получить свойство  
---|---  
Object.put_ActiveStyleIndex( ActiveStyleIndex ) | Установить свойство  
  
Свойство позволяет устанавливать и получать активный стиль отчета.

Примечание:

Тип VT_I4 - номер стиля в списке стилей. При установке стиля можно также использовать VT_R8 - уникальный номер стиля.

Подразделы:

(отсутствуют)
