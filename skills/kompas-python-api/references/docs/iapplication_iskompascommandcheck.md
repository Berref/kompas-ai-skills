# IsKompasCommandCheck - Проверить, нажата ли кнопка команды

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_messageboxex.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_iskompascommandenable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

long IsKompasCommandCheck (long commandID);

Синтаксис COM:

HRESULT IsKompasCommandCheck (long commandID, long * retVal);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

1 | \- кнопка нажата,  
---|---  
0 | \- кнопка отжата.  
  
Подразделы:

(отсутствуют)
