# SetCallBack - Изменить имя (в Automation) или адрес (в COM) функции обратной связи процесса

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](ksrequestinfo3d_setcallbackex.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](irequestinfo_gettitle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetCallBack (BSTR methodName,

long hInst,

LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- имя функции,  
---|---  
hInst | \- HINSTANCE модуля, в котором находится функция,  
dispatchOCX | \- интерфейс, в котором находится функция.  
  
Синтаксис COM:

BOOL SetCallBack (USERSELECTCALLBACKPROC callBack);

Входной параметр:

callBack | \- адрес функции.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Тип функции обратной связи для выбора объекта:

typedef int (__stdcall * USERSELECTCALLBACKPROC)(LPENTITY, LPREQUESTINFO);

Прототип CallBack-функции:

Синтаксис Automation (пример для Visual C):

int WINAPI SELECTCALLBACKPROC (LPDISPATCH entity,

LPDISPATCH info);

Синтаксис COM:

int __stdcall SelectCallBackProc (LPENTITY entity, LPREQUESTINFO info);

Входные параметры:

entity | \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
info | \- указатель на интерфейс [kIsRequestInfo3D](ksrequestinfo3d.html) или [IRequestInfo](ksrequestinfo3d.html).  
  
Функция вызывается по нажатию кнопки мыши на подсвеченном объекте.

Получить доступ к массиву объектов, указываемых в процессе, можно вызовом метода [GetEntityCollection](ksrequestinfo3d_getentitycollection.html) у параметра info.

Если входной параметр entity равен 0, то в процессе была указана точка и рекомендуется заполнить массив нулевыми указателями.

Если entity не равен 0, то при необходимости можно добавить данный объект в массив.

CallBack-функция должна вернуть 1, если содержимое массива выбранных элементов было изменено (в этом случае будет обновлена подсветка выбранных объектов в модели), и 0, если массив не изменился (в модели никаких изменений не произойдет).

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64.Рекомендуется использовать функцию [ksRequestInfo3D::SetCallBackEx.](ksrequestinfo3d_setcallbackex.html)

Подразделы:

(отсутствуют)
