# AddObject - Создает новый элемент 3D модели

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Контейнер ](bc2278809.html) > [Интерфейс IModelContainer ](imodelcontainer.html) > [IModelContainer - методы ](imodelcontainer_methods.html) |  Scroll [ [ [ ](bc2279073.html "К следующему разделу")](imodelcontainer_methods.html "На уровень выше")](imodelcontainer_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelcontainer.html)

Синтаксис Automation:

LPDISPATCH AddObject( ksObj3dTypeEnum ObjectType );

Синтаксис COM:

HRESULT AddObject( ksObj3dTypeEnum ObjectType, IModelObject * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [IModelObject](imodelobject.html).  
---|---  
  
Входные параметры:

ObjectType | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Подразделы:

(отсутствуют)
