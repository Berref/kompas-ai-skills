# GetGabarites - Получить габариты листа

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [Интерфейс IPrintJob_Sheet ](iprintjob_sheet_.html) > [IPrintJob_Sheet - свойства ](iprintjob_sheet_props.html) |  Scroll [ [ [ ](iprintjob_sheet_number.html "К следующему разделу")](iprintjob_sheet_props.html "На уровень выше")](iprintjob_sheet_documentname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_sheet_.html)

Синтаксис Automation:

BOOL GetGabarites( double * Width,

double * Height );

Синтаксис COM:

HRESULT GetGabarites( double * Width,

double * Height,

BOOL * Result );

Выходные параметры:

Width | \- ширина листа,  
---|---  
Height | \- высота листа.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить габариты листа.

Подразделы:

(отсутствуют)
