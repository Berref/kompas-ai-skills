# ksSetCurrentSpcObject - Установить текущий объект спецификации по указателю на него либо по его индексу

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcdescription.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetapplylibraryspcstyle.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation - метод [ksSetCurrentSpcObject](ksspecification_kssetcurrentspcobject.html).

Синтаксис:

long ksSetCurrentSpcObject (long spcObj, long index);

Входные параметры:

spcObj | \- указатель на объект,  
---|---  
index | \- индекс объекта.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод работает для видимых таблиц спецификации.

Подразделы:

(отсутствуют)
