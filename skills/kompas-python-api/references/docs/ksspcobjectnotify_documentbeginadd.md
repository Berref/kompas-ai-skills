# DocumentBeginAdd - Начало добавления документа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html) > [ksSpcObjectNotify - события ](ksspcobjectnotify_events.html) |  Scroll [ [ [ ](ksspcobjectnotify_documentremove.html "К следующему разделу")](ksspcobjectnotify_events.html "На уровень выше")](ksspcobjectnotify_documentadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjectnotify.html)

Синтаксис Automation:

BOOL DocumentBeginAdd (long objRef);

Синтаксис COM:

BOOL DocumentBeginAdd (long objRef);

Входные параметры:

objRef | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

TRUE | \- добавить документ сборочного чертежа,  
---|---  
FALSE | \- добавление документа сборочного чертежа запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий объекта спецификации...](ksspcobjectnotifyenum.html)

Подразделы:

(отсутствуют)
