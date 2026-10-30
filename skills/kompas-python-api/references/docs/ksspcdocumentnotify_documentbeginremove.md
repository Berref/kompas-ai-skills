# DocumentBeginRemove - Начало удаления документа сборочного чертежа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-спецификации ksSpcDocumentNotify/ISpcDocumentNotify ](ksspcdocumentnotify.html) > [ISpcDocumentNotify - события ](ksspcdocumentnotify_events.html) |  Scroll [ [ [ ](ksspcdocumentnotify_documentremove.html "К следующему разделу")](ksspcdocumentnotify_events.html "На уровень выше")](ksspcdocumentnotify_documentbeginadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocumentnotify.html)

Синтаксис Automation:

BOOL DocumentBeginRemove (BSTR docName);

Синтаксис COM:

BOOL DocumentBeginRemove (char * docName);

Входные параметры:

docName | \- имя файла документа.  
---|---  
  
Возвращаемое значение:

TRUE | \- удалить документ сборочного чертежа,  
---|---  
FALSE | \- удаление документа запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий документа-спецификации...](ksspcdocumentnotifyenum.html).

Подразделы:

(отсутствуют)
