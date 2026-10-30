# UpdateByModel - Обновить по текущему состоянию модели

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iopendocumentparam.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_setpassword.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL UpdateByModel( VARIANT LoadCombinationIndex, BSTR Password );

Синтаксис COM:

HRESULT UpdateByModel( VARIANT LoadCombinationIndex, BSTR Password, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

LoadCombinationIndex | \- индекс типа загрузки,  
---|---  
Password | \- пароль.  
  
Подразделы:

(отсутствуют)
