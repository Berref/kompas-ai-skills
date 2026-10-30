# CellValue - Значение в ячейке

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - свойства](ipropertyparamgrid_propers.html) |  Scroll [ [ [ ](ipropertyparamgrid_cellvaluevisible.html "К следующему разделу")](ipropertyparamgrid_propers.html "На уровень выше")](ipropertyparamgrid_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Тип данных: VARIANT

Синтаксис Automation:

CellValue = Object.CellValue( NRow, NCol ) | Получить свойство ([* ](1.html))  
---|---  
Object.CellValue( NRow, NCol ) = CellValue | Установить свойство ([* ](1.html))  
CellValue = Object.GetCellValue( NRow, NCol ) | Получить свойство([**](2.html))  
Object.SetCellValue( NRow, NCol, CellValue ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CellValue( NRow, NCol, &CellValue ) | Получить свойство  
---|---  
Object.put_CellValue( NRow, NCol, CellValue ) | Установить свойство  
  
Входные параметры:

long NRow | \- номер строки,  
---|---  
long NCol | \- номер столбца.  
  
Подразделы:

(отсутствуют)
