# ksExecuteKompasCommand - Выполнить команду системы КОМПАС

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksexecutekompaslibrarycommand.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecdialspecialsymbol.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksExecuteKompasCommand](ksexecutekompascommand.html).

Синтаксис Automation:

BOOL ksExecuteKompasCommand (long commandID, BOOL post);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html),  
---|---  
post | \- true - запуск команды через PostMessage, \- false - через SendMessage.  
  
Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

1\. Проверить доступность команды можно с помощью функции [KompasObject::ksIsKompasCommandEnable](kompasobject_ksiskompascommandenable.html).

2\. Проверить, нажата ли в данный момент кнопка команды, можно с помощью [KompasObject::ksIsKompasCommandCheck](kompasobject_ksiskompascommandcheck.html).

Подразделы:

(отсутствуют)
