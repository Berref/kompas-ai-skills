# BeginCreate - Начало создания документа (до диалога выбора типа)

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_beginopendocument.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_beginclosealldocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL BeginCreate (long docType);

Синтаксис COM:

BOOL BeginCreate (long docType);

Входные параметры:

docName | \- тип документа,  
---|---  
0 | \- если пользователь запросил диалог создания документа.  
  
Возвращаемое значение:

TRUE | \- создать документ,  
---|---  
FALSE | \- создание документа запрещено.  
  
Примечание:

Источником события является интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
