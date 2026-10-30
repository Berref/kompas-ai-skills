# BeginInsertDocument - Запуск вставки документа из библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_deleteinsert.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_beginexecute.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL BeginInsertDocument( LPDISPATCH PLibrary, long InsertionType, BSTR Insertion );

Синтаксис COM:

BOOL BeginInsertDocument( LPUNKNOWN PLibrary, long InsertionType, BSTR Insertion );

Возвращаемое значение:

TRUE | \- запретить запуск стандартного процесса вставки,  
---|---  
FALSE | \- разрешить запуск стандартного процесса вставки.  
  
Подразделы:

(отсутствуют)
