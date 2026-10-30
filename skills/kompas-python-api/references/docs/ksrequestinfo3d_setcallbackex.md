# SetCallBackEx - Установить функцию обратной связи

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](irequestinfo_setcommandsstring.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](ksrequestinfo3d_setcallback.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetCallBackEx(LPCTSTR methodName, VARIANT hInst, LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- строка с именем функции обратной связи,  
---|---  
hInst | \- идентификатор приложения (dll), в котором реализована CallBack-функция,  
dispatchOCX | \- указатель на интерфейc IDispatch, в котором реализована CallBack-функция.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Аналог функции в COM см. [IRequestInfo3D::SetCallBack](ksrequestinfo3d_setcallback.html).

Прототип FilterCallBack-функции:

Синтаксис Automation (пример для Visual C):

int WINAPI SELECTCALLBACKPROC(LPDISPATCH entity, LPDISPATCH info);

Входной параметр:

entity | \- указатель на интерфейс текущего элемента или объекта [ksEntity](ksentity.html),  
---|---  
info | \- указатель на интерфейс [ksRequestInfo3D](ksrequestinfo3d.html).  
  
Примечание:

Функция вызывается по нажатию кнопки мыши на подсвеченном объекте.

Получить доступ к массиву объектов, указываемых в процессе, можно вызовом метода [GetEntityCollection](ksrequestinfo3d_getentitycollection.html) у параметра info.

•Если входной параметр entity равен 0, то в процессе была указана точка и рекомендуется заполнить массив нулевыми указателями.

•Если entity не равен 0, то при необходимости можно добавить данный объект в массив.

CallBack-функция должна вернуть:

•1, если содержимое массива выбранных элементов было изменено (в этом случае будет обновлена подсветка выбранных объектов в модели).

•0, если массив не изменился (в модели никаких изменений не произойдет).

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [ksRequestInfo3D::SetCallBack](ksrequestinfo3d_setcallback.html).

Подразделы:

(отсутствуют)
