# Интерфейс IParts7

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) |  Scroll [ [ [ ](iparts7_props.html "К следующему разделу")](bc2609111.html "На уровень выше")](icomponentpositioner7_setdragpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции компонентов 3D документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObjects](imodelobjects.html)

[IParts7](iparts7.html)

Примечание:

1\. Данный интерфейс можно получить от интерфейса [IPart7](ipart7.html), используя свойство [IPart7::Parts](ipart7_parts.html).

2\. Данный интерфейс можно получить от интерфейса [IModelObjects](imodelobjects.html), используя метод IUnknown QueryInterface.

3\. От интерфейса 3D-документа [IKompasDocument3D](ikompasdocument3d.html) может быть получен верхний компонент [IKompasDocument3D::TopPart](ikompasdocument3d_toppart.html), а от полученного верхнего компонента [IPart7](ipart7.html) может быть получена коллекция компонентов [IParts7](iparts7.html) с помощью свойства [IPart7::Parts](ipart7_parts.html). Элементы коллекции-компоненты могут быть получены у коллекции с помощью свойства [IParts7::Part](iparts7_part.html). Либо с помощью свойства [IModelObjects::Item](imodelobjects_item.html) как объекты типа [IModelObject](imodelobject.html) с последующим приведением к типу [IPart7](ipart7.html) через QueryInterface. От каждого элемента коллекции-компонента может быть получена вложенная коллекция компонентов c помощью свойства [IPart7::Parts](ipart7_parts.html). И так далее, пока имеются вложенные коллекции компонентов.

Подразделы:

[IParts7 - свойства ](iparts7_props.html)

[IParts7 - методы ](iparts7_methods.html)
