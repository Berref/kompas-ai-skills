# ApplicationDestroy - Закрытие приложения

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_beginclosealldocument.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_events.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL ApplicationDestroy();

Возвращаемое значение:

| \- Не используется.  
---|---  
  
Синтаксис COM:

BOOL ApplicationDestroy();

Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. Источником события является интерфейс [KompasObject](kompasobject.html).

2\. Индекс события задан в [перечислении событий приложения...](kskompasobjectnotifyenum.html).

3\. При обработке данного события необходимо отписаться от всех событий. Библиотека должна сама следить за отпиской событий.

Подразделы:

(отсутствуют)
