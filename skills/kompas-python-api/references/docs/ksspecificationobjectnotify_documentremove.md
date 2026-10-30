# DocumentRemove - Удаление документа из объекта спецификации

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationObjectNotify ](ksspecificationobjectnotify.html) > [ksSpecificationObjectNotify - события ](ksspecificationobjectnotify_events.html) |  Scroll [ [ [ ](ksspecificationobjectnotify_endprocess.html "К следующему разделу")](ksspecificationobjectnotify_events.html "На уровень выше")](ksspecificationobjectnotify_documentbeginadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationobjectnotify.html)

Синтаксис Automation:

BOOL DocumentRemove( ISpecificationObject * obj, BSTR docName );

Входные параметры:

obj | \- указатель на интерфейс [ISpecificationObject](ispecificationobject.html) редактируемого объекта спецификации,  
---|---  
docName | \- имя файла удаляемого документа.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий для объектов спецификации [ksSpcObjectNotifyEnum](ksspcobjectnotifyenum.html).

Подразделы:

(отсутствуют)
