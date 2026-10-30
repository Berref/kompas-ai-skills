# ExecuteKompasCommand - Выполнить команду системы КОМПАС

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_getsystemversion.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_createpropertymanager.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

BOOL ExecuteKompasCommand (long commandID, BOOL post);

Синтаксис COM:

HRESULT ExecuteKompasCommand (long commandID, BOOL post, BOOL * retval);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
post | \- true - запуск команды через PostMessage, \- false - через SendMessage.  
  
Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

1\. Проверить доступность команды можно с помощью функции [IApplication::IsKompasCommandEnable](iapplication_iskompascommandenable.html).

2\. Проверить, нажата ли в данный момент кнопка команды, можно с помощью [IApplication::IsKompasCommandCheck](iapplication_iskompascommandcheck.html).

Подразделы:

(отсутствуют)
