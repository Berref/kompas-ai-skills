# BeginDelete - Начало удаления объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_begingeomchange.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_begincopy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL BeginDelete (ISpecificationObject * obj );

Входные параметры:

obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) удаляемого объекта спецификации.  
---|---  
  
Возвращаемое значение:

TRUE | \- удалить объект,  
---|---  
FALSE | \- запрещает удаление объекта.  
  
Примечание:

Индекс события задан в перечислении событий для объектов спецификации [ksSpcObjectNotifyEnum](ksspcobjectnotifyenum.html).

Подразделы:

(отсутствуют)
