# ShowPerformanceBlockName - Показывать имя блока исполнений

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_showperformancefull.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_shownestingblockname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

ShowPerformanceBlockName = iObject.ShowPerformanceBlockName | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowPerformanceBlockName = ShowPerformanceBlockName | Установить свойство ([* ](1.html))  
ShowPerformanceBlockName = iObject.GetShowPerformanceBlockName() | Получить свойство ([**](2.html))  
iObject.SetShowPerformanceBlockName (ShowPerformanceBlockName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowPerformanceBlockName (&ShowPerformanceBlockName) | Получить свойство  
---|---  
iObject->put_ShowPerformanceBlockName (ShowPerformanceBlockName) | Установить свойство  
  
Значения свойства:

TRUE | \- имена блоков исполнений показываются в таблице спецификации,  
---|---  
FALSE | \- имена блоков исполнений не показываются в таблице спецификации.  
  
Примечание:

Позволяет включать и отключать показ в таблице спецификации заголовков блоков исполнений и пустых строк вокруг них.

Подразделы:

(отсутствуют)
