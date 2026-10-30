# CellBeginEdit - Начало редактирования в ячейке

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_celldblclick.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_beginprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL CellBeginEdit( ISpecificationObject * obj, long number );

Входные параметры:

obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) редактируемого объекта спецификации,  
---|---  
number | \- номер редактируемой ячейки.  
  
Возвращаемое значение:

TRUE | \- редактировать ячейку,  
---|---  
FALSE | \- запрещает редактировать ячейку.  
  
Примечание:

Индекс события задан в перечислении событий для объектов спецификации [ksSpcObjectNotifyEnum](ksspcobjectnotifyenum.html).

Подразделы:

(отсутствуют)
