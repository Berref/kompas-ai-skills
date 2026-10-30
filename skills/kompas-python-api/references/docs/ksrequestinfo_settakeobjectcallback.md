# SetTakeObjectCallBack - Установить функцию обратной связи для подчиненного процесса

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - методы ](ksrequestinfo_methods.html) |  Scroll [ [ [ ](ksplacementparam.html "К следующему разделу")](ksrequestinfo_methods.html "На уровень выше")](ksrequestinfo_setcursortext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Синтаксис Automation:

BOOL SetTakeObjectCallBack(LPCTSTR methodName, VARIANT hInst, LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- строка с именем функции обратной связи,  
---|---  
hInst | \- идентификатор приложения (dll), в котором реализована CallBack-функция,  
dispatchOCX | \- указатель на интерфейc IDispatch, в котором реализована CallBack-функция.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Прототип CallBack-функции:

Синтаксис Automation (пример для Visual C):

BOOL WINAPI TakeObjectCallBack(LPDISPATCH _object);

Входной параметр:

_object | \- указатель на интерфейс объекта [ksEntity](ksentity.html) для подпроцессов создания объектов, \- указатель на интерфейс сопряжения [ksMateConstraint](ksmateconstraint.html) для подпроцессов создания сопряжений.  
---|---  
  
Синтаксис COM:

BOOL SetTakeProcessObject (USERTAKEOBJECTCALLBACKPROC callBack);

Входной параметр:

callBack | \- адрес функции.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Тип функции обратной связи для подчиненного процесса

typedef BOOL (__stdcall * USERTAKEOBJECTCALLBACKPROC)(LPUNKNOWN);

Прототип CallBack-функции:

Синтаксис COM:

BOOL __stdcall SelectFilterProc (LPUNKNOWN _object );

Входной параметр:

_object | \- указатель на интерфейс объекта [ksEntity](ksentity.html) для подпроцессов создания объектов, \- указатель на интерфейс сопряжения [ksMateConstraint](ksmateconstraint.html) для подпроцессов создания сопряжений.  
---|---  
  
Примечание:

Функция вызывается при завершении подпроцесса создания\редактирования подчиненного объекта

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

Подразделы:

(отсутствуют)
