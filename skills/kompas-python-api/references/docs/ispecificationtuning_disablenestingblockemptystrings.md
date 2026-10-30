# DisableNestingBlockEmptyStrings - Запретить вывод пустых строк вокруг начала вложенного блока

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_drawbottomup.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_disableadditionalblockemptystrings.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DisableNestingBlockEmptyStrings = iObject.DisableNestingBlockEmptyStrings | Получить свойство ([* ](1.html))  
---|---  
iObject.DisableNestingBlockEmptyStrings = DisableNestingBlockEmptyStrings | Установить свойство ([* ](1.html))  
DisableNestingBlockEmptyStrings = iObject.GetDisableNestingBlockEmptyStrings() | Получить свойство ([**](2.html))  
iObject.SetDisableNestingBlockEmptyStrings (DisableNestingBlockEmptyStrings) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DisableNestingBlockEmptyStrings (&DisableNestingBlockEmptyStrings) | Получить свойство  
---|---  
iObject->put_DisableNestingBlockEmptyStrings (DisableNestingBlockEmptyStrings) | Установить свойство  
  
Значения свойства:

TRUE | \- не показывать пустые строки, обрамляющие название начала вложенных блоков спецификации,  
---|---  
FALSE | \- показывать пустые строки, обрамляющие название начала вложенных блоков спецификации.  
  
Примечание:

Позволяет включать и отключать показ пустых строк, обрамляющих название начала вложенных блоков спецификации.

Подразделы:

(отсутствуют)
