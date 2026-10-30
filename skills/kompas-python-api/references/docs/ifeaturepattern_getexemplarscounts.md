# GetExemplarsCounts - Получить количество экземпляров

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) |  Scroll [ [ [ ](ifeaturepattern_isinitialobject.html "К следующему разделу")](ifeaturepattern_methods.html "На уровень выше")](ifeaturepattern_destroy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Синтаксис Automation:

BOOL GetExemplarsCounts( long * Count1, long * Count2 );

Синтаксис COM:

HRESULT GetExemplarsCounts( long * Count1, long * Count2, BOOL * Result );

Выходные параметры:

Count1 | \- количество экземпляров в первом направлении копирования,  
---|---  
Count2 | \- количество экземпляров во втором направлении копирования.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Два направления копирования имеют массивы по сетке и по концентрической сетке.

Для массивов остальных типов Count2 равен 1.

Подразделы:

(отсутствуют)
