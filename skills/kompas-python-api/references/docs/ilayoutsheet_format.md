# Format - Формат листа

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheet ](ilayoutsheet.html) > [ILayoutSheet - свойства ](ilayoutsheet_props.html) |  Scroll [ [ [ ](ilayoutsheet_layoutlibraryfilename.html "К следующему разделу")](ilayoutsheet_props.html "На уровень выше")](ilayoutsheet_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheet.html)

Тип данных: указатель на интерфейс [ISheetFormat](isheetformat.html) формата листа оформления

Синтаксис Automation:

Format = iObject.Format | Получить свойство([* ](1.html))  
---|---  
Format = iObject.GetFormat() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Format (&Format) | Получить свойство  
---|---  
  
Примечание:

1\. Данное свойство определяет формат листа оформления. После изменения значений свойств формата листа оформления, для того чтобы изменения вступили в силу, надо вызвать метод [Update](ilayoutsheet_update.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
