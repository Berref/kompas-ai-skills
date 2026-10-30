# UserSelectEntityEx - Запустить процесс выбора объекта (позволяет использовать Панель свойств)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_userselectentityex2.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_userselectentity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH UserSelectEntityEx( LPDISPATCH filterObject,

BSTR methodName,

BSTR prompt,

long hInst,

LPDISPATCH val,

LPUNKNOWN processParam );

Входные параметры:

filterObject | \- указатель на объект по умолчанию, который будет подсвечен при запуске процесса,  
---|---  
methodName | \- название функции фильтрации или NULL,  
prompt | \- строка подсказки или NULL,  
hInst | \- hInstance модуля, в котором находится функция фильтрации,  
val | \- интерфейс, в котором находится функция фильтрации, если hInstance не доступен,  
processParam | \- Параметры процесса [IProcessParam](iprocessparam.html).  
  
Тип функции фильтрации:

bool WINAPI SELECTFILTERPROC (LPDISPATCH _entity)

Пользователь может указать процессу, подходит ему по каким-то соображениям присланный объект или нет. Если функция фильтрации возвращает TRUE, значит, объект подходит, и он будет подсвечен процессом.

Возвращаемое значение:

указатель на интерфейс [ksEntity](ksentity.html) объекта, который выделили в процессе выбора | \- в случае успешного завершения,  
---|---  
NULL | \- в случае отказа.  
  
Синтаксис COM:

LPENTITY UserSelectEntityEx(LPENTITY defSelectObject,

void* fnFilter,

LPOLESTR prompt,

LPUNKNOWN processParam );

Входные параметры:

defSelectObject | \- указатель на объект по умолчанию, который будет подсвечен при запуске процесса,  
---|---  
fnFilter | \- название функции фильтрации или NULL,  
prompt | \- строка приглашения или NULL,  
processParam | \- Параметры процесса [IProcessParam](iprocessparam.html).  
  
Тип функции фильтрации:

typedef BOOL (__stdcall * USERSELECTFILTERPROC)(LPENTITY);

Пользователь может указать процессу, подходит ему по каким-то соображениям присланный объект или нет. Если функция фильтрации возвращает TRUE, значит, объект подходит, и он будет подсвечен процессом.

Возвращаемое значение:

указатель на интерфейс [IEntity](ksentity.html) объекта, который выделили в процессе выбора | \- в случае успешного завершения,  
---|---  
NULL | \- в случае отказа.  
  
Примечание:

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64.

Рекомендуется использовать функцию [ksDocument3D::UserSelectEntityEx2.](ksdocument3d_userselectentityex2.html)

Подразделы:

(отсутствуют)
