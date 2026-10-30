# CutUnitMarking - Обозначение узла в сечении, заданное по индексу, ссылке или тексту

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс ICutUnitMarkings ](icutunitmarkings.html) > [ICutUnitMarkings - свойства ](icutunitmarkings_props.html) |  Scroll [ [ [ ](icutunitmarkings_methods.html "К следующему разделу")](icutunitmarkings_props.html "На уровень выше")](icutunitmarkings_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutunitmarkings.html)

Тип данных: указатель на интерфейс [ICutUnitMarking](icutunitmarking.html)

Синтаксис Automation:

CutUnitMarking = iObject.CutUnitMarking(index) | Получить свойство([* ](1.html))  
---|---  
CutUnitMarking = iObject.GetCutUnitMarking(index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CutUnitMarking(index, &CutUnitMarking) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс обозначения узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- reference объекта \- строковое значение текста сверху [ICutUnitMarking::TextUp](icutunitmarking_textup.html).  
---|---  
  
Пример:

mark = iMarks.Mark("A1");

где "А1" - текст сверху

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
