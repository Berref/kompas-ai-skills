# LineStyle - Стиль линии

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_trackingtype.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_lineoffsets.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: long (соответствует перечислению [ksCurveStyleEnum](kscurvestyleenum.html))

Синтаксис Automation:

LineStyle = iObject.LineStyle( LineIndex ); | Получить свойство([* ](1.html))  
---|---  
iObject.LineStyle( LineIndex ) = LineStyle; | Установить свойство ([* ](1.html))  
LineStyle = iObject.GetLineStyle( LineIndex ); | Получить свойство ([**](2.html))  
iObject.SetLineStyle( LineIndex, LineStyle ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineStyle( LineIndex, &LineStyle ) | Получить свойство  
---|---  
iObject->put_LineStyle( LineIndex, LineStyle ) | Установить свойство  
  
Входные параметры:

long LineIndex | \- индекс линии.  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать стиль линии.

Подразделы:

(отсутствуют)
