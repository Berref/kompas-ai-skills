# FindCommonName - Найти объект общее наименование для заданного объекта

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ICommonNamesManager](icommonnamesmanager.html) > [ICommonNamesManager - методы](icommonnamesmanager_methods.html) |  Scroll [ [ [ ](icommonnamesmanager_isenablecreatecommonname.html "К следующему разделу")](icommonnamesmanager_methods.html "На уровень выше")](icommonnamesmanager_addcommonname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icommonnamesmanager.html)

Синтаксис Automation:

LPDISPATCH FindCommonName( ISpecificationBaseObject * ParentObject );

Синтаксис COM:

HRESULT FindCommonName( ISpecificationBaseObject * ParentObject, ICommonNameObject * * Result );;

Возвращаемое значение:

| \- Объект спецификации - Общее наименование [ICommonNameObject](icommonnameobject.html).  
---|---  
  
Входные параметры:

ParentObject | \- базовый объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Подразделы:

(отсутствуют)
