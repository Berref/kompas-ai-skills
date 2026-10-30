# GetMarking - Обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMarking ](ipropertymarking.html) > [IPropertyMarking - методы ](ipropertymarking_methods.html) |  Scroll [ [ [ ](ipropertymarking_setmarking.html "К следующему разделу")](ipropertymarking_methods.html "На уровень выше")](ipropertymarking_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymarking.html)

Синтаксис Automation:

BSTR GetMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer );

Синтаксис COM:

HRESULT GetMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BSTR * Result );

Входные параметры:

MarkingType | \- индекс части обозначения из перечисления [ksVariantMarkingTypeEnum,](ksvariantmarkingtypeenum.html)  
---|---  
AddSystemDelimer | \- добавлять разделители.  
  
Подразделы:

(отсутствуют)
