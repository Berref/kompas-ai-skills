# BeginDragOpenFiles - Открытие файлов перетаскиванием в окно Компас

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_beginopendocument.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_begincreate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL BeginDragOpenFiles( VARIANT * filesList, BOOL insert, BOOL * filesListChanged );

Синтаксис COM:

BOOL BeginDragOpenFiles( VARIANT * filesList, BOOL insert, BOOL * filesListChanged );

Возвращаемое значение:

TRUE | \- использовать стандартный механизм открытия\вставки файлов,  
---|---  
FALSE | \- библиотека самостоятельно обработала список файлов или запретила действия с данными файлами.  
  
Входные параметры:

filesList | \- список файлов,  
---|---  
insert | TRUE - выполняется вставка файлов в сборку, FALSE - выполняется открытие файлов.  
  
Выходные параметры:

filesList | \- список файлов (библиотека может изменить список файлов),  
---|---  
filesListChanged | \- признак изменения списка файлов.  
  
Подразделы:

(отсутствуют)
