# AddPropertyFromLibrary - Добавить свойство из библиотеки в список правил

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IFormatLabelRules ](iformatlabelrules.html) > [IFormatLabelRules - методы ](iformatlabelrules_methods.html) |  Scroll [ [ [ ](iformatlabelrules_clear.html "К следующему разделу")](iformatlabelrules_methods.html "На уровень выше")](iformatlabelrules_addpropertybyid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iformatlabelrules.html)

Синтаксис Automation:

BOOL AddPropertyFromLibrary( long IndexAt, BSTR FileName, double PropertyId, BOOL Use, BSTR Prefix );

Синтаксис COM:

HRESULT AddPropertyFromLibrary( long IndexAt, BSTR FileName, double PropertyId, BOOL Use, BSTR Prefix, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

IndexAt | \- индекс добавляемой настройки,  
---|---  
FileName | \- имя файла библиотеки,  
PropertyId | \- указатель на интерфейс описания свойства [IProperty](iproperty.html),  
Use | \- признак использования,  
Prefix | \- префикс.  
  
Подразделы:

(отсутствуют)
