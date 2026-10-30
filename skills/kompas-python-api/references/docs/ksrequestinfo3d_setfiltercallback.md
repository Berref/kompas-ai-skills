# SetFilterCallBack - Изменить имя (в Automation) или адрес (в COM) функции обратной связи для фильтрации объектов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - методы ](ksrequestinfo3d_methods.html) |  Scroll [ [ [ ](ksrequestinfo3d_setfiltercallbackex.html "К следующему разделу")](ksrequestinfo3d_methods.html "На уровень выше")](irequestinfo_setdynamicfiltering.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Синтаксис Automation:

BOOL SetFilterCallBack (BSTR methodName,

long hInst,

LPDISPATCH dispatchOCX);

Входные параметры:

methodName | \- имя функции,  
---|---  
hInst | \- HINSTANCE модуля, в котором находится функция,  
dispatchOCX | \- интерфейс, в котором находится функция.  
  
Синтаксис COM:

BOOL SetFilterCallBack (USERSELECTFILTERPROC callBack);

Входной параметр:

callBack | \- адрес функции.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Тип функции обратной связи для фильтрации объекта (функции-«фильтра»)

typedef BOOL (__stdcall * USERSELECTFILTERPROC)(LPENTITY);

Прототип FilterCallBack-функции:

Синтаксис Automation (пример для Visual C):

BOOL WINAPI SELECTFILTERPROC (LPDISPATCH _entity);

Синтаксис COM:

BOOL __stdcall SelectFilterProc (LPENTITY entity);

Входной параметр:

entity | \- указатель на интерфейс текущего элемента или объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- объект будет подсвечен.  
---|---  
  
В данной функции можно отобрать интересующие пользователя элементы или объекты. Функция вызывается при изменении положения курсора, если курсор находится рядом с элементом или объектом модели.

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64.

Рекомендуется использовать функцию [ksRequestInfo3D::SetFilterCallBackEx](ksrequestinfo3d_setfiltercallbackex.html).

Подразделы:

(отсутствуют)
