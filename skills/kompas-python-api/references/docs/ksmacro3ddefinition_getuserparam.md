# GetUserParam - Получить параметры пользователя

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_getuserparamsize.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_getuserlibraryname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL GetUserParam (LPDISPATCH userPars);

Выходные параметры:

userPars | \- указатель на интерфейс пользовательских параметров [ksUserParam](ksuserparam.html).  
---|---  
  
Синтаксис COM:

BOOL GetUserParam (void *value,

unsigned int size);

Входные параметры:

value | \- указатель на пользовательскую структуру параметров,  
---|---  
size | \- размер структуры параметров.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Способ получения пользовательских данных (userPars) должен совпадать со способом их сохранения (void*, SAFEARRAY, или [DynamicArray](ksdynamicarray.html)) через [ksMacro3DDefinition::SetUserParam](ksmacro3ddefinition_setuserparam.html).

– Если пользовательские данные были сохранены через SAFEARRAY (userPars), то перед их получением нужно создать SAFEARRAY соответствующего размера (размер данных можно определить при помощи [ksMacro3DDefinition::GetUserParamSize](ksmacro3ddefinition_getuserparamsize.html)).

– Если пользовательские данные были сохранены через [ksUserParam::SetUserArray](ksuserparam_setuserarray.html), то перед их получением нужно создать UserArray, аналогичный по структуре используемому при сохранении, и передать его в [ksUserParam::SetUserArray](ksuserparam_setuserarray.html).

Подразделы:

(отсутствуют)
