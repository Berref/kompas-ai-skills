# IsSuitableObject - Проверка пригодности объекта для операции

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) |  Scroll [ [ [ ](ilinearpattern.html "К следующему разделу")](ifeaturepattern_methods.html "На уровень выше")](ifeaturepattern_isinitialobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Синтаксис Automation:

BOOL IsSuitableObject( IModelObject * Object );

Синтаксис COM:

HRESULT IsSuitableObject( IModelObject * Object, BOOL * Result );

Входные параметры:

Object | \- указатель на объект [IModelObject.](imodelobject.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- указанный объект можно скопировать с помощью данной операции.  
---|---  
  
Подразделы:

(отсутствуют)
