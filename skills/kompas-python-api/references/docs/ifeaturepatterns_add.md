# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePatterns ](ifeaturepatterns.html) > [IFeaturePatterns - методы ](ifeaturepatterns_methods.html) |  Scroll [ [ [ ](ifeaturepattern.html "К следующему разделу")](ifeaturepatterns_methods.html "На уровень выше")](ifeaturepatterns_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum Type );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum Type, IFeaturePattern ** Result );

Выходные параметры:

Type | \- тип объекта [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Возвращаемое значение:

\- указатель на интерфейс [IFeaturePattern.](ifeaturepattern.html)  
---  
  
В зависимости от типа объекта создается [операция копирования определенного типа](copytype.html).

Подразделы:

(отсутствуют)
