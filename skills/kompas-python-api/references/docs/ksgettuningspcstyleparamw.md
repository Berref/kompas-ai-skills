# ksGetTuningSpcStyleParamW - Получить параметры настройки спецификации документа (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetwidthcolumnspc.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgettuningspcstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetTuningSpcStyleParam](ksspecification_ksgettuningspcstyleparam.html).

Синтаксис:

int ksGetTuningSpcStyleParamW (reference pDoc,

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

3\. Для документа-спецификации настройки можно заменить всегда; для графического документа: в случае, если документ подключен к спецификации или включен режим "Спецификация на листе"; для 3d документа: в случае, если документ подключен к спецификации.

4\. При использовании ANSI следует использовать функцию [ksGetTuningSpcStyleParam](ksgettuningspcstyleparam.html).

Подразделы:

(отсутствуют)
