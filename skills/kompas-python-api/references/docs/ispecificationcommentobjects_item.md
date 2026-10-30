# Item - Вспомогательный объект спецификации, заданный по индексу, по уникальному идентификатору или по уникальному номеру

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationCommentObjects ](ispecificationcommentobjects.html) > [ISpecificationCommentObjects - свойства ](ispecificationcommentobjects_props.html) |  Scroll [ [ [ ](ispecificationcommentobjects_methods.html "К следующему разделу")](ispecificationcommentobjects_props.html "На уровень выше")](ispecificationcommentobjects_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcommentobjects.html)

Тип данных: Указатель на интерфейс [ISpecificationCommentObject](ispecificationcommentobject.html) объекта спецификации.

Синтаксис Automation:

spcObj = iObject.Item (Index) | Получить свойство ([* ](1.html))  
---|---  
spcObj = iObject.GetItem (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (Index, &spcObj) | Получить свойство  
---|---  
  
Примечание:

1\. С помощью данного свойства можно получить вспомогательный объект спецификации, заданный по индексу, по уникальному идентификатору [IKompasAPIObject::Reference](ikompasapiobject_reference.html) или уникальному номеру [ISpecificationObject::UniqueNumber](ispecificationobject_uniquenumber.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
