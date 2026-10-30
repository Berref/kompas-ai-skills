# MouseMove - Перемещение мыши

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_mouseup.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_mousedown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL MouseDown (short nShiftState, long x, long y);

Синтаксис COM:

BOOL MouseMove (short nShiftState, long x, long y);

Входные параметры:

nShiftState | \- комбинация нажатых системных клавиш (SHIFT_MASK, CTRL_MASK, ALT_MASK),  
---|---  
х,у | \- координаты в экранных пикселах.  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

2\. Значения системных кнопок допустимых в комбинации параметра nShiftState:

SHIFT_MASK | 0x01  
---|---  
CTRL_MASK | 0x02  
ALT_MASK | 0x04  
  
Подразделы:

(отсутствуют)
