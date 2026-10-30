# GetPageGabarites - Получить габариты страницы устройства печати

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_getpagesmapgabarites.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_execute.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL GetPageGabarites( double * Width

double * Height );

Синтаксис COM:

HRESULT GetPageGabarites( double * Width,

double * Height,

BOOL * Result );

Выходные параметры:

Width | \- ширина страницы,  
---|---  
Height | \- высота страницы.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи (если листа с таким номером не существует).  
  
Примечание:

Метод позволяет получить габариты страницы устройства печати.

Подразделы:

(отсутствуют)
