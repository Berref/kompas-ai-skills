# KeyDown - Клавиша нажата и удерживается нажатой

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_keypress.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_createdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL KeyDown (long * key, long flags, BOOL sysKey);

Синтаксис COM:

BOOL KeyDown( long * key, long flags, BOOL sysKey);

Входные параметры:

key | \- код нажатой клавиши,  
---|---  
flags | \- [флаг клавиатуры](key_flags.html),  
sysKey | \- [признак нажатия системной клавиши](syskey.html).  
  
Выходные параметры:

key | \- измененный код нажатой клавиши.  
---|---  
  
Возвращаемое значение:

TRUE | \- разрешить обработку нажатой клавиши,  
---|---  
FALSE | \- запретить обработку нажатой клавиши.  
  
Примечание:

1\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html)

2\. Благодаря автоматическому повторению кода клавиши при удержании ее нажатой, до появления события [wm_keyup](wm_keyup.html) может выдаваться несколько событий [wm_keydown](wm_keydown.html). Значение разряда 30 параметра flags позволяет определить, было ли событие wm_keydown первым или является повторным во время удержания клавиши нажатой.

3\. Если библиотека обработала событие нажатия клавиши и нужно запретить обработку события другими подписчиками, то нужно обнулить код клавиши т.е. *key = 0 и вернуть FALSE, если нужно запретить обработку события системой КОМПАС.

Подразделы:

(отсутствуют)
