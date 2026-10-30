# ksConnectionUnAdvise - Снять подписку на событие

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с событиями ](events_fncts_common.html) |  Scroll [ [ [ ](cn1743685.html "К следующему разделу")](events_fncts_common.html "На уровень выше")](ksconnectionadvise.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int ksConnectionUnadvise (NotifyConnectionParam * param);

Входные параметры:

param | \- указатель на [структуру параметров подписки на события](structnotifyconnectionparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Для текущей библиотеки или текущей notify-библиотеки выполнит Release на соответствующий указатель событий.

Подразделы:

(отсутствуют)
