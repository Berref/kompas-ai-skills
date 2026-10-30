# BeginChoiceMarking - Начало выбора обозначения

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html) > [IDocument3DNotify - события ](ksdocument3dnotify_events.html) |  Scroll [ [ [ ](ksdocument3dnotify_beginloadcombinationchange.html "К следующему разделу")](ksdocument3dnotify_events.html "На уровень выше")](ksdocument3dnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify.html)

Синтаксис Automation:

BOOL BeginChoiceMarking();

Синтаксис COM:

BOOL BeginChoiceMarking();

Возвращаемое значение:

TRUE | \- выбрать обозначение,  
---|---  
FALSE | \- выбор обозначения запрещен.  
  
Примечание:

1\. Индекс метода задан в [перечислении событий документа-модели...](ksdocument3dnotifyenum.html).

2\. Событие может приходить при редактировании параметров тела.

Подразделы:

(отсутствуют)
