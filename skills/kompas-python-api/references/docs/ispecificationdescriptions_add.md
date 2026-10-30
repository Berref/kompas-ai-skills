# Add - Добавить новое описание спецификации в документ и в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescriptions ](ispecificationdescriptions.html) > [ISpecificationDescriptions - методы ](ispecificationdescriptions_methods.html) |  Scroll [ [ [ ](ispecificationsectionstyles.html "К следующему разделу")](ispecificationdescriptions_methods.html "На уровень выше")](ispecificationdescriptions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescriptions.html)

Синтаксис Automation:

LPDISPATCH Add (BSTR LayoutName,

long StyleID,

BSTR SpcName,

ISpecificationDescription);

Синтаксис COM:

HRESULT Add ([in] BSTR LayoutName,

[in] long StyleID,

[in] BSTR SpcName,

[out, retval] ISpecificationDescription** Result);

Входные параметры:

LayoutName | \- имя библиотеки стилей,  
---|---  
StyleID | \- номер стиля в библиотеке стилей,  
SpcName | \- имя документа спецификации, связанного с описанием спецификации в документе.  
  
Возвращаемое значение:

| \- Указатель на интерфейс [ISpecificationDescription](ispecificationdescription.html) описания спецификации.  
---|---  
  
Примечание:

К одному документу могут быть добавлены описания спецификации только разных стилей. Если LayoutName и StyleID не заданы, то добавляется описание спецификации по умолчанию, если оно не было создано ранее.

Подразделы:

(отсутствуют)
