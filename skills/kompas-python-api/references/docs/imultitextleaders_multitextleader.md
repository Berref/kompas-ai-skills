# MultiTextLeader - Выносная надпись к многослойным конструкциям, заданная по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeaders ](imultitextleaders.html) > [IMultiTextLeaders - свойства ](imultitextleaders_props.html) |  Scroll [ [ [ ](imultitextleaders_methods.html "К следующему разделу")](imultitextleaders_props.html "На уровень выше")](imultitextleaders_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleaders.html)

Тип данных: указатель на интерфейс [IMultiTextLeader](imultitextleader.html)

Синтаксис Automation:

MultiTextLeader = iObject.MultiTextLeader(Index) | Получить свойство([* ](1.html))  
---|---  
MultiTextLeader = iObject.GetMultiTextLeader(Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_MultiTextLeader(Index, &MultiTextLeader) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта, reference объекта.  
---|---  
  
Значения свойства:

указатель на интерфейс [IMultiTextLeader](imultitextleader.html) | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
