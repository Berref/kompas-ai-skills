# Интерфейс ISpecificationCommentObjects

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationcommentobjects_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationcolumnstyles_item.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции вспомогательных объектов спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationCommentObjects](ispecificationcommentobjects.html)

Описание:

Позволяет получить список вспомогательных объектов спецификации.

Примечание:

1\. Управляет массивом интерфейсов [ISpecificationCommentObject](ispecificationcommentobject.html).

2\. Коллекция позволяет создать новые вспомогательные объекты спецификации. Для создания нового вспомогательного объекта спецификации используется метод [Add](ispecificationcommentobjects_add.html). После вызова метода Add объект будет добавлен в коллекцию, но в документе не появится.

3\. Для отображения объекта в документе нужно задать его параметры и вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

4\. Методы [Attach](ispecificationcommentobjects_attach.html) и [Detach](ispecificationcommentobjects_detach.html) работают только для коллекции, взятой у базового объекта СП.

5\. Данный интерфейс можно получить от интерфейса описания спецификации [ISpecificationDescription](ispecificationdescription.html) с помощью свойства [ISpecificationDescription::CommentObjects](ispecificationdescription_commentobjects.html) и от интерфейса базового объекта спецификации [ISpecificationBaseObject](ispecificationbaseobject.html) с помощью свойства [ISpecificationBaseObject_CommentObjects](ispecificationbaseobject_commentobjects.html).

Подразделы:

[ISpecificationCommentObjects - свойства ](ispecificationcommentobjects_props.html)

[ISpecificationCommentObjects - методы ](ispecificationcommentobjects_methods.html)
