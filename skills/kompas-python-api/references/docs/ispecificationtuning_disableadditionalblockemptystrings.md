# DisableAdditionalBlockEmptyStrings - Запретить вывод пустых строк вокруг начала дополнительного блока

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_disablenestingblockemptystrings.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_disableemptyblockstring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DisableAdditionalBlockEmptyStrings = iObject.DisableAdditionalBlockEmptyStrings | Получить свойство ([* ](1.html))  
---|---  
iObject.DisableAdditionalBlockEmptyStrings = DisableAdditionalBlockEmptyStrings | Установить свойство ([* ](1.html))  
DisableAdditionalBlockEmptyStrings = iObject.GetDisableAdditionalBlockEmptyStrings() | Получить свойство ([**](2.html))  
iObject.SetDisableAdditionalBlockEmptyStrings (DisableAdditionalBlockEmptyStrings) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DisableAdditionalBlockEmptyStrings (&DisableAdditionalBlockEmptyStrings) | Получить свойство  
---|---  
iObject->put_DisableAdditionalBlockEmptyStrings (DisableAdditionalBlockEmptyStrings) | Установить свойство  
  
Значения свойства:

TRUE | \- не показывать пустые строки, обрамляющие название начала дополнительных блоков спецификации,  
---|---  
FALSE | \- показывать пустые строки, обрамляющие название начала дополнительных блоков спецификации.  
  
Примечание:

Позволяет включать и отключать показ пустых строк, обрамляющих название начала дополнительных блоков спецификации.

Подразделы:

(отсутствуют)
