# RemoveSheets - Удалить лист из задания на печать

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_save.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_getpagesmapgabarites.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL RemoveSheets( VARIANT Index );

Синтаксис COM:

HRESULT RemoveSheets( VARIANT Index,

BOOL * Result );

Входные параметры:

Index | \- индекс листа.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи (если листа с таким номером не существует).  
  
Примечание:

Метод позволяет удалить лист из задания на печать.

Подразделы:

(отсутствуют)
