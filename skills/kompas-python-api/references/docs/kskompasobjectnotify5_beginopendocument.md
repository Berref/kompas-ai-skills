# BeginOpenDocument - Начало открытия документа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_beginopenfile.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_begincreate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL BeginOpenDocument (BSTR docName);

Входные параметры:

docName | \- имя файла документа.  
---|---  
  
Возвращаемое значение:

TRUE | \- открыть документ,  
---|---  
FALSE | \- не открывать документ.  
  
Синтаксис COM:

BOOL BeginOpenDocument (char * docName);

Входные параметры:

docName | \- имя файла документа.  
---|---  
  
Возвращаемое значение:

TRUE | \- открыть документ,  
---|---  
FALSE | \- не открывать документ.  
  
Примечание:

1\. Источником события является интерфейс [KompasObject](kompasobject.html).

2\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

Подразделы:

(отсутствуют)
