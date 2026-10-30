# SpecialExecute - Отправить задание на специальную печать

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_sheet_.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_showpreviewwindow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL SpecialExecute( BSTR OutputFileName );

Синтаксис COM:

HRESULT SpecialExecute( BSTR OutputFileName, BOOL * Result );

Входные параметры:

OutputFileName | \- имя устройства печати.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет отправить задание на полистную печать на устройство печати.

Примечание:

Чтобы отправить задание на печать на текущий принтер, следует в качестве параметра OutputFileName прислать пустую строку.

Подразделы:

(отсутствуют)
