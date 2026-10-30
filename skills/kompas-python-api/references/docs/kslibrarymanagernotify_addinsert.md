# AddInsert - Добавлен документ в библиотеку документов

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksLibraryManagerNotify ](kslibrarymanagernotify.html) > [ksLibraryManagerNotify - события ](kslibrarymanagernotify_events.html) |  Scroll [ [ [ ](kslibrarymanagernotify_addlibrarydescription.html "К следующему разделу")](kslibrarymanagernotify_events.html "На уровень выше")](kslibrarymanagernotify_events.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](kslibrarymanagernotify.html)

Синтаксис Automation:

BOOL AddInsert (IInsert * PInsert, BOOL create);

Синтаксис COM:

BOOL AddInsert (IUnknown * PInsert, BOOL create);

Входные параметры:

PInsert | \- интерфейс вставки документа,  
---|---  
create | \- TRUE - создали новый, \- FALSE - добавили с диска.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksLibraryManagerNotifyEnum](kslibrarymanagernotifyenum.html).

Подразделы:

(отсутствуют)
