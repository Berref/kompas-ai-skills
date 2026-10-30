# ksConnectionAdvise - Подписаться на событие

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с событиями ](events_fncts_common.html) |  Scroll [ [ [ ](ksconnectionunadvise.html "К следующему разделу")](events_fncts_common.html "На уровень выше")](events_fncts_common.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int ksConnectionAdvise (NotifyConnectionParam * param, LPUNKNOWN object);

Входные параметры:

param | \- указатель на [структуру параметров подписки на события](structnotifyconnectionparam.html),  
---|---  
object | \- указатель интерфейса событий.  
  
Возвращаемое значения:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Система выполнит AddRef на object и запомнит в текущей библиотеке или в текущей notify-библиотеке.

Подразделы:

(отсутствуют)
