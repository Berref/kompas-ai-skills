# GetObjectLinkPropertyValue - Получить значение свойства в исполнении

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - методы ](iproductdatamanager_methods.html) |  Scroll [ [ [ ](iproductdatamanager_getobjectpropertyvalue.html "К следующему разделу")](iproductdatamanager_methods.html "На уровень выше")](iproductdatamanager_findproductobjectbygeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Синтаксис Automation:

BOOL GetObjectLinkPropertyValue( IPropertyKeeper * PropObject, IPropertyKeeper * EmbodimentObject, BSTR PropertyPath, VARIANT * Value, BOOL * FromSource );

Синтаксис COM:

HRESULT GetObjectLinkPropertyValue( IPropertyKeeper * PropObject, IPropertyKeeper * EmbodimentObject, BSTR PropertyPath, VARIANT * Value, BOOL * FromSource, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PropObject |  \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html),  
---|---  
EmbodimentObject | \- указатель на объект исполнения в СЧИ [IPropertyKeeper](ipropertykeeper.html),  
PropertyPath | \- строковый идентификатор свойства.  
  
Выходные параметры:

Value |  \- значение свойства,  
---|---  
FromSource | \- значение было получено из источника.  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
