# GetComplexPropertyValue - Получить значение составного свойства

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_setcomplexpropertyvalue.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_iscomplexpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

BSTR GetComplexPropertyValue( IProperty * Property, BOOL * FromSource );

Синтаксис COM:

HRESULT GetComplexPropertyValue( IProperty * Property, BOOL * FromSource, BSTR * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Property | \- интерфейс свойства.  
---|---  
  
Выходные параметры:

FromSource | \- признак получения значения свойства из источника.  
---|---  
  
Подразделы:

(отсутствуют)
