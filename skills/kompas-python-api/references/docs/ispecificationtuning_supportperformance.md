# SupportPerformance - Поддержка исполнений в спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_useadditionalblocks.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_showsectionname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

SupportPerformance = iObject.SupportPerformance | Получить свойство ([* ](1.html))  
---|---  
iObject.SupportPerformance = SupportPerformance | Установить свойство ([* ](1.html))  
SupportPerformance = iObject.GetSupportPerformance() | Получить свойство ([**](2.html))  
iObject.SetSupportPerformance (SupportPerformance) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SupportPerformance (&SupportPerformance) | Получить свойство  
---|---  
iObject->put_SupportPerformance (SupportPerformance) | Установить свойство  
  
Значения свойства:

TRUE | \- исполнения поддерживаются в спецификации,  
---|---  
FALSE | \- исполнения не поддерживаются в спецификации.  
  
Примечание:

Позволяет определить требуется ли в спецификации создавать объекты-исполнения.

Подразделы:

(отсутствуют)
