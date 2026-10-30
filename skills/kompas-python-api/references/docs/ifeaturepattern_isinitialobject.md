# IsInitialObject - Проверка: является ли объект исходным для массива

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) |  Scroll [ [ [ ](ifeaturepattern_issuitableobject.html "К следующему разделу")](ifeaturepattern_methods.html "На уровень выше")](ifeaturepattern_getexemplarscounts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Синтаксис Automation:

BOOL IsInitialObject( IModelObject * Object );

Синтаксис COM:

HRESULT IsInitialObject( IModelObject * Object, BOOL * Result );

Входные параметры:

Object | \- указатель на объект [IModelObject.](imodelobject.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- если объект есть в списке копируемых объектов.  
---|---  
  
Подразделы:

(отсутствуют)
