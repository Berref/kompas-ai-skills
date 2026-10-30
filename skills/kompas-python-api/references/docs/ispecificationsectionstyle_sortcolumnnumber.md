# SortColumnNumber - Номер колонки, в которой необходимо проводить сортировку

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationSectionStyle ](ispecificationsectionstyle.html) > [ISpecificationSectionStyle - свойства ](ispecificationsectionstyle_props.html) |  Scroll [ [ [ ](ispecificationsectionstyle_sortcolumnnumberex.html "К следующему разделу")](ispecificationsectionstyle_props.html "На уровень выше")](ispecificationsectionstyle_number.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationsectionstyle.html)

Тип данных: long

Синтаксис Automation:

SortColumnNumber = iObject.SortColumnNumber | Получить свойство ([* ](1.html))  
---|---  
SortColumnNumber = iObject.GetSortColumnNumber() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SortColumnNumber (&SortColumnNumber) | Получить свойство  
---|---  
  
Примечание:

1\. Данное свойство определяет уникальный номер колонки для колонок с типом [SortColumnType](ispecificationsectionstyle_sortcolumntype.html), по которой будет производится сортировка объектов в разделе. Иногда однородная (но не одинаковая) информация должна храниться в нескольких колонках и по этой причине они имеют одинаковый тип [ColumnType](ispecificationcolumnstyle_columntype.html).

Чтобы отличать такие колонки, вместе с типом задается еще и номер, отличающий колонку этого типа от других колонок такого же типа.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
