# Apply - Применить набор

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Сборка ](bc3308967.html) > [Интерфейс ILoadCombination ](iloadcombination.html) > [ILoadCombination - методы ](iloadcombination_methods.html) |  Scroll [ [ [ ](iloadcombination_applyex.html "К следующему разделу")](iloadcombination_methods.html "На уровень выше")](iloadcombination_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iloadcombination.html)

Синтаксис Automation:

BOOL Apply( VARIANT loadCombinationIndex )

Синтаксис COM:

HRESULT Apply([in] VARIANT loadCombinationIndex, [out, retval] BOOL * Value );

Входные параметры:

loadCombinationIndex | \- тип VARIANT - индекс набора или имя набора.  
---|---  
  
Возвращаемое значение:

TRUE | \- набор успешно применен,  
---|---  
FALSE | \- не применен.  
  
Примечание:

1\. Метод позволяет применить набор с заданным именем или индексом.

2\. Набор становится текущим, что позволит открывать документ с таким набором по умолчанию.

Подразделы:

(отсутствуют)
