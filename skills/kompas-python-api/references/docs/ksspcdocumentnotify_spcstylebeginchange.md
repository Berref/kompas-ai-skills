# SpcStyleBeginChange - Начало изменения стиля спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-спецификации ksSpcDocumentNotify/ISpcDocumentNotify ](ksspcdocumentnotify.html) > [ISpcDocumentNotify - события ](ksspcdocumentnotify_events.html) |  Scroll [ [ [ ](ksspcdocumentnotify_spcstylechange.html "К следующему разделу")](ksspcdocumentnotify_events.html "На уровень выше")](ksspcdocumentnotify_documentremove.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocumentnotify.html)

Синтаксис Automation:

BOOL SpcStyleBeginChange (BSTR libName, long numb);

Синтаксис COM:

BOOL SpcStyleBeginChange (char * libName, long numb);

Входные параметры:

libName | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации.  
  
Возвращаемое значение:

TRUE | \- изменить стиль спецификации,  
---|---  
FALSE | \- изменение стиля запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий документа-спецификации...](ksspcdocumentnotifyenum.html).

Подразделы:

(отсутствуют)
