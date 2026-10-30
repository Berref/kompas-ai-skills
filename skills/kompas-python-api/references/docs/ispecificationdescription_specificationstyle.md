# SpecificationStyle - Стиль спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_specificationtuning.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_specificationdocumentname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: указатель на интерфейс [ISpecificationStyle](ispecificationstyle.html) cтиля спецификации

Синтаксис Automation:

Style = iObject.SpecificationStyle | Получить свойство ([* ](1.html))  
---|---  
Style = iObject.GetSpecificationStyle() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SpecificationStyle( &Style ) | Получить свойство  
---|---  
  
Примечание:

1\. Полученный интерфейс отражает содержимое стиля в библиотеке стилей для данного описания на момент получения и в дальнейшем не отслеживает изменений в библиотеке стилей.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
