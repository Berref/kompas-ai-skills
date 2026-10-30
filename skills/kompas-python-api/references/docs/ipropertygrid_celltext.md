# CellText - Текст в ячейке

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyGrid ](ipropertygrid.html) > [IPropertyGrid - свойства ](ipropertygrid_props.html) |  Scroll [ [ [ ](ipropertygrid_columncount.html "К следующему разделу")](ipropertygrid_props.html "На уровень выше")](ipropertygrid_cellformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertygrid.html)

Тип данных: строка

Синтаксис Automation:

cllText = iObject.CellText (nRow, nCol) | Получить свойство ([* ](1.html))  
---|---  
iObject.CellText (nRow, nCol ) = CellText | Установить свойство ([* ](1.html))  
CellText = iObject.GetCellText (nRow, nCol) | Получить свойство([**](2.html))  
iObject.SetCellText (nRow, nCol, CellText) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CellText (nRow, nCol, &CellText) | Получить свойство  
---|---  
iObject->put_CellText (nRow, nCol, CellText) | Установить свойство  
  
Входные параметры:

nRow (long) | \- индекс строки,  
---|---  
nCol (long) | \- индекс колонки.  
  
Значение свойства:

Текст в ячейке. |   
---|---  
  
Примечание:

Позволяет получить/установить текст в ячейке.

Подразделы:

(отсутствуют)
