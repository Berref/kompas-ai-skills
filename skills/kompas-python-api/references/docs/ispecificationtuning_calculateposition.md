# CalculatePosition - Режим расчета позиций

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_calculatezone.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_blockonnewpage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

CalculatePosition = iObject.CalculatePosition | Получить свойство ([* ](1.html))  
---|---  
iObject.CalculatePosition = CalculatePosition | Установить свойство ([* ](1.html))  
CalculatePosition = iObject.GetCalculatePosition() | Получить свойство ([**](2.html))  
iObject.SetCalculatePosition (CalculatePosition) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CalculatePosition (&CalculatePosition) | Получить свойство  
---|---  
iObject->put_CalculatePosition (CalculatePosition) | Установить свойство  
  
Значения свойства:

TRUE | \- расчет позиций автоматически (после каждой сортировки) не происходит,  
---|---  
FALSE | \- расчет позиций происходит автоматически.  
  
Примечание:

Позволяет включить или отключить расчет позиций (то есть присвоение объектам новых номеров позиций после того, как нумерация нарушилась в результате автоматической сортировки или удаления объектов).

Подразделы:

(отсутствуют)
