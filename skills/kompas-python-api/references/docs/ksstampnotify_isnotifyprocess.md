# IsNotIifyProcess - Ограничение обрабатываемых событий

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий основной надписи графического документа ksStampNotify/IStampNotify ](ksstampnotify.html) > [IStampNotify - методы ](ksstampnotify_methods.html) |  Scroll [ [ [ ](ksselectionmngnotify.html "К следующему разделу")](ksstampnotify_methods.html "На уровень выше")](ksstampnotify_methods.html "К предыдущему разделу")  
---|---  
  
Синтаксис Automation:

Не используется.

Синтаксис COM:

BOOL IsNotifyProcess (int notifyType);

Входной параметр:

notifyType | \- номер события в [перечислении событий](events_enum_common.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- событие будет обрабатываться,  
---|---  
FALSE | \- событие обрабатываться не будет.  
  
Примечание:

В COM перед любым вызовом события система сделает запрос о возможности его обработки с использованием данного метода. Библиотека сама может ограничивать обрабатываемые события.

Подразделы:

(отсутствуют)
