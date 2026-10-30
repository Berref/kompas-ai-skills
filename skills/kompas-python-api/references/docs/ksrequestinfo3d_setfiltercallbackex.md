# SetFilterCallBackEx - Установить функцию обратной связи для фильтрации объектов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](irequestinfo_setmenuid.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](ksrequestinfo3d_setfiltercallback.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetFilterCallBackEx(LPCTSTR methodName, VARIANT hInst, LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- строка с именем функции обратной связи,  
---|---  
hInst | \- идентификатор приложения (dll), в котором реализована CallBack-функция,  
dispatchOCX | \- указатель на интерфейc IDispatch, в котором реализована CallBack-функция.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Аналог функции в COM, см. [IRequestInfo3D::SetFilterCallBack](ksrequestinfo3d_setfiltercallback.html).

Прототип FilterCallBack-функции:

Синтаксис Automation (пример для Visual C):

BOOL WINAPI SELECTFILTERPROC (LPDISPATCH _entity);

Входной параметр:

entity | \- указатель на интерфейс текущего элемента или объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

В данной функции можно отобрать интересующие пользователя элементы или объекты. Функция вызывается при изменении положения курсора, если курсор находится рядом с элементом или объектом модели.

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [ksRequestInfo3D::SetFilterCallBack](ksrequestinfo3d_setfiltercallback.html).

Подразделы:

(отсутствуют)
