# SpecificationDocumentName - Имя подключенного файла документа спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_specificationstyle.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_showexcludedobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BSTR

Синтаксис Automation:

DocumentName = iObject.SpecificationDocumentName | Получить свойство ([* ](1.html))  
---|---  
iObject.SpecificationDocumentName = DocumentName | Установить свойство ([* ](1.html))  
DocumentName = iObject.GetSpecificationDocumentName() | Получить свойство ([**](2.html))  
iObject.SetSpecificationDocumentName (DocumentName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SpecificationDocumentName (&DocumentName) | Получить свойство  
---|---  
iObject->put_SpecificationDocumentName (DocumentName) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить и установить полное имя файла документа спецификации подключенной к данному чертежу или сборке. Доступно только для чертежа или сборки.

2\. После изменения параметров оформления нужно вызвать метод [Update](ispecificationdescription_update.html), чтобы новые данные вступили в силу.

Подразделы:

(отсутствуют)
