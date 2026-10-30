# GetSystemVersion - Получить версию системы

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_iskompascommandenable.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_executekompascommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

BOOL IsKompasCommandEnable (long commandID);

Синтаксис COM:

HRESULT GetSystemVersion( long * Major, long * Minor, long * Release, long * Build, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

iMajor | \- старшее слово версии,  
---|---  
iMinor | \- младшее слово версии,  
iRelease | \- номер выпуска внутри одной версии,  
iBuild | \- номер сборки внутри одного выпуска.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
