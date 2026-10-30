# ClosePaint - Конец отрисовки документа

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_closepaintgl.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_closeframe.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL ClosePaint (IPaintObject* paintObj);

Синтаксис COM:

BOOL ClosePaint (IUnknown* paintObj);

Входные параметры:

paintObj | \- указатель на интерфейс [IPaintObject](ipaintobject.html) вспомогательных данных для отрисовки документа.  
---|---  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

Подразделы:

(отсутствуют)
