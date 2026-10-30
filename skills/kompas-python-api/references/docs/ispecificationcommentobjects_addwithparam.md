# AddWithParam - Добавить новый объект спецификации в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationCommentObjects ](ispecificationcommentobjects.html) > [ISpecificationCommentObjects - методы ](ispecificationcommentobjects_methods.html) |  Scroll [ [ [ ](ispecificationcommentobjects_attach.html "К следующему разделу")](ispecificationcommentobjects_methods.html "На уровень выше")](ispecificationcommentobjects_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcommentobjects.html)

Синтаксис Automation:

LPDISPATCH AddWithParam( ISpecificationObjectCreateParam * Param, ISpecificationBaseObject * ParentObject );

Синтаксис COM:

HRESULT AddWithParam( ISpecificationObjectCreateParam * Param, ISpecificationBaseObject * ParentObject, ISpecificationCommentObject * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ISpecificationCommentObject](ispecificationcommentobject.html) вспомогательного объекта спецификации.  
---|---  
  
Входные параметры:

Param | \- Указатель на интерфейс расширенных параметров создания объекта спецификации [ISpecificationObjectCreateParam](ispecificationobjectcreateparam.html).  
---|---  
ParentObject | \- Указатель на базовый объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html), для которого добавляется комментарий.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
