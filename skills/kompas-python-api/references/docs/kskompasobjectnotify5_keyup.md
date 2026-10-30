# KeyUp - Клавиша отпущена

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_opendocument.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_keypress.html "К предыдущему разделу")  
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
sysKey | [\- ](syskey.html)[признак нажатия системной клавиши](syskey.html),  
  
Выходные параметры:

key | \- измененный код нажатой клавиши.  
---|---  
  
Возвращаемое значение:

TRUE | \- разрешить обработку нажатой клавиши,  
---|---  
FALSE | \- запретить обработку нажатой клавиши.  
  
Примечание:

1\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

2\. Если syskey = false, была нажата обычная клавиша, что соответствует событию [wm_keyup](wm_keyup.html),[ если syskey = true, была нажата системная клавиша, что соответствует событию ](wm_syskeyup.html)wm_syskeyup.

3\. Если библиотека обработала событие нажатия клавиши и нужно запретить обработку события другими подписчиками, то нужно обнулить код клавиши т.е. *key = 0 и вернуть FALSE, если нужно запретить обработку события системой КОМПАС.

Подразделы:

(отсутствуют)
