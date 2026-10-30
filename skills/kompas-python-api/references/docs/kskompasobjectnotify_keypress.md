# KeyPress - Одиночное нажатие клавиши

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_keyup.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_keydown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL KeyPress (long * key, BOOL sysKey);

Синтаксис COM:

BOOL KeyPress (long * key, BOOL sysKey);

Входные параметры:

key | \- код нажатой клавиши,  
---|---  
flags | [\- ](key_flags.html)[флаг клавиатуры](key_flags.html),  
sysKey | \- [признак нажатия системной клавиши](syskey.html).  
  
Выходные параметры:

key | \- измененный код клавиши.  
---|---  
  
Возвращаемое значение:

TRUE | \- разрешить обработку нажатой клавиши,  
---|---  
FALSE | \- запретить обработку нажатой клавиши.  
  
Примечание:

1\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

2\. Если syskey = false, была нажата обычная клавиша, что соответствует событию [WM_KEYUP](wm_keyup.html),[ если SYSKEY = true, была нажата системная клавиша, что соответствует событию ](wm_syskeyup.html)WM_SYSKEYUP.

3\. Если библиотека обработала событие нажатия клавиши и нужно запретить обработку события другими подписчиками, то нужно обнулить код клавиши т.е. *key = 0 и вернуть FALSE, если нужно запретить обработку события системой КОМПАС.

Подразделы:

(отсутствуют)
