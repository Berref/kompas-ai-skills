# BeginCreate - Начало создания документа (до диалога выбора типа)

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_begindragopenfiles.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_beginconverttosaveprevious.html "К предыдущему разделу")  
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
