# CellDblClick - Двойной щелчок в ячейке

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html) > [ksSpcObjectNotify - события ](ksspcobjectnotify_events.html) |  Scroll [ [ [ ](ksspcobjectnotify_changecurrent.html "К следующему разделу")](ksspcobjectnotify_events.html "На уровень выше")](ksspcobjectnotify_cellbeginedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcobjectnotify.html)

Синтаксис Automation:

BOOL StampCellDblClick (long objRef, long number);

Синтаксис COM:

BOOL StampCellDblClick (long objRef, long number);

Входные параметры:

objRef | \- указатель на объект,  
---|---  
number | \- номер ячейки.  
  
Возвращаемое значение:

TRUE | \- обработать двойной щелчок,  
---|---  
FALSE | \- обработка двойного щелчка запрещена.  
  
Примечание:

Индекс метода задан в [перечислении событий объекта спецификации...](ksspcobjectnotifyenum.html)

Подразделы:

(отсутствуют)
