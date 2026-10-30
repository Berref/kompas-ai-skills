# UserSelectEntityEx2 - Запустить процесс выбора объекта (позволяет использовать Панель свойств)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_zoomprevnextorall.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_userselectentityex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH UserSelectEntityEx2(LPDISPATCH filterObject,

BSTR methodName, BSTR prompt,

VARIANT hInst, [defaultvalue(0)]LPDISPATCH val, [defaultvalue(0)]LPUNKNOWN processParam );

Входные параметры:

filterObject | \- указатель на объект по умолчанию, который будет подсвечен при запуске процесса,  
---|---  
methodName | \- название функции фильтрации или NULL,  
prompt | \- строка подсказки или NULL,  
hInst | \- hInstance модуля, в котором находится функция фильтрации,  
val | \- интерфейс, в котором находится функция фильтрации, если hInstance не доступен,  
processParam | \- параметры процесса [IProcessParam](iprocessparam.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FАLSE | \- в случае неудачи.  
  
Аналог функции в COM см. [IRequestInfo3D::SetCallBack](ksrequestinfo3d_setcallback.html).

Тип функции фильтрации:

bool WINAPI SELECTFILTERPROC (LPDISPATCH _entity)

Пользователь может указать процессу, подходит ему по каким-то соображениям присланный объект или нет. Если функция фильтрации возвращает TRUE, значит объект подходит, и он будет подсвечен процессом.

Возвращаемое значение:

указатель на интерфейс [IEntity](ksentity.html) объекта, который выделили в процессе выбора | \- в случае успешного завершения,  
---|---  
NULL | \- в случае отказа.  
  
Примечание:

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [ksDocument3D::UserSelectEntityEx](ksdocument3d_userselectentityex.html).

Подразделы:

(отсутствуют)
