# CellFormat - Формат вывода текста в ячейке

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyGrid ](ipropertygrid.html) > [IPropertyGrid - свойства ](ipropertygrid_props.html) |  Scroll [ [ [ ](ipropertygrid_celltext.html "К следующему разделу")](ipropertygrid_props.html "На уровень выше")](ipropertygrid_autosizecolumns.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertygrid.html)

Тип данных: long

Синтаксис Automation:

CellFormat = iObject.CellFormat (nRow, nCol) | Получить свойство ([* ](1.html))  
---|---  
iObject.CellFormat (nRow, nCol) = CellFormat | Установить свойство ([* ](1.html))  
CellFormat = iObject.GetCellFormat (nRow, nCol) | Получить свойство([**](2.html))  
iObject.SetCellFormat (nRow, nCol, CellFormat) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CellFormat (nRow, nCol, &CellFormat) | Получить свойство  
---|---  
iObject->put_CellFormat (nRow, nCol, CellFormat) | Установить свойство  
  
Входные параметры:

nRow (long) | \- индекс строки,  
---|---  
nCol (long) | \- индекс колонки.  
  
Значение свойства:

формат вывода текста в ячейке. |   
---|---  
  
Примечание:

Формат вывода текста в ячейке задается стандартными значениями, используемыми в методе DrawText ОС Windows.

Подразделы:

(отсутствуют)
