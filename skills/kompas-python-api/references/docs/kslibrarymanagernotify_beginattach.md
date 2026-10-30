# BeginAttach - Подключить библиотеку

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_begindetach.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_attach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL BeginAttach (ILibrary * PLibrary);

Синтаксис COM:

BOOL BeginAttach (IUnknown * PLibrary);

Входные параметры:

PLibrary | \- интерфейс библиотеки.  
---|---  
  
Возвращаемое значение:

TRUE | \- можно подключить библиотеку,  
---|---  
FALSE | \- библиотеку подключать нельзя.  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
