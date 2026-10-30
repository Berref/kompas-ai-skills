# Интерфейс ISpecificationDescriptions

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](ispecificationdescriptions_props.html "К следующему разделу")](spec_work.html "На уровень выше")](ispecificationcommentobjects_detach.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции описаний спецификации у документа.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ISpecificationDescriptions](ispecificationdescriptions.html)

Примечание:

1\. Для документа-спецификации возможно только одно описание, и оно есть всегда (т.е. добавлять и удалять нельзя).

2\. В текстовом документе описаний нет.

3\. Для остальных документов (чертеж, фрагмент, деталь и сборка) описаний может быть сколько угодно, в том числе и ни одного.

4\. При добавлении нового описания оно становится текущим.

5\. Данный интерфейс может быть получен следующими способами:

•от интерфейса документа [IKompasDocument](ikompasdocument.html) с помощью свойства [IKompasDocument::SpecificationDescriptions](ikompasdocument_specificationdescriptions.html),

•от интерфейса чертежа [IDrawingDocument](idrawingdocument.html) с помощью свойства [IDrawingDocument::ChangeListDescriptions](idrawingdocument_changelistdescriptions.html).

Подразделы:

[ISpecificationDescriptions - свойства ](ispecificationdescriptions_props.html)

[ISpecificationDescriptions - методы ](ispecificationdescriptions_methods.html)
