# GetPropertyValue - Получить значение свойства

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_getuserdatastoragesmanager.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_getpropertyadditionalstorage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

BOOL GetPropertyValue( LPDISPATCH Property, VARIANT * Value, BOOL BaseUnit, BOOL * FromSource );

Синтаксис COM:

HRESULT GetPropertyValue(IProperty* Property, VARIANT * Value, BOOL BaseUnit, BOOL * FromSource, BOOL * Result );

Входные параметры:

Property | \- интерфейс свойства,  
---|---  
BaseUnit | \- TRUE - значение в базовых единицах измерения (СИ), \- FALSE - в настроенных единицах измерения,  
  
Выходные параметры:

FromSource | \- хранилище было получено из источника,  
---|---  
Value | \- значение свойства.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
