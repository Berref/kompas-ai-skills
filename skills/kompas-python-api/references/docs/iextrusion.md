# Интерфейс IExtrusion

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) |  Scroll [ [ [ ](iextrusion_props.html "К следующему разделу")](bc2279073.html "На уровень выше")](isurfacethickenings_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс операции выдавливания.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IExtrusion](iextrusion.html)

[IChooseBodies7](ichoosebodies7.html)

[IThinParameters](ithinparameters.html)

[ICutExtrusion](icutextrusion.html)

[IExtrusion1](iextrusion1.html)

Примечание.

1\. Интерфейс можно получить с помощью метода коллекции операций выдавливания [IExtrusions::Add](iextrusions_add.html) или свойства [IExtrusions::Extrusion](iextrusions_extrusion.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить следующие дополнительный интерфейсы:

•[IChooseBodies7](ichoosebodies7.html) \- интерфейс для области применения тел в операции,

•[IThinParameters](ithinparameters.html) \- интерфейс параметров тонкой стенки,

•[ICutExtrusion](icutextrusion.html) \- интерфейс операции "Вырезать выдавливанием",

•[IExtrusion1](iextrusion1.html) \- интерфейс параметров элемента выдавливания.

Подразделы:

[IExtrusion - свойства ](iextrusion_props.html)

[IExtrusion - методы ](iextrusion_methods.html)
