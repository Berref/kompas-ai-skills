# AddPropertyById - Добавить свойство по идентификатору в список правил

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IFormatLabelRules ](iformatlabelrules.html) > [IFormatLabelRules - методы ](iformatlabelrules_methods.html) |  Scroll [ [ [ ](iformatlabelrules_addpropertyfromlibrary.html "К следующему разделу")](iformatlabelrules_methods.html "На уровень выше")](iformatlabelrules_addproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iformatlabelrules.html)

Синтаксис Automation:

BOOL AddPropertyById( long IndexAt, double PropertyId, BOOL Use, BSTR Prefix );

Синтаксис COM:

HRESULT AddPropertyById( long IndexAt, double PropertyId, BOOL Use, BSTR Prefix, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

IndexAt | \- индекс добавляемой настройки,  
---|---  
PropertyId | \- указатель на интерфейс описания свойства [IProperty](iproperty.html),  
Use | \- признак использования,  
Prefix | \- префикс.  
  
Подразделы:

(отсутствуют)
