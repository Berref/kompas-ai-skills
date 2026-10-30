# BeginPaintTmpObjects - Начало отрисовки временных объектов (фантомов)

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_beginpaint.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_addgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL BeginPaintTmpObjects();

Синтаксис COM:

BOOL BeginPaintTmpObjects();

Возвращаемое значение:

FALSE | \- запретить отрисовку временных объектов.  
---|---  
  
Примечание:

Событие можно получить в 2D документе и использовать для самостоятельной отрисовки временных объектов функциями OpenGL

Подразделы:

(отсутствуют)
