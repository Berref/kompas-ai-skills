# Number - Номер колонки данного типа

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_stamplinkid.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: long

Синтаксис Automation:

Number = iObject.Number | Получить свойство ([* ](1.html))  
---|---  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number (&Number) | Получить свойство  
---|---  
  
Примечание:

1\. Данное свойство определяет уникальный номер колонки для колонок с таким же типом. Иногда однородная (но не одинаковая) информация должна храниться в нескольких колонках, и по этой причине они имеют одинаковый тип [ColumnType](ispecificationcolumnstyle_columntype.html) Например, несколько колонок групповой спецификации содержат информацию о количестве, но числа в них разные, т.к. они относятся к разным исполнениям. Чтобы отличать такие колонки, вместе с типом задается еще и номер, отличающий колонку этого типа от других колонок такого же типа. Если разные колонки имеют одинаковый тип, то номера колонок этого типа должны быть разными.

2\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
