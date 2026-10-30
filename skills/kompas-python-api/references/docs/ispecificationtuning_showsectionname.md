# ShowSectionName - Режим отображения заголовков разделов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_supportperformance.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_showperformancefull.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

ShowSectionName = iObject.ShowSectionName | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowSectionName = ShowSectionName | Установить свойство ([* ](1.html))  
ShowSectionName = iObject.GetShowSectionName() | Получить свойство ([**](2.html))  
iObject.SetShowSectionName (ShowSectionName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowSectionName (&ShowSectionName) | Получить свойство  
---|---  
iObject->put_ShowSectionName (ShowSectionName) | Установить свойство  
  
Значения свойства:

TRUE | \- заголовки разделов показываются в таблице спецификации,  
---|---  
FALSE | \- заголовки разделов не показываются в таблице спецификации.  
  
Примечание:

Позволяет включить или отключить показ в таблице спецификации заголовков разделов и пустых строк. Если значение свойства - FALSE, объекты показываются в таблице спецификации непрерывным списком. При этом порядок их сортировки сохраняется (в том числе учитывается принадлежность объектов к разным разделам). На отображение резервных строк значение этого свойства не влияет.

Подразделы:

(отсутствуют)
