# LayoutStyleNumber - Номер стиля оформления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheet ](ilayoutsheet.html) > [ILayoutSheet - свойства ](ilayoutsheet_props.html) |  Scroll [ [ [ ](ilayoutsheet_sheettype.html "К следующему разделу")](ilayoutsheet_props.html "На уровень выше")](ilayoutsheet_layoutlibraryfilename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheet.html)

Тип данных: double

Синтаксис Automation:

LayoutStyleNumber = iObject.LayoutStyleNumber | Получить свойство([* ](1.html))  
---|---  
iObject.LayoutStyleNumber = LayoutStyleNumber | Установить свойство ([* ](1.html))  
LayoutStyleNumber = iObject.GetLayoutStyleNumber() | Получить свойство ([**](2.html))  
iObject.SetLayoutStyleNumber (LayoutStyleNumber) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LayoutStyleNumber (&LayoutStyleNumber) | Получить свойство  
---|---  
iObject->put_LayoutStyleNumber (LayoutStyleNumber) | Установить свойство  
  
Примечание:

Данное свойство позволяет получить\изменить номер используемого стиля в библиотеке стилей оформлений (см. [LayoutLibraryFileName](ilayoutsheet_layoutlibraryfilename.html)). После изменения значений свойств формата листа оформления, для того чтобы изменения вступили в силу, надо вызвать метод [Update](ilayoutsheet_update.html).

Подразделы:

(отсутствуют)
