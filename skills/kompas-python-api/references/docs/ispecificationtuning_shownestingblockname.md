# ShowNestingBlockName - Показывать имя вложенного блока

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_showperformanceblockname.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_showlistcountissameformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

ShowNestingBlockName = iObject.ShowNestingBlockName | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowNestingBlockName = ShowNestingBlockName | Установить свойство ([* ](1.html))  
ShowNestingBlockName = iObject.GetShowNestingBlockName() | Получить свойство ([**](2.html))  
iObject.SetShowNestingBlockName (ShowNestingBlockName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowNestingBlockName (&ShowNestingBlockName) | Получить свойство  
---|---  
iObject->put_ShowNestingBlockName (ShowNestingBlockName) | Установить свойство  
  
Значения свойства:

TRUE | \- имена вложенных блоков показываются в таблице спецификации,  
---|---  
FALSE | \- имена вложенных блоков не показываются в таблице спецификации.  
  
Примечание:

Позволяет включать и отключать показ в таблице спецификации заголовков блоков вложенных разделов и пустых строк вокруг них.

Подразделы:

(отсутствуют)
