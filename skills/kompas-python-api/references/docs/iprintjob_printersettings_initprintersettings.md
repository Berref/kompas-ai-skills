# InitPrinterSettings - Установить настройки принтера

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_PrinterSettings ](iprintjob_printersettings.html) > [IPrintJob_PrinterSettings - методы ](iprintjob_printersettings_methods.html) |  Scroll [ [ [ ](iprintjob_printersettings_loadprinterconfig.html "К следующему разделу")](iprintjob_printersettings_methods.html "На уровень выше")](iprintjob_printersettings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_printersettings.html)

Синтаксис Automation:

BOOL InitPrinterSettings( BSTR DeviceName,

BOOL IsPortraitPage,

long PaperSize,

long PaperLength,

long PaperWidth,

long PaperSource );

Синтаксис COM:

HRESULT InitPrinterSettings( BSTR DeviceName,

BOOL IsPortraitPage,

long PaperSize,

long PaperLength,

long PaperWidth,

long PaperSource,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

DeviceName | \- имя принтера,  
---|---  
IsPortraitPage | \- ориентация бумаги,  
PaperSize | \- размер бумаги,  
PaperLength | \- длина бумаги,  
PaperWidth | \- ширина бумаги,  
PaperSource | \- источник бумаги.  
  
Метод позволяет настроить параметры принтера или плоттера, на котором будут печататься документы.

Примечание:

Размер бумаги можно задать двумя способами:

1\. Константой, переданной параметром PaperSize. В этом случае параметры PaperLength и PaperWidth должны равняться -1.

2\. Задать произвольный размер с помощью параметров PaperLength и PaperWidth. В этом случае параметр PaperSize должен быть равен 0.

Подразделы:

(отсутствуют)
