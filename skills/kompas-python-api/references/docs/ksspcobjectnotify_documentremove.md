# DocumentRemove - Удаление документа из объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html) > [ksSpcObjectNotify - события ](ksspcobjectnotify_events.html) |  Scroll [ [ [ ](ksspcobjectnotify_endprocess.html "К следующему разделу")](ksspcobjectnotify_events.html "На уровень выше")](ksspcobjectnotify_documentbeginadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjectnotify.html)

Синтаксис Automation:

BOOL DocumentRemove (long objRef, BSTR docName);

Синтаксис COM:

BOOL DocumentRemove (long objRef, char * docName);

Входные параметры:

objRef | \- указатель на объект,  
---|---  
docName | \- имя файла документа.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс метода задан в [перечислении событий объекта спецификации...](ksspcobjectnotifyenum.html)

Подразделы:

(отсутствуют)
