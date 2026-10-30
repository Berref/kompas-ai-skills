# IsEnableCreateCommonName - Проверить возможность создания объекта общее наименование для заданного объекта

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ICommonNamesManager](icommonnamesmanager.html) > [ICommonNamesManager - методы](icommonnamesmanager_methods.html) |  Scroll [ [ [ ](igroupobjectsmanager.html "К следующему разделу")](icommonnamesmanager_methods.html "На уровень выше")](icommonnamesmanager_findcommonname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icommonnamesmanager.html)

Синтаксис Automation:

ksCreateCommonNameState IsEnableCreateCommonName( ISpecificationBaseObject * BaseObject );

Синтаксис COM:

HRESULT IsEnableCreateCommonName( ISpecificationBaseObject * BaseObject, ksCreateCommonNameState * Result );

Возвращаемое значение:

| \- Признак доступности создания объекта общее наименование из перечисления [ksCreateCommonNameState](kscreatecommonnamestate.html).  
---|---  
  
Входные параметры:

BaseObject | \- базовый объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Подразделы:

(отсутствуют)
