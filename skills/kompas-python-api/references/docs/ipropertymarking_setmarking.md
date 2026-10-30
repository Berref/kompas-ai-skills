# SetMarking - Обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMarking ](ipropertymarking.html) > [IPropertyMarking - методы ](ipropertymarking_methods.html) |  Scroll [ [ [ ](ipropertybmplist.html "К следующему разделу")](ipropertymarking_methods.html "На уровень выше")](ipropertymarking_getmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymarking.html)

Синтаксис Automation:

BOOL SetMarking( ksVariantMarkingTypeEnum MarkingType, BSTR Marking );

Синтаксис COM:

HRESULT SetMarking( ksVariantMarkingTypeEnum MarkingType, BSTR Marking, BOOL * Result );

Входные параметры:

MarkingType | \- индекс части обозначения из перечисления [ksVariantMarkingTypeEnum,](ksvariantmarkingtypeenum.html)  
---|---  
Marking | \- текст обозначения.  
  
Примечание:

При передаче полного обозначения части обозначения нужно разделить разделителями |$

Подразделы:

(отсутствуют)
