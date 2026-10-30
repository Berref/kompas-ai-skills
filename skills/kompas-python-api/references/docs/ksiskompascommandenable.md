# ksIsKompasCommandEnable - Проверить доступность выполнения команды

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksismodule2dactive.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksiskompascommandcheck.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [KompasObject::ksIsKompasCommandEnable](kompasobject_ksiskompascommandenable.html).

Синтаксис:

int LIB_FUNC ksIsKompasCommandEnable (long commandID);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html),  
---|---  
post | \- способ запуска команды: 1 - запуск команды через PostMessage, 0 - через SendMessage.  
  
Возвращаемое значение:

1 | \- команда доступна,  
---|---  
0 | \- команда недоступна.  
  
Примечание:

1\. Проверить доступность команды можно с помощью функции [ksIsKompasCommandEnable](ksiskompascommandenable.html).

2\. Проверить, нажата ли в данный момент кнопка команды, можно с помощью [ksIsKompasCommandCheck](ksiskompascommandcheck.html).

Подразделы:

(отсутствуют)
