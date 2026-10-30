# GetClipFrameGabarites - Получить выводимые на печать габариты листа

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [Интерфейс IPrintJob_Sheet ](iprintjob_sheet_.html) > [IPrintJob_Sheet - методы ](iprintjob_sheet_methods.html) |  Scroll [ [ [ ](iprintjob_sheet_setclipframegabarites.html "К следующему разделу")](iprintjob_sheet_methods.html "На уровень выше")](iprintjob_sheet_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_sheet_.html)

Синтаксис Automation:

BOOL GetClipFrameGabarites( double * Left,

double * Bottom,

double * Right,

double * Top );

Синтаксис COM:

HRESULT GetClipFrameGabarites( double * Left,

double * Bottom,

double * Right,

double * Top,

BOOL * Result );

Выходные параметры:

Left, Bottom, Right, Top | \- габариты рамки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить выводимые на печать габариты листа.

Подразделы:

(отсутствуют)
