# DocumentBeginAdd - Начало добавления документа

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_documentremove.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_documentadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL DocumentBeginAdd( ISpecificationObject * obj );

Входные параметры:

obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) редактируемого объекта спецификации.  
---|---  
  
Возвращаемое значение:

TRUE | \- добавить документ сборочного чертежа,  
---|---  
FALSE | \- запрещает добавление документа сборочного чертежа.  
  
Примечание:

Индекс события задан в перечислении событий для объектов спецификации [ksSpcObjectNotifyEnum](ksspcobjectnotifyenum.html).

Подразделы:

(отсутствуют)
