# LayoutLibraryFileName - Имя файла библиотеки стилей оформления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheet ](ilayoutsheet.html) > [ILayoutSheet - свойства ](ilayoutsheet_props.html) |  Scroll [ [ [ ](ilayoutsheet_layoutstylenumber.html "К следующему разделу")](ilayoutsheet_props.html "На уровень выше")](ilayoutsheet_format.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheet.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

LayoutLibraryFileName = iObject.LayoutLibraryFileName | Получить свойство([* ](1.html))  
---|---  
iObject.LayoutLibraryFileName = LayoutLibraryFileName | Установить свойство ([* ](1.html))  
LayoutLibraryFileName = iObject.GetLayoutLibraryFileName() | Получить свойство ([**](2.html))  
iObject.SetLayoutLibraryFileName (LayoutLibraryFileName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LayoutLibraryFileName (&LayoutLibraryFileName) | Получить свойство  
---|---  
iObject->put_LayoutLibraryFileName (LayoutLibraryFileName) | Установить свойство  
  
Примечание:

Данное свойство позволяет получить/изменить полное имя файла библиотеки стилей оформлений, из которой взят данный стиль. После изменения значений свойств формата листа оформления, для того чтобы изменения вступили в силу, надо вызвать метод [Update](ilayoutsheet_update.html).

Подразделы:

(отсутствуют)
