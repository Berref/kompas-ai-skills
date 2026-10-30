# ShowTurn - Показывать "Повернуто"

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IViewDesignation ](iviewdesignation.html) > [IViewDesignation - свойства ](iviewdesignation_props.html) |  Scroll [ [ [ ](iviewdesignation_showunfold.html "К следующему разделу")](iviewdesignation_props.html "На уровень выше")](iviewdesignation_showscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviewdesignation.html)

Тип данных: BOOL

Синтаксис Automation:

ShowTurn = iObject.ShowTurn | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowTurn = ShowTurn | Установить свойство ([* ](1.html))  
ShowTurn = iObject.GetShowTurn() | Получить свойство ([**](2.html))  
iObject.SetShowTurn (ShowTurn) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowTurn (&ShowTurn) | Получить свойство  
---|---  
iObject->put_ShowTurn (ShowTurn) | Установить свойство  
  
Примечание:

Если свойство возвращает TRUE, в Обозначении вида включается спецзнак "Повернуто".

Если FALSE, спецзнак "Повернуто" из обозначения выключается.

Подразделы:

(отсутствуют)
