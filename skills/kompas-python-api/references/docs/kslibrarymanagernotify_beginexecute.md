# BeginExecute - Запуск выполнения команды библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_begininsertdocument.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_begindetach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL BeginExecute (ILibrary * PLibrary);

Синтаксис COM:

BOOL BeginExecute (IUnknown * PLibrary);

Входные параметры:

PLibrary | \- интерфейс библиотеки.  
---|---  
  
Возвращаемое значение:

TRUE | \- можно выполнять команду библиотеки,  
---|---  
FALSE | \- выполнять команду библиотеки нельзя.  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
