# GetPropertyAdditionalStorage - Получить дополнительные данные, связанные со свойством

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_getpropertyvalue.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_setcomplexpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

LPDISPATCH GetPropertyAdditionalStorage( IProperty * Property,

BOOL Create,

BOOL * FromSource );

Синтаксис COM:

HRESULT GetPropertyAdditionalStorage( IProperty * Property,

BOOL Create,

BOOL * FromSource,

IUserDataStorage ** Result );

Возвращаемое значение:

указатель на интерфейс пользовательского хранилища с дополнительными данными для свойства.  
---  
  
Входные параметры:

Property | \- указатель на интерфейс свойства,  
---|---  
Create | \- создавать хранилище, если оно отсутствует.  
  
Выходные параметры:

FromSource | \- хранилище было получено из источника.  
---|---  
  
Примечание:

При первом изменении значения свойства дополнительные данные очищаются автоматически.

Подразделы:

(отсутствуют)
