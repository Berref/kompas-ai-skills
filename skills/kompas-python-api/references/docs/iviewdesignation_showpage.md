# ShowPage - Показывать лист

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IViewDesignation ](iviewdesignation.html) > [IViewDesignation - свойства ](iviewdesignation_props.html) |  Scroll [ [ [ ](iviewdesignation_showscale.html "К следующему разделу")](iviewdesignation_props.html "На уровень выше")](iviewdesignation_showname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviewdesignation.html)

Тип данных: BOOL

Синтаксис Automation:

ShowPage = iObject.ShowPage | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowPage = ShowPage | Установить свойство ([* ](1.html))  
ShowPage = iObject.GetShowPage() | Получить свойство ([**](2.html))  
iObject.SetShowPage (ShowPage) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowPage (&ShowPage) | Получить свойство  
---|---  
iObject->put_ShowPage (ShowPage) | Установить свойство  
  
Примечание:

Если свойство возвращает TRUE, в обозначении вида включается номер листа.

Если FALSE, номер листа из обозначения выключается.

Подразделы:

(отсутствуют)
