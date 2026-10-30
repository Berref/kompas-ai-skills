# Execute - Отправить задание на печать на устройство печати

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_getpagegabarites.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_load.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL Execute( BSTR OutputFileName );

Синтаксис COM:

HRESULT Execute( BSTR OutputFileName,

BOOL * Result );

Входные параметры:

OutputFileName | \- имя устройства печати.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет отправить задание на печать на устройство печати.

2\. Чтобы отправить задание на печать на текущий принтер, следует в качестве параметра OutputFileName прислать пустую строку.

Подразделы:

(отсутствуют)
