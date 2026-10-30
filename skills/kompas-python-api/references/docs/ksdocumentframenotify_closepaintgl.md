# ClosePaintGL - Окончание создания листа в контексте OpenGL

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_closepainttmpobjects.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_closepaint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL CloseCreateGLList (ksGLObject* glObj, long drawMode);

Синтаксис COM:

BOOL CloseCreateGLList (long drawMode);

Входные параметры:

glObj | \- указатель на интерфейс [ksGLObject](ksglobject.html) вспомогательных данных для создания листа в контексте OpenGL; используется при работе под управлением внешнего контроллера,  
---|---  
drawMode | \- режим отображения документа-модели [KDocument3DDrawMode.](kdocument3ddrawmode.html)  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

Подразделы:

(отсутствуют)
