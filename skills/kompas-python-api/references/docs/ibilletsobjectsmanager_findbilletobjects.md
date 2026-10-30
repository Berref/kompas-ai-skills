# FindBilletObjects - Получить список заготовок

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IBilletsObjectsManager](ibilletsobjectsmanager.html) > [IBilletsObjectsManager - методы](ibilletsobjectsmanager_methods.html) |  Scroll [ [ [ ](ibilletsobjectsmanager_findparentforbilletobject.html "К следующему разделу")](ibilletsobjectsmanager_methods.html "На уровень выше")](ibilletsobjectsmanager_addbilletobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibilletsobjectsmanager.html)

Синтаксис Automation:

VARIANT FindBilletObjects( ISpecificationBaseObject * ParentObject );

Синтаксис COM:

HRESULT FindBilletObjects( ISpecificationBaseObject* ParentObject, VARIANT* Result );

Возвращаемое значение:

| \- Объекты заготовки в виде массива SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

ParentObject | \- базовый объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html)  
---|---  
  
Подразделы:

(отсутствуют)
