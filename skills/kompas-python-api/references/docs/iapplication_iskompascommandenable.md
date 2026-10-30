# IsKompasCommandEnable - Проверить доступность выполнения команды

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_iskompascommandcheck.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_getsystemversion.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

BOOL IsKompasCommandEnable (long commandID);

Синтаксис COM:

HRESULT IsKompasCommandEnable (long commandID, BOOL * retVal);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- команда доступна,  
---|---  
FALSE | \- команда недоступна.  
  
Подразделы:

(отсутствуют)
