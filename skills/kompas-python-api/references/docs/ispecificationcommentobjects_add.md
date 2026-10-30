# Add - Добавить новый вспомогательный объект спецификации в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationCommentObjects ](ispecificationcommentobjects.html) > [ISpecificationCommentObjects - методы ](ispecificationcommentobjects_methods.html) |  Scroll [ [ [ ](ispecificationcommentobjects_addwithparam.html "К следующему разделу")](ispecificationcommentobjects_methods.html "На уровень выше")](ispecificationcommentobjects_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcommentobjects.html)

Синтаксис Automation:

LPDISPATCH Add (long Section);

Синтаксис COM:

HRESULT Add ([in] long Section,

[out, retval] ISpecificationCommentObject** Result );

Входные параметры:

Section | \- номер раздела.  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс [ISpecificationCommentObject](ispecificationcommentobject.html) вспомогательного объекта спецификации.  
---|---  
  
Примечание:

После вызова метода Add объект будет добавлен в коллекцию, но в документе не появится. Для отображения объекта в документе нужно задать его параметры и вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
