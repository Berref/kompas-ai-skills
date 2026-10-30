# EditInsert - Редактирование документа из библиотеки документов

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_endexecute.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_detach.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL EditInsert (ILibrary * PLibrary, IKompasDocument * pDoc, BOOL newFrw);

Синтаксис COM:

BOOL DeleteInsert (IUnknown * PInsert);

Входные параметры:

PLibrary | \- интерфейс библиотеки,  
---|---  
pDoc | \- интерфейс редактируемого документа,  
newFrw | \- TRUE - редактирование нового документа, \- FALSE - редактирование существующего документа.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
