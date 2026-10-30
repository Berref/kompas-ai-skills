# BlockOnNewPage - Располагать блок на новой странице

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_calculateposition.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_blockcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

BlockOnNewPage = iObject.BlockOnNewPage | Получить свойство ([* ](1.html))  
---|---  
iObject.BlockOnNewPage = BlockOnNewPage | Установить свойство ([* ](1.html))  
BlockOnNewPage = iObject.GetBlockOnNewPage() | Получить свойство ([**](2.html))  
iObject.SetBlockOnNewPage (BlockOnNewPage) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BlockOnNewPage (&BlockOnNewPage) | Получить свойство  
---|---  
iObject->put_BlockOnNewPage (BlockOnNewPage) | Установить свойство  
  
Значения свойства:

TRUE | \- располагать блок на новой странице,  
---|---  
FALSE | \- располагать блок сразу за предыдущим.  
  
Примечание:

Позволяет указать, требуется ли располагать начала всех блоков на новых листах спецификации.

Подразделы:

(отсутствуют)
