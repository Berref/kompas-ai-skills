# Интерфейс IPart7

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) |  Scroll [ [ [ ](ipart7_props.html "К следующему разделу")](bc2609111.html "На уровень выше")](iparts7_saveasdetail.html "К предыдущему разделу")  
---|---  
  
Интерфейс компонента 3D документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IPart7](ipart7.html)

[IFeature7](ifeature7.html)

[ISourcePart7Params](isourcepart7params.html)

[ISheetMetalContainer](isheetmetalcontainer.html)

[IModelContainer](imodelcontainer.html)

[IMassInertiaParam7](imassinertiaparam7.html)

[ISymbols3DContainer](isymbols3dcontainer.html)

[IAuxiliaryGeomContainer](iauxiliarygeomcontainer.html)

[IModelObjectNotifyResult](imodelobjectnotifyresult.html)

[IPropertyKeeper](ipropertykeeper.html)

[ISurfaceContainer](isurfacecontainer.html)

Описание:

Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы компонента:

•интерфейс объекта Дерева построения [IFeature7](ifeature7.html),

•интерфейс параметров компонента в источнике [ISourcePart7Params](isourcepart7params.html).

•интерфейс контейнера объектов гибки [ISheetMetalContainer](isheetmetalcontainer.html),

•интерфейс контейнера трехмерных объектов [IModelContainer](imodelcontainer.html),

•интерфейс массово-центровочных характеристик [IMassInertiaParam7](imassinertiaparam7.html).

•интерфейс контейнера условных обозначений в [3D ISymbols3DContainer](isymbols3dcontainer.html),

•интерфейс контейнера объектов вспомогательной геометрии [IAuxiliaryGeomContainer](iauxiliarygeomcontainer.html),

•интерфейс контейнера поверхностей [ISurfaceContainer](isurfacecontainer.html),

•интерфейс результатов редактирования 3D объекта [IModelObjectNotifyResult](imodelobjectnotifyresult.html),

•интерфейс получения/редактирования значения свойств [IPropertyKeeper,](ipropertykeeper.html)

•интерфейс контейнера объектов измерений и диагностики [IMeasurementContainer](imeasurementcontainer.html).

Примечание.

1\. Компонент может быть получен от интерфейса коллекции компонентов [IParts7](iparts7.html).

2\. Компонент может быть получен от интерфейса [IModelObject](imodelobject.html) или [IFeature7](ifeature7.html),используя метод IUnknown QueryInterface.

3\. Верхний компонент может быть получен от интерфейса 3D-документа [IKompasDocument3D](ikompasdocument3d.html) с помощью свойства [IKompasDocument3D::TopPart](ikompasdocument3d_toppart.html).

4\. От интерфейса 3D-документа [IKompasDocument3D](ikompasdocument3d.html) может быть получен верхний компонент [IKompasDocument3D::TopPart](ikompasdocument3d_toppart.html), а от полученного верхнего компонента [IPart7](ipart7.html) может быть получена коллекция компонентов [IParts7](iparts7.html) с помощью свойства [IPart7::Parts](ipart7_parts.html). Элементы коллекции-компоненты могут быть получены у коллекции с помощью свойства [IParts7::Part](iparts7_part.html). Либо с помощью свойства [IModelObjects::Item](imodelobjects_item.html) как объекты типа [IModelObject](imodelobject.html) с последующим приведением к типу [IPart7](ipart7.html) через QueryInterface. От каждого элемента коллекции-компонента может быть получена вложенная коллекция компонентов c помощью свойства [IPart7::Parts](ipart7_parts.html). И так далее, пока имеются вложенные коллекции компонентов.

Подразделы:

[IPart7 - свойства ](ipart7_props.html)

[IPart7 - методы ](ipart7_methods.html)
