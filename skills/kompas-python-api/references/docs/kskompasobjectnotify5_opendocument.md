# OpenDocument - Документ открыт

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_methods.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_keyup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL OpenDocument (LPDISPATCH pDoc, long docType);

Входные параметры:

pDoc | \- указатель на интерфейс IDispatch открытого документа,  
---|---  
docType | [\- тип документа ](doctype.html)[DocType](doctype.html)[.](doctype.html)  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Синтаксис COM:

BOOL OpenDocument(long pDoc, int docType);

Входные параметры:

pDoc | \- указатель на открытый документ,  
---|---  
docType | [\- тип документа ](doctype.html)[DocType](doctype.html)[.](doctype.html)  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. Источником события является интерфейс [KompasObject](kompasobject.html).

2\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

Подразделы:

(отсутствуют)
