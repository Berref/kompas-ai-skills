# SystemControlStop - Передача управления библиотеке

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_tryexecute.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_systemcontrolstart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL SystemControlStop (ILibrary * PLibrary);

Синтаксис COM:

BOOL SystemControlStop (IUnknown * PLibrary);

Входные параметры:

PLibrary | \- интерфейс библиотеки.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
