# ButtonUpdate - Установка состояния кнопки панели

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksContentDialogNotify ](kscontentdialognotify.html) > [ksContentDialogNotify - методы ](kscontentdialognotify_methods.html) |  Scroll [ [ [ ](kscontentdialognotify_createcontentcallback.html "К следующему разделу")](kscontentdialognotify_methods.html "На уровень выше")](kscontentdialognotify_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscontentdialognotify.html)

Синтаксис Automation:

BOOL ButtonUpdate( long ButtonID, long * Check, BOOL * Enable );

Синтаксис COM:

HRESULT ButtonUpdate( long ButtonID, long * Check, BOOL * Enable, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

ButtonID | \- идентификатор команды панели диалога,  
---|---  
Check | \- состояние кнопки (Нажата\Отжата),  
Enable | \- доступность команды.  
  
Подразделы:

(отсутствуют)
