# BeginDetach - Отключить библиотеку

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_beginexecute.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_beginattach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL BeginDetach (ILibrary * PLibrary);

Синтаксис COM:

BOOL BeginDetach (IUnknown * PLibrary);

Входные параметры:

PLibrary | \- интерфейс библиотеки.  
---|---  
  
Возвращаемое значение:

TRUE | \- можно отключить библиотеку,  
---|---  
FALSE | \- библиотеку отключить нельзя.  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
