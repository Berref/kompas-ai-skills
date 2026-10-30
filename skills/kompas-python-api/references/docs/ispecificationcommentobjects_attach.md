# Attach - Добавить вспомогательный объект спецификации в коллекцию прикрепленных объектов (Для базового объекта)

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationCommentObjects ](ispecificationcommentobjects.html) > [ISpecificationCommentObjects - методы ](ispecificationcommentobjects_methods.html) |  Scroll [ [ [ ](ispecificationcommentobjects_copyspecificationobject.html "К следующему разделу")](ispecificationcommentobjects_methods.html "На уровень выше")](ispecificationcommentobjects_addwithparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcommentobjects.html)

Синтаксис Automation:

BOOL Attach( LPDISPATCH spcObj );

Синтаксис COM:

HRESULT Attach ([in]ISpecificationCommentObject* spcObj,

[out, retval] BOOL* PRes);

Входные параметры:

spcObj | \- указатель на интерфейс прикрепляемого вспомогательного объекта спецификации.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод работает только для коллекции взятой у базового объекта СП.

Подразделы:

(отсутствуют)
