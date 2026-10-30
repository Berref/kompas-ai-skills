# SummaryCountText - Суммарное количество для исполнения

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_syncronizewithproperties.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_summarycount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: Указатель на интерфейс [IText](itext.html)

Синтаксис Automation:

SummaryCountText = Object.TemplatePath( ColumnTypeNumber, BlockNumber ) | Получить свойство ([* ](1.html))  
---|---  
SummaryCountText = Object.GetSummaryCountText( ColumnTypeNumber, BlockNumber ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SummaryCountText( DocumentType, DocumentTypeId, &SummaryCountText ) | Получить свойство  
---|---  
  
Входные параметры:

ColumnTypeNumber | \- номер колонки количество,  
---|---  
BlockNumber | \- номер блока исполнений.  
  
Примечание:

•В разных разделах количество может иметь различный тип.

•В разделе Детали, стандартные изделия, например, имеют целочисленное значение. При объединении нескольких объектов спецификации в этом случае количество суммируется.

•В разделе Материал количество строковое, и текст возвращается с объекта, у которого задано не пустое значение.

•В разделе Документация также формируется объединенное значение.

В отличие от [ISpecificationBaseObject::SummaryCount](ispecificationbaseobject_summarycount.html) метод может вернуть не пустое значение для строковых колонок.

Подразделы:

(отсутствуют)
