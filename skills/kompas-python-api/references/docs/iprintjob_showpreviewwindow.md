# ShowPreviewWindow - Показать окно предварительного просмотра перед печатью

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_specialexecute.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_save.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL ShowPreviewWindow();

Синтаксис COM:

HRESULT ShowPreviewWindow( BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Метод позволяет показать окно предварительного просмотра перед печатью с текущим состоянием задания на печать.

2\. После закрытия окна предварительного просмотра задание на печать очищается, аналогично вызову метода [IPrintJob::Clear](iprintjob_clear.html).

Подразделы:

(отсутствуют)
