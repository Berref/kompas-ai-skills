# CreateContentCallback - Создание контента

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksContentDialogNotify ](kscontentdialognotify.html) > [ksContentDialogNotify - методы ](kscontentdialognotify_methods.html) |  Scroll [ [ [ ](kscontentdialognotify_destroycontent.html "К следующему разделу")](kscontentdialognotify_methods.html "На уровень выше")](kscontentdialognotify_buttonupdate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscontentdialognotify.html)

Синтаксис Automation:

BOOL CreateContentCallback( OLE_HANDLE ParentHwnd, OLE_HANDLE * NewContentHwnd );

Синтаксис COM:

HRESULT CreateContentCallback( OLE_HANDLE ParentHwnd, OLE_HANDLE * NewContentHwnd, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

ParentHwnd | \- родительское окно.  
---|---  
  
Выходные параметры:

NewContentHwnd | \- новое окно контента.  
---|---  
  
Подразделы:

(отсутствуют)
