# BeginOpenDocument - Начало открытия документа

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_beginopenfile.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_begindragopenfiles.html "К предыдущему разделу")  
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
