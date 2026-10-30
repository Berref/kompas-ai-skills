# UseAdditionalBlocks - Использовать блоки дополнительных разделов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_usertextstyle.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_supportperformance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

UseAdditionalBlocks = iObject.UseAdditionalBlocks | Получить свойство ([* ](1.html))  
---|---  
iObject.UseAdditionalBlocks = UseAdditionalBlocks | Установить свойство ([* ](1.html))  
UseAdditionalBlocks = iObject.GetUseAdditionalBlocks() | Получить свойство ([**](2.html))  
iObject.SetUseAdditionalBlocks (UseAdditionalBlocks) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UseAdditionalBlocks (&UseAdditionalBlocks) | Получить свойство  
---|---  
iObject->put_UseAdditionalBlocks (UseAdditionalBlocks) | Установить свойство  
  
Значения свойства:

TRUE | \- использовать блоки дополнительных разделов,  
---|---  
FALSE | \- блоки дополнительных разделов использоваться не будут.  
  
Примечание:

Позволяет получить\изменить возможность использования блоков дополнительных разделов. Если значение свойства - TRUE, при создании объектов в спецификации доступны блоки дополнительных разделов.

Подразделы:

(отсутствуют)
