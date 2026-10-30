# FindGroupObject - Получить групповой объект спецификации по указателю на экземпляр

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IGroupObjectsManager](igroupobjectsmanager.html) > [IGroupObjectsManager - методы](igroupobjectsmanager_methods.html) |  Scroll [ [ [ ](igroupobjectsmanager_getgroupobjectsgeometry.html "К следующему разделу")](igroupobjectsmanager_methods.html "На уровень выше")](igroupobjectsmanager_findgroupobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](igroupobjectsmanager.html)

Синтаксис Automation:

LPDISPATCH FindGroupObject( ISpecificationBaseObject * BaseObject );

Синтаксис COM:

HRESULT FindGroupObject( ISpecificationBaseObject * BaseObject, ISpecificationBaseObject * * Result );

Возвращаемое значение:

| \- групповой объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Входные параметры:

BaseObject | \- базовый объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Подразделы:

(отсутствуют)
