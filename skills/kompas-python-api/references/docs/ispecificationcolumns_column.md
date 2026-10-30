# Column - Колонка объекта спецификации, заданная по типу, номеру и блоку

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumns ](ispecificationcolumns.html) > [ISpecificationColumns - свойства ](ispecificationcolumns_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyles.html "К следующему разделу")](ispecificationcolumns_props.html "На уровень выше")](ispecificationcolumns_item.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumns.html)

Тип данных: указатель на интерфейс [ISpecificationColumn](ispecificationcolumn.html) колонки объекта спецификации

Синтаксис Automation:

Column = iObject.Column( type, ColumnNumber, BlockNumber ) | Получить свойство ([* ](1.html))  
---|---  
Column = iObject.GetColumn( type, ColumnNumber, BlockNumber ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Column( type, ColumnNumber, BlockNumber, &Column ) | Получить свойство  
---|---  
  
Входные параметры:

type | \- тип колонки объекта спецификации из [ksSpecificationColumnTypeEnum](ksspecificationcolumntypeenum.html),  
---|---  
ColumnNumber | \- номер колонки данного типа,  
BlockNumber | \- номер блока.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
