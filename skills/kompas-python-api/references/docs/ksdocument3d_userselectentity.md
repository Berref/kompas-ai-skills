# UserSelectEntity - Запустить процесс выбора объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_userselectentityex.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_usergetplacementandentity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH UserSelectEntity (LPDISPATCH defObject,

LPCTSTR methodName,

LPCTSTR prompt,

long hInstance,

LPDISPATCH dispatchOCX);

Входные параметры:

defObject | \- указатель на объект по умолчанию, который будет подсвечен при запуске процесса,  
---|---  
methodName | \- название функции фильтрации или NULL,  
prompt | \- строка подсказки или NULL,  
hInstance | \- hInstance модуля, в котором находится функция фильтрации,  
dispatchOCX | \- интерфейс, в котором находится функция фильтрации, если hInstance не доступен.  
  
Тип функции фильтрации:

bool WINAPI SELECTFILTERPROC (LPDISPATCH _entity)

Пользователь может указать процессу, подходит ему по каким-то соображениям присланный объект или нет. Если функция фильтрации возвращает TRUE, значит, объект подходит, и он будет подсвечен процессом.

Возвращаемое значение:

указатель на интерфейс [ksEntity](ksentity.html) объекта, который выделили в процессе выбора | \- в случае успешного завершения,  
---|---  
NULL | \- в случае отказа.  
  
Синтаксис COM:

LPENTITY UserSelectEntity (LPENTITY defObject,

USERSELECTFILTERPROC methodName,

LPOLESTR prompt);

Входные параметры:

defObject | \- указатель на объект по умолчанию, который будет подсвечен при запуске процесса,  
---|---  
methodName | \- название функции фильтрации или NULL,  
prompt | \- строка приглашения или NULL.  
  
Тип функции фильтрации:

typedef BOOL (__stdcall * USERSELECTFILTERPROC)(LPENTITY);

Пользователь может указать процессу, подходит ему по каким-то соображениям присланный объект или нет. Если функция фильтрации возвращает TRUE, значит, объект подходит, и он будет подсвечен процессом.

Возвращаемое значение:

указатель на интерфейс [IEntity](ksentity.html) объекта, который выделили в процессе выбора | \- в случае успешного завершения,  
---|---  
NULL | \- в случае отказа.  
  
Подразделы:

(отсутствуют)
