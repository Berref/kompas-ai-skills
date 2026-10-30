# TryExecute - Попытка выполнения команды библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](ksmodelobjectnotify.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_systemcontrolstop.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL TryExecute( ILibrary * PLibrary, long CommandID );

Синтаксис COM

HRESULT TryExecute( ILibrary * PLibrary, long CommandID, BOOL * Result );

Возвращаемое значение:

TRUE | \- если нужно разрешить запуск команды.  
---|---  
  
Входные параметры:

PLibrary | \- указатель на интерфейс библиотеки,  
---|---  
CommandID | \- номер команды.  
  
Подразделы:

(отсутствуют)
