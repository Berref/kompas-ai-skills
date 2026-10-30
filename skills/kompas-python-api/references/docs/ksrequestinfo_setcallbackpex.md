# SetCallBackPEx - Установить имя функции обратной связи для процесса Placement

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - методы ](ksrequestinfo_methods.html) |  Scroll [ [ [ ](ksrequestinfo_setcursortext.html "К следующему разделу")](ksrequestinfo_methods.html "На уровень выше")](ksrequestinfo_setcallbackp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Синтаксис Automation:

BOOL SetCallBackPEx(LPCTSTR methodName, VARIANT hInst, LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- строка с именем функции обратной связи,  
---|---  
hInst | \- идентификатор приложения (dll), в котором реализована CallBack-функция,  
dispatchOCX | \- указатель на интерфейc IDispatch, в котором реализована CallBack-функция.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [ksRequestInfo::SetCallBackP](ksrequestinfo_setcallbackp.html).

Подразделы:

(отсутствуют)
