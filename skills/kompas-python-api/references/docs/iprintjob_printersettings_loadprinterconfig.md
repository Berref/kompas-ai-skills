# LoadPrinterConfig - Загрузить конфигурацию принтера

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_PrinterSettings ](iprintjob_printersettings.html) > [IPrintJob_PrinterSettings - методы ](iprintjob_printersettings_methods.html) |  Scroll [ [ [ ](iprintjob_printersettings_saveprinterconfig.html "К следующему разделу")](iprintjob_printersettings_methods.html "На уровень выше")](iprintjob_printersettings_initprintersettings.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_printersettings.html)

Синтаксис Automation:

BOOL LoadPrinterConfig( BSTR FileName );

Синтаксис COM:

HRESULT LoadPrinterConfig( BSTR FileName, BOOL * Result );

Входные параметры:

FileName | \- имя файла конфигурации.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет загрузить настройки печати из файла.

Примечание:

Если в качестве параметра передать пустую строку, то будет загружена конфигурация из настроек в зависимости от типа принтера

Подразделы:

(отсутствуют)
