# SetProcessingGroupObjectsCallBack - Установить имя (в Automation) или адрес (в COM) функции обратной связи для обработки объектов, пришедших при селектировании рамкой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](irequestinfo_setprocessparam.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](ksrequestinfo3d_setobjectsfilter3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetProcessingGroupObjectsCallBack(BSTR methodName, VARIANT hInst, LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- имя функции,  
---|---  
hInst | \- HINSTANCE модуля, в котором находится функция,  
dispatchOCX | \- интерфейс, в котором находится функция.  
  
Синтаксис COM :

BOOL SetProcessingGroupObjectsCallBack(void* callBack);

Входной параметр:

callBack | \- адрес функции.  
---|---  
  
Возвращаемое значение

TRUE | \- в случае успешного завершения.  
---|---  
  
Прототип CallBack-функции:

Синтаксис Automation (пример для Visual C):

BOOL WINAPI USERPROCESSINGGROUPOBJECTS( VARIANT * Objects, long selectionType );

Синтаксис COM:

BOOL __stdcall USERPROCESSINGGROUPOBJECTS( VARIANT * Objects, long selectionType );

Входные параметры:

Objects | \- список объектов массив SafeArray тип VT_ARRAY | VT_DISPATCH в автоматизации; VT_ARRAY | VT_UNKNOWN в COM.  
---|---  
selectionType | \- Тип селектирования из перечисления.  
  
Возвращаемое значение

  
| \- не используется.  
---|---  
  
Примечание

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

Подразделы:

(отсутствуют)
