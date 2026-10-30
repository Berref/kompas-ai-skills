# Интерфейс IModelObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) |  Scroll [ [ [ ](imodelobject_props.html "К следующему разделу")](bc2229904.html "На уровень выше")](bc2229904.html "К предыдущему разделу")  
---|---  
  
Базовый интерфейс для всех модельных объектов.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

Примечание:

1\. Данный интерфейс является базовым для модельных объектов.

2\. Интерфейс можно получить из коллекции модельных объектов [IModelObjects](imodelobjects.html) с помощью свойства [IModelObjects::Item](imodelobjects_item.html).

3\. Интерфейс может быть получен с помощью метода IUnknown QueryInterface от модельного объекта, например, [IPart7](ipart7.html), [IFeature7](ifeature7.html).

4\. Интерфейс может быть получен от интерфейса [IModelContainer](imodelcontainer.html) с помощью свойства [IModelContainer::Objects](imodelcontainer_objects.html) из массива SAFEARRAY типа VT_ARRAY|VT_DISPATCH с преобразованием от интерфейса IDispatch к IModelObject c помощью метода IUnknown QueryInterface.

5\. Интерфейс может быть получен от интерфейса [IFeature7](ifeature7.html) с помощью свойства [IFeature7::ModelObjects](ifeature7_modelobjects.html) из массива SAFEARRAY типа VT_ARRAY|VT_DISPATCH с преобразованием от интерфейса IDispatch к IModelObject c помощью метода IUnknown QueryInterface.

6\. Имеет дополнительный интерфейс [IColorParam7](icolorparam7.html), который можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IModelObject - свойства ](imodelobject_props.html)

[IModelObject - методы ](imodelobject_methods.html)
