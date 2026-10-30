# FindParentForBilletObject - Получить владельца для заготовки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IBilletsObjectsManager](ibilletsobjectsmanager.html) > [IBilletsObjectsManager - методы](ibilletsobjectsmanager_methods.html) |  Scroll [ [ [ ](icommonnameobject.html "К следующему разделу")](ibilletsobjectsmanager_methods.html "На уровень выше")](ibilletsobjectsmanager_findbilletobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibilletsobjectsmanager.html)

Синтаксис Automation:

LPDISPATCH FindParentForBilletObject( ISpecificationBaseObject * BilletObject );

Синтаксис COM:

HRESULT FindParentForBilletObject( ISpecificationBaseObject* BilletObject, ISpecificationBaseObject** Result );

Возвращаемое значение:

| \- Базовый объект спецификации, для которого создана заготовка [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Входные параметры:

BilletObject | \- объект-заготовка [ISpecificationBaseObject](ispecificationbaseobject.html)  
---|---  
  
Подразделы:

(отсутствуют)
