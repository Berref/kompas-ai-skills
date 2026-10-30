# GetUserParam - Возвращает пользовательские параметры, записанные в компоненте

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getuserparamsize.html "К следующему разделу")](kspart_methods.html "На уровень выше")](ipart_getuserlibraryname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL GetUserParam (LPDISPATCH userPars);

Выходной параметр:

userPars | \- указатель на интерфейс пользовательских параметров [ksUserParam](ksuserparam.html).  
---|---  
  
Синтаксис COM:

BOOL GetUserParam (void *value,

unsigned int size);

Входной параметр:

Size | \- размер структуры параметров.  
---|---  
  
Выходной параметр:

Value | \- пользовательская структура параметров.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Способ получения пользовательских данных (userPars) должен совпадать со способом их сохранения (void*, SAFEARRAY, или [DynamicArray](ksdynamicarray.html)) через [ksPart::SetUserParam](kspart_setuserparam.html).

•Если пользовательские данные были сохранены через SAFEARRAY (userPars), то перед их получением нужно создать SAFEARRAY соответствующего размера (размер данных можно определить при помощи [ksPart::GetUserParamSize](kspart_getuserparamsize.html)).

•Если пользовательские данные были сохранены через [ksUserParam::SetUserArray](ksuserparam_setuserarray.html), то перед их получением нужно создать UserArray, аналогичный по структуре используемому при сохранении, и передать его в [ksUserParam::SetUserArray](ksuserparam_setuserarray.html).

Подразделы:

(отсутствуют)
