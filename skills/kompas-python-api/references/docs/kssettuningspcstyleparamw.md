# ksSetTuningSpcStyleParamW - Установить параметры настроек спецификации документа (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcchangevalue.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssettuningspcstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetTuningSpcStyleParam](ksspecification_kssettuningspcstyleparam.html).

Синтаксис:

int ksSetTuningSpcStyleParamW (reference pDoc,

int index,

SpcTuningStyleParamW * par);

Входные параметры:

pDoc | \- указатель на документ,  
---|---  
index | \- индекс описания спецификации в документе,  
par | \- структура параметров [SpcTuningStyleParamW](structspctuningstyleparamw.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если pDoc == 0, то изменяются параметры настроек для текущего документа;

2\. Если index == -1, то изменяются параметры настроек текущего описания спецификации;

3\. Для документа-спецификации настройки можно заменить всегда;

4\. Для графического документа настройки можно заменить в случае, если документ подключен к спецификации или включен режим "Спецификация на листе";

5\. Для документа-модели настройки можно заменить в случае, если документ подключен к спецификации.

6\. При использовании ANSI следует использовать функцию [ksSetTuningSpcStyleParam](kssettuningspcstyleparam.html).

Подразделы:

(отсутствуют)
