# Number - Номер раздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationSectionStyle ](ispecificationsectionstyle.html) > [ISpecificationSectionStyle - свойства ](ispecificationsectionstyle_props.html) |  Scroll [ [ [ ](ispecificationsectionstyle_sortcolumnnumber.html "К следующему разделу")](ispecificationsectionstyle_props.html "На уровень выше")](ispecificationsectionstyle_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationsectionstyle.html)

Тип данных: long

Синтаксис Automation:

Number = iObject.Number | Получить свойство ([* ](1.html))  
---|---  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number (&Number) | Получить свойство  
---|---  
  
Примечание:

1\. Данное свойство определяет уникальный номер раздела в данном стиле спецификации.

2\. Разделы в спецификации располагаются в порядке возрастания или убывания их номеров Number, в зависимости от значения свойства [ISpecificationStyle::SortSectionDown](ispecificationstyle_sortsectiondown.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
