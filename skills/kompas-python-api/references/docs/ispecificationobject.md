# Интерфейс ISpecificationObject

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationobject_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationdescription_update.html "К предыдущему разделу")  
---|---  
  
Интерфейс объекта спецификации.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[ISpecificationObject](ispecificationobject.html)

Описание:

Различаются несколько типов объектов спецификации (см. [ksSpecificationObjectTypeEnum](ksspecificationobjecttypeenum.html)). Данный интерфейс позволяет получить общие параметры для объектов спецификации и изменить общие параметры для базовых и вспомогательных объектов спецификации.

Примечание:

1\. После изменения параметров объекта спецификации требуется вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

2\. Данный интерфейс можно получить у базового [ISpecificationBaseObject](ispecificationbaseobject.html) и вспомогательного [ISpecificationCommentObject](ispecificationcommentobject.html) объектов спецификации и через безопасный массив [ISpecificationDescription::Objects](ispecificationdescription_objects.html) для остальных типов объектов спецификации.

Подразделы:

[ISpecificationObject - свойства ](ispecificationobject_props.html)

[ISpecificationObject - методы ](ispecificationobject_methods.html)
