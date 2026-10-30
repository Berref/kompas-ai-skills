# ksTransferReference - Преобразовать объект по reference из API5 в интерфейсный объект API7

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](pumpwaitingmessages.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kstransferinterface.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [KompasObject::TransferReference](kompasobject_transferreference.html).

Синтаксис:

LPUNKNOWN ksTransferReference( reference obj, reference doc );

Входные параметры:

obj | \- указатель на объект в API5,  
---|---  
doc | \- указатель на документ, где находится объект.  
  
Возвращаемое значение:

| \- указатель на интерфейс объекта в API7 (Тип данных:LPUNKNOWN).  
---|---  
  
Описание:

Функция позволяет получить интерфейс объекта в API7 по присланному указателю obj в API5.

Примечание:

1\. Функция реализована для документов и объектов вида графического документа. В остальных случаях возвращается NULL.

2\. Если obj - указатель на документ, параметр doc игнорируется.

3\. Если параметр doc = 0, берется текущий документ.

Подразделы:

(отсутствуют)
