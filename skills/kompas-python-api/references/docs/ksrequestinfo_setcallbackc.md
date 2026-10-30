# SetCallBackC - Установить имя функции обратной связи для процесса Cursor

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - методы ](ksrequestinfo_methods.html) |  Scroll [ [ [ ](ksrequestinfo_setcallbackcex.html "К следующему разделу")](ksrequestinfo_methods.html "На уровень выше")](ksrequestinfo_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Синтаксис Automation:

BOOL SetCallBackC (LPCTSTR methodName,

long hInst,

LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- строка с именем функции обратной связи,  
---|---  
hInst | \- идентификатор приложения (dll), в котором реализована CallBack-функция,  
dispatchOCX | \- указатель на интерфейc IDispatch, в котором реализована CallBack-функция.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Если разрабатываемое приложение dll, тогда заполняется параметр hInst, а dispatchOCX = NULL.

2\. Если разрабатываемое приложение ActiceX DLL, тогда заполняется параметр dispatchOCX, а hInst = 0.

3\. Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64. Рекомендуется использовать функцию [ksRequestInfo::SetCallBackCEx](ksrequestinfo_setcallbackcex.html).

Подразделы:

(отсутствуют)
