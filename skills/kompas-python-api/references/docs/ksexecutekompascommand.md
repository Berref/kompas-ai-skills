# ksExecuteKompasCommand - Выполнить команду системы КОМПАС

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksgetexternalinterface.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksenableundo.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [KompasObject::ksExecuteKompasCommand](kompasobject_ksexecutekompascommand.html).

Синтаксис:

int LIB_FUNC ksExecuteKompasCommand (long commandID, int post);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html),  
---|---  
post | \- способ запуска команды: 1 - запуск команды через PostMessage, 0 - через SendMessage.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Проверить доступность команды можно с помощью функции [ksIsKompasCommandEnable](ksiskompascommandenable.html).

2\. Проверить, нажата ли в данный момент кнопка команды, можно с помощью [ksIsKompasCommandCheck](ksiskompascommandcheck.html).

Подразделы:

(отсутствуют)
