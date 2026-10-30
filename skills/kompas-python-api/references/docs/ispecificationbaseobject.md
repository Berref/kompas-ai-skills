# Интерфейс ISpecificationBaseObject

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationbaseobject_props.html "К следующему разделу")](spec_work.html "На уровень выше")](igroupobjectsmanager_getgroupobjectsgeometry.html "К предыдущему разделу")  
---|---  
  
Интерфейс базового объекта спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationObject](ispecificationobject.html)

[ISpecificationBaseObject](ispecificationbaseobject.html)

Описание:

Интерфейс позволяет получить и изменить параметры для базовых объектов спецификации. Для базовых объектов предусмотрена возможность автоматического заполнения колонок, сортировки, подключения графических объектов из сборочного чертежа, подключения деталей из сборки и т.д.

Примечание:

1\. После изменения параметров объекта спецификации требуется вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

2\. Данный интерфейс можно получить у коллекции базовых объектов спецификации [ISpecificationBaseObjects](ispecificationbaseobjects.html).

Подразделы:

[ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html)

[ISpecificationBaseObject - методы ](ispecificationbaseobject_methods.html)
