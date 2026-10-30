# MouseDblClick - Двойной щелчок кнопкой мыши

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDocumentFrameNotify/IDocumentFrameNotify ](ksdocumentframenotify.html) > [ksDocumentFrameNotify, IDocumentFrameNotify - события ](ksdocumentframenotify_events.html) |  Scroll [ [ [ ](ksdocumentframenotify_mousedown.html "К следующему разделу")](ksdocumentframenotify_events.html "На уровень выше")](ksdocumentframenotify_deactivate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentframenotify.html)

Синтаксис Automation:

BOOL MouseDblClick (short nButton, short nShiftState, long x, long y);

Синтаксис COM:

BOOL MouseDblClick (short nButton, short nShiftState, long x, long y);

Входные параметры:

nButton | \- тип кнопки (LEFT_BUTTON, RIGHT_BUTTON или MIDDLE_BUTTON),  
---|---  
nShiftState | \- комбинация нажатых системных кнопок клавиатуры (SHIFT_MASK, CTRL_MASK, ALT_MASK),  
х,у | \- координаты в экранных пикселах.  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий окна документа [ksDocumentFrameNotifyEnum](ksdocumentframenotifyenum.html).

Значения системных кнопок, допустимых в комбинации параметра nShiftState:

SHIFT_MASK | 0x01  
---|---  
CTRL_MASK | 0x02  
ALT_MASK | 0x04  
  
Значения типов кнопок мыши для параметра nButton:

LEFT_BUTTON | 0x01  
---|---  
RIGHT_BUTTON | 0x02  
MIDDLE_BUTTON | 0x04  
  
Подразделы:

(отсутствуют)
