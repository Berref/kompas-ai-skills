# DeleteEx - Удалить тип загрузки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_getloadcombinationcomment.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL DeleteEx( VARIANT LoadCombinationIndex,

BSTR Password,

BOOL DeleteDependant );

Синтаксис COM:

HRESULT DeleteEx( VARIANT LoadCombinationIndex,

BSTR Password,

BOOL DeleteDependant,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

LoadCombinationIndex | \- индекс типа загрузки,  
---|---  
Password | \- пароль,  
DeleteDependant | \- TRUE - с подчиненными типами загрузки,  
| \- FALSE - без подчиненных.  
  
Подразделы:

(отсутствуют)
