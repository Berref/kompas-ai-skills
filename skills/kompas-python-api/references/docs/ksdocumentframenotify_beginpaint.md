# BeginPaint - Начало отрисовки документа

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_beginpaintgl.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_beginpainttmpobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL BeginPaint (IPaintObject* paintObj);

Синтаксис COM:

BOOL BeginPaint (IUnknown* paintObj);

Входные параметры:

paintObj | \- указатель на интерфейс [IPaintObject](ipaintobject.html) вспомогательных данных для отрисовки документа.  
---|---  
  
Возвращаемое значение:

FALSE | \- запретить отрисовку документа.  
---|---  
  
Примечание:

1\. Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

2\. Если событие вернет значение FALSE, то КОМПАС-3D не будет отрисовывать документ; библиотека в этом случае должна сама выполнить всю отрисовку, событие ClosePaint посылаться не будет.

Подразделы:

(отсутствуют)
