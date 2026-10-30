# ShowName - Показывать наименование

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IViewDesignation ](iviewdesignation.html) > [IViewDesignation - свойства ](iviewdesignation_props.html) |  Scroll [ [ [ ](iviewdesignation_showpage.html "К следующему разделу")](iviewdesignation_props.html "На уровень выше")](iviewdesignation_showangle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviewdesignation.html)

Тип данных: BOOL

Синтаксис Automation:

ShowName = iObject.ShowName | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowName = ShowName | Установить свойство ([* ](1.html))  
ShowName = iObject.GetShowName() | Получить свойство ([**](2.html))  
iObject.SetShowName (ShowName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowName(&ShowName) | Получить свойство  
---|---  
iObject->put_ShowName(ShowName) | Установить свойство  
  
Примечание:

Если свойство возвращает TRUE, в обозначении вида включается наименование из ссылки на объект например (A-A).

Если FALSE, наименование из обозначения выключается.

Подразделы:

(отсутствуют)
