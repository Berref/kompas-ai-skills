# BeginGeomChange - Начало изменения геометрии объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html) > [ksSpcObjectNotify - события ](ksspcobjectnotify_events.html) |  Scroll [ [ [ ](ksspcobjectnotify_beginprocess.html "К следующему разделу")](ksspcobjectnotify_events.html "На уровень выше")](ksspcobjectnotify_begindelete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjectnotify.html)

Синтаксис Automation:

BOOL BeginGeomChange (long objRef);

Синтаксис COM:

BOOL BeginGeomChange (long objRef);

Входные параметры:

objRef | \- указатель на объект,  
---|---  
  
Возвращаемое значение:

TRUE | \- изменить геометрию объекта спецификации,  
---|---  
FALSE | \- изменение объекта спецификации запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий объекта спецификации...](ksspcobjectnotifyenum.html)

Подразделы:

(отсутствуют)
