# SetSection - Установить номер раздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationCommentObject ](ispecificationcommentobject.html) > [ISpecificationCommentObject - методы ](ispecificationcommentobject_methods.html) |  Scroll [ [ [ ](ispecificationdescription.html "К следующему разделу")](ispecificationcommentobject_methods.html "На уровень выше")](ispecificationcommentobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcommentobject.html)

Синтаксис Automation:

BOOL SetSection( long Val );

Синтаксис COM:

HRESULT SetSection( long Val, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

Val | \- номер раздела.  
---|---  
  
Примечание:

Задаваемый номер раздела должен присутствовать в данной спецификации.

Узнавать текущий номер раздела объекта надо у базового интерфейса [ISpecificationObject](ispecificationobject.html).

Подразделы:

(отсутствуют)
