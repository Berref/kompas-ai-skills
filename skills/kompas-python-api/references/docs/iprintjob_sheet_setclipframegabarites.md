# SetClipFrameGabarites - Установить выводимые на печать габариты листа

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [Интерфейс IPrintJob_Sheet ](iprintjob_sheet_.html) > [IPrintJob_Sheet - методы ](iprintjob_sheet_methods.html) |  Scroll [ [ [ ](iprintjob_outputparameters.html "К следующему разделу")](iprintjob_sheet_methods.html "На уровень выше")](iprintjob_sheet_getclipframegabarites.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_sheet_.html)

Синтаксис Automation:

BOOL SetClipFrameGabarites( double Left,

double Bottom,

double Right,

double Top );

Синтаксис COM:

HRESULT SetClipFrameGabarites( double Left,

double Bottom,

double Right,

double Top,

BOOL * Result );

Входные параметры:

Left, Bottom, Right, Top | \- габариты рамки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет установить выводимые на печать габариты листа.

2\. Никакой из габаритов рамки не может быть больше соответствующего ему габарита листа.

Подразделы:

(отсутствуют)
