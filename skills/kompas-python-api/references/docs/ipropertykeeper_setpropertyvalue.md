# SetPropertyValue - Установить значение свойства

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertymng.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_inserthypertextreference.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

BOOL SetPropertyValue( LPDISPATCH Property, VARIANT Value, BOOL BaseUnit );

Синтаксис COM:

HRESULT SetPropertyValue(IProperty* Property, VARIANT Value, BOOL BaseUnit, BOOL * Result );

Входные параметры:

Property | \- интерфейс свойства,  
---|---  
Value | \- значение свойства,  
BaseUnit | -TRUE - значение в базовых единицах измерения (СИ), \- FALSE в настроенных единицах измерения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
