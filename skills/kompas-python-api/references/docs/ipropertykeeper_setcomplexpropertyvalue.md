# SetComplexPropertyValue - Установить значение составного свойства

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_getpropertyadditionalstorage.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_getcomplexpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

BOOL SetComplexPropertyValue( IProperty * Property, BSTR Value );

Синтаксис COM:

HRESULT SetComplexPropertyValue( IProperty * Property, BSTR Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Property | \- интерфейс свойства,  
---|---  
Value | \- xml-строка с описанием структуры значения составного свойства.  
  
Подразделы:

(отсутствуют)
