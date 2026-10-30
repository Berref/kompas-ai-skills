# Number - Номер блока дополнительных (вложенных) разделов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAdditionalBlockStyle ](iadditionalblockstyle.html) > [IAdditionalBlockStyle - свойства ](iadditionalblockstyle_props.html) |  Scroll [ [ [ ](iadditionalblocktuning.html "К следующему разделу")](iadditionalblockstyle_props.html "На уровень выше")](iadditionalblockstyle_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iadditionalblockstyle.html)

Тип данных: long

Синтаксис Automation:

Number = iObject.Number | Получить свойство ([* ](1.html))  
---|---  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number (&Number) | Получить свойство  
---|---  
  
Примечание:

1\. Блоки разделов в спецификации располагаются в порядке возрастания или убывания их номеров Number, в зависимости от значения свойства [ISpecificationStyle::SortSectionDown](ispecificationstyle_sortsectiondown.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
