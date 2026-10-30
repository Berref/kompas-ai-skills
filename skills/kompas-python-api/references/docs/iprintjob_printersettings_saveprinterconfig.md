# SavePrinterConfig - Сохранить конфигурацию принтера

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_PrinterSettings ](iprintjob_printersettings.html) > [IPrintJob_PrinterSettings - методы ](iprintjob_printersettings_methods.html) |  Scroll [ [ [ ](mathematick.html "К следующему разделу")](iprintjob_printersettings_methods.html "На уровень выше")](iprintjob_printersettings_loadprinterconfig.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_printersettings.html)

Сохранить конфигурацию принтера

Синтаксис Automation:

BOOL SavePrinterConfig( BSTR FileName );

Синтаксис COM:

HRESULT SavePrinterConfig( BSTR FileName, BOOL * Result );

Входные параметры:

FileName | \- имя файла конфигурации.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет сохранить настройки печати в файл.

Подразделы:

(отсутствуют)
