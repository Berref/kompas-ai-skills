# AddProjectionOf - Добавить в эскиз проекцию объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_addsketch.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_addintersectionof.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

VARIANT AddProjectionOf( IModelObject * Object );

Синтаксис COM:

HRESULT AddProjectionOf( IModelObject * Object, VARIANT * Result );

Возвращаемое значение:

| \- Массив созданных проекционных объектов в виде в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

Object | \- указатель на интерфейс [IModelObject](imodelobject.html).  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
