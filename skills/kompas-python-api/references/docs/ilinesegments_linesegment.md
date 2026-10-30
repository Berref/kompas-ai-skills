# LineSegment - Отрезок, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ILineSegments ](ilinesegments.html) > [ILineSegments - свойства ](ilinesegments_props.html) |  Scroll [ [ [ ](ilinesegments_methods.html "К следующему разделу")](ilinesegments_props.html "На уровень выше")](ilinesegments_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegments.html)

Тип данных: указатель на интерфейс отрезка [ILineSegment](ilinesegment.html)

Синтаксис Automation:

LineSegment = iObject.LineSegment( Index ); | Получить свойство([* ](1.html))  
---|---  
LineSegment = iObject.GetLineSegment( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineSegment( Index, &LineSegment ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс отрезка в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- reference объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
