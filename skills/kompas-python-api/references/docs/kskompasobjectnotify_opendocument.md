# OpenDocument - Документ открыт

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kslayoutsheetsnotify.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_keyup.html "К предыдущему разделу")  
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
