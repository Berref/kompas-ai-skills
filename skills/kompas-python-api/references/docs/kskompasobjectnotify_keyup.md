# KeyUp - Клавиша отпущена

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_opendocument.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_keypress.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL KeyUp (long * key, long flags, BOOL sysKey);

Синтаксис COM:

BOOL KeyUp (long * key, long flags, BOOL sysKey);

Входные параметры:

key | \- код нажатой клавиши,  
---|---  
flags | [\- ](key_flags.html)[флаг клавиатуры](key_flags.html),  
sysKey | [\- ](syskey.html)[признак нажатия системной клавиши](syskey.html).  
  
Выходные параметры:

key | \- измененный код нажатой клавиши.  
---|---  
  
Возвращаемое значение:

TRUE | \- разрешить обработку нажатой клавиши,  
---|---  
FALSE | \- запретить обработку нажатой клавиши.  
  
Примечание:

1\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

2\. Если syskey = false, была нажата обычная клавиша, что соответствует событию [wm_keyup](wm_keyup.html), если syskey = true, была нажата системная клавиша, что соответствует событию [WM_KEYUP](wm_keyup.html),[ если SYSKEY = true, была нажата системная клавиша, что соответствует событию ](wm_syskeyup.html)WM_SYSKEYUP.

3\. Если библиотека обработала событие нажатия клавиши и нужно запретить обработку события другими подписчиками, то нужно обнулить код клавиши т.е. *key = 0 и вернуть FALSE, если нужно запретить обработку события системой КОМПАС.

Подразделы:

(отсутствуют)
