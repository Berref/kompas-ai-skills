# SetPassword - Установить пароль

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_updatebymodel.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_setloadcombinationname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL SetPassword( VARIANT LoadCombinationIndex,

BSTR OldPassword,

BSTR Password,

BOOL UnprotectUsers );

Синтаксис COM:

HRESULT SetPassword( VARIANT LoadCombinationIndex,

BSTR OldPassword,

BSTR Password,

BOOL UnprotectUsers,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

LoadCombinationIndex | \- индекс типа загрузки,  
---|---  
OldPassword | \- старый пароль,  
Password | \- новый пароль,  
UnprotectUsers | \- TRUE - при удалении пароля системного типа удалять пароли пользовательских типов.  
  
Подразделы:

(отсутствуют)
