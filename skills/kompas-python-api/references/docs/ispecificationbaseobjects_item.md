# Item - Базовый объект спецификации, заданный по индексу, по уникальному идентификатору или по уникальному номеру

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObjects ](ispecificationbaseobjects.html) > [ISpecificationBaseObjects - свойства ](ispecificationbaseobjects_props.html) |  Scroll [ [ [ ](ispecificationbaseobjects_methods.html "К следующему разделу")](ispecificationbaseobjects_props.html "На уровень выше")](ispecificationbaseobjects_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobjects.html)

Тип данных: Указатель на интерфейс [ISpecificationBaseObject](ispecificationbaseobject.html) объекта спецификации

Синтаксис Automation:

spcObj = iObject.Item (Index) | Получить свойство ([* ](1.html))  
---|---  
spcObj = iObject.GetItem (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (Index, &spcObj) | Получить свойство  
---|---  
  
Примечание:

1\. С помощью данного свойства можно получить базовый объект спецификации, заданный по индексу, по уникальному идентификатору [IKompasAPIObject::Reference](ikompasapiobject_reference.html) или уникальному номеру [ISpecificationObject::UniqueNumber](ispecificationobject_uniquenumber.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
