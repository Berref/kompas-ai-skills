# Delete - Удалить набор

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_deleteex.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_create.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL Delete( VARIANT loadCombinationIndex )

Синтаксис COM:

HRESULT Delete([in] VARIANT loadCombinationIndex, [out, retval] BOOL * result );

Входные параметры:

loadCombinationIndex | \- тип VARIANT - индекс набора или имя набора.  
---|---  
  
Возвращаемое значение:

TRUE | \- удален,  
---|---  
FALSE | \- не удален.  
  
Примечание:

Метод позволяет удалить пользовательский набор с заданным именем или индексом.

Подразделы:

(отсутствуют)
