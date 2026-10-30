# Интерфейс ISpecificationBaseObjects

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationbaseobjects_props.html "К следующему разделу")](spec_work.html "На уровень выше")](iattacheddocuments_adddocument.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции базовых объектов спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationBaseObjects](ispecificationbaseobjects.html)

Описание:

Позволяет получить список базовых объектов спецификации.

Примечание:

1\. Управляет массивом интерфейсов [ISpecificationBaseObject](ispecificationbaseobject.html).

2\. Коллекция позволяет создать новые базовые объекты спецификации. Для создания нового базового объекта спецификации используется метод [Add](ispecificationbaseobjects_add.html). После вызова метода Add объект будет добавлен в коллекцию, но в документе не появится.

3\. Для отображения объекта в документе нужно задать его параметры и вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

4\. Данный интерфейс можно получить от интерфейса описания спецификации [ISpecificationDescription](ispecificationdescription.html) с помощью свойства [ISpecificationDescription::BaseObjects](ispecificationdescription_baseobjects.html).

Подразделы:

[ISpecificationBaseObjects - свойства ](ispecificationbaseobjects_props.html)

[ISpecificationBaseObjects - методы ](ispecificationbaseobjects_methods.html)
