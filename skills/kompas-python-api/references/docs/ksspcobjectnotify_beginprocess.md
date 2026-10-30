# BeginProcess - Начало редактирования/создания объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html) > [ksSpcObjectNotify - события ](ksspcobjectnotify_events.html) |  Scroll [ [ [ ](ksspcobjectnotify_cellbeginedit.html "К следующему разделу")](ksspcobjectnotify_events.html "На уровень выше")](ksspcobjectnotify_begingeomchange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjectnotify.html)

Синтаксис Automation:

BOOL BeginProcess (long pType, long objRef);

Синтаксис COM:

BOOL BeginProcess (long pType, long objRef);

Входные параметры:

objRef | \- указатель на объект,  
---|---  
pType | \- [тип объекта спецификации...](spcstrtypes.html) (SPC_BASE_OBJECT, SPC_COMMENT).  
  
Возвращаемое значение:

TRUE | \- редактировать/создать объект,  
---|---  
FALSE | \- редактирование/создание объекта спецификации запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий объекта спецификации...](ksspcobjectnotifyenum.html)

Подразделы:

(отсутствуют)
