# AddGabarit - Рассчитывается общий габарит окна

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_beginpainttmpobjects.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_activate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL AddGabarit (IGabaritObject * gabObj);

Синтаксис COM:

BOOL AddGabarit (IUnknown* gabObj);

Входные параметры:

gabObj | \- указатель на интерфейс [IGabaritObject](igabaritobject.html) вспомогательных данных для изменения габарита документа.  
---|---  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

2\. Если на данное событие подписалось несколько библиотек, то заданные ими прямоугольники суммируются.

Подразделы:

(отсутствуют)
