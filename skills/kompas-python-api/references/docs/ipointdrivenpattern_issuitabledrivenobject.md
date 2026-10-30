# IsSuitableDrivenObject - Проверка пригодности управляющего объекта для операции

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) > [Интерфейс IPointDrivenPattern ](ipointdrivenpattern.html) > [IPointDrivenPattern - методы ](ipointdrivenpattern_methods.html) |  Scroll [ [ [ ](itablepattern.html "К следующему разделу")](ipointdrivenpattern_methods.html "На уровень выше")](ipointdrivenpattern_cleardrivenobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipointdrivenpattern.html)

Синтаксис Automation:

BOOL IsSuitableDrivenObject( IModelObject * Object );

Синтаксис COM:

HRESULT IsSuitableDrivenObject( IModelObject * Object, BOOL * Result );

Входные параметры:

Object | \- управляющий объект для операции.  
---|---  
  
Возвращаемое значение:

TRUE | \- можно добавлять объект Object,  
---|---  
FALSE | \- нельзя добавлять обЪект Object.  
  
Примечание:

Метод проверяет объект Object на возможность использования в качестве управляющего объекта операции.

Подразделы:

(отсутствуют)
