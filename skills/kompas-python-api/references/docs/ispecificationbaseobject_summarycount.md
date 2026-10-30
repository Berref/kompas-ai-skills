# SummaryCount - Суммарное количество для исполнения

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_summarycounttext.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_spcused.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: double

Синтаксис Automation:

SummaryCount = iObject.SummaryCount( ColumnTypeNumber, BlockNumber ) | Получить свойство ([* ](1.html))  
---|---  
SummaryCount = iObject.GetSummaryCount( ColumnTypeNumber, BlockNumber ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SummaryCount( ColumnTypeNumber, BlockNumber, &SummaryCount ) | Получить свойство  
---|---  
  
Входные параметры:

ColumnTypeNumber | \- номер колонки данного типа,  
---|---  
BlockNumber | \- номер блока исполнений.  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Данное свойство возвращает суммарное значение в колонке "Количество" указанного номера колонки для одинаковых объектов указанного блока исполнений.

Подразделы:

(отсутствуют)
