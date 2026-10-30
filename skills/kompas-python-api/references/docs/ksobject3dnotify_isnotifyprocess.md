# IsNotIifyProcess - Ограничение обрабатываемых событий

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html) > [IObject3DNotify - методы ](ksobject3dnotify_methods.html) |  Scroll [ [ [ ](ksstampnotify.html "К следующему разделу")](ksobject3dnotify_methods.html "На уровень выше")](ksobject3dnotify_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject3dnotify.html)

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
