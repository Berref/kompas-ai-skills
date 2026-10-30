# SetObjectLinkPropertyValue - Установить значение свойства в исполнении

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - методы ](iproductdatamanager_methods.html) |  Scroll [ [ [ ](iproductdatamanager_setobjectpropertyvalue.html "К следующему разделу")](iproductdatamanager_methods.html "На уровень выше")](iproductdatamanager_getobjectpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Синтаксис Automation:

BOOL SetObjectLinkPropertyValue( IPropertyKeeper * PropObject, IPropertyKeeper * EmbodimentObject, BSTR PropertyPath, VARIANT Value );

Синтаксис COM:

HRESULT SetObjectLinkPropertyValue( IPropertyKeeper * PropObject, IPropertyKeeper * EmbodimentObject, BSTR PropertyPath, VARIANT Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PropObject | \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html),  
---|---  
EmbodimentObject | \- указатель на объект исполнения в СЧИ [IPropertyKeeper](ipropertykeeper.html),  
PropertyPath | \- строковый идентификатор свойства,  
Value | \- значение свойства.  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
