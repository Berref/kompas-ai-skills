# SetObjectPropertyValue - Установить значение свойства по строковому идентификатору в метаданных

[API интерфейсов. Версия 7](applicate.html) > [Дерево СЧИ ](ct1473974.html) > [Интерфейс IProductDataManager ](iproductdatamanager.html) > [IProductDataManager - методы ](iproductdatamanager_methods.html) |  Scroll [ [ [ ](cj1473974.html "К следующему разделу")](iproductdatamanager_methods.html "На уровень выше")](iproductdatamanager_setobjectlinkpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproductdatamanager.html)

Синтаксис Automation:

BOOL SetObjectPropertyValue( IPropertyKeeper * PropObject, BSTR PropertyPath, VARIANT Value );

Синтаксис COM:

HRESULT SetObjectPropertyValue( IPropertyKeeper * PropObject, BSTR PropertyPath, VARIANT Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PropObject |  \- указатель на объект СЧИ [IPropertyKeeper](ipropertykeeper.html),  
---|---  
PropertyPath | \- строковый идентификатор свойства,  
Value | \- значение свойства.  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
