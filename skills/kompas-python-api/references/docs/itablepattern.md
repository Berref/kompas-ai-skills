# Интерфейс ITablePattern

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) |  Scroll [ [ [ ](itablepattern_props.html "К следующему разделу")](ifeaturepattern_methods.html "На уровень выше")](ipointdrivenpattern_issuitabledrivenobject.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров массива по таблице.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IFeaturePattern](ifeaturepattern.html)

[ITablePattern](itablepattern.html)

[ILocalCSObject](ilocalcsobject.html)

Интерфейс используется для операций:

o3d_TablePattern | 522 | Массив операций по таблице из файла  
---|---|---  
o3d_PartsTablePattern | 523 | Массив компонентов по таблице из файла  
o3d_AuxTablePattern | 524 | Массив вспомогательной геометрии по таблице из файла  
o3d_BodiesTablePattern | 525 | Массив тел по таблице из файла  
  
Интерфейс можно получить в коллекции массивов [IFeaturePatterns](ifeaturepatterns.html).

С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[ITablePattern - свойства ](itablepattern_props.html)
