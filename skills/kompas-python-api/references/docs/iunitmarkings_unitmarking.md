# UnitMarking - Обозначение узла, заданное по индексу, ссылке или тексту

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitMarkings ](iunitmarkings.html) > [IUnitMarkings - свойства ](iunitmarkings_props.html) |  Scroll [ [ [ ](iunitmarkings_methods.html "К следующему разделу")](iunitmarkings_props.html "На уровень выше")](iunitmarkings_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitmarkings.html)

Тип данных: указатель на интерфейс [IUnitMarking](iunitmarking.html)

Синтаксис Automation:

UnitMarking = iObject.UnitMarking(index) | Получить свойство([* ](1.html))  
---|---  
UnitMarking = iObject.GetUnitMarking(index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UnitMarking(index, &UnitMarking) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс обозначения узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, \- reference объекта \- строковое значение текста сверху [IUnitMarking::TextUp](iunitmarking_textup.html).  
---|---  
  
Пример:

UnitMarking = iUnitMarkings.UnitMarking("A1");

где "А1" - текст сверху

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
