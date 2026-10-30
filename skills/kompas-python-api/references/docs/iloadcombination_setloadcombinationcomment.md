# SetLoadCombinationComment - Установить комментарий

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_setloadcombinationname.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_getloadcombinationname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL SetLoadCombinationComment( VARIANT LoadCombinationIndex,

BSTR NewVal,

BSTR Password );

Синтаксис COM:

HRESULT SetLoadCombinationComment( VARIANT LoadCombinationIndex,

BSTR NewVal,

BSTR Password,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

LoadCombinationIndex | \- индекс типа загрузки,  
---|---  
NewVal | \- строка с комментарием,  
Password | \- пароль.  
  
Подразделы:

(отсутствуют)
