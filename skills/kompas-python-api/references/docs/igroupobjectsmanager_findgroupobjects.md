# FindGroupObjects - Получить список сгруппированных объектов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IGroupObjectsManager](igroupobjectsmanager.html) > [IGroupObjectsManager - методы](igroupobjectsmanager_methods.html) |  Scroll [ [ [ ](igroupobjectsmanager_findgroupobject.html "К следующему разделу")](igroupobjectsmanager_methods.html "На уровень выше")](igroupobjectsmanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](igroupobjectsmanager.html)

Синтаксис Automation:

VARIANT FindGroupObjects( ISpecificationBaseObject * ParentGroupObject );

Синтаксис COM:

HRESULT FindGroupObjects( ISpecificationBaseObject * ParentGroupObject, VARIANT * Result );

Возвращаемое значение:

| \- Базовые объекты в виде массива SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

ParentGroupObject | \- групповой объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Подразделы:

(отсутствуют)
