# InitStringComboCell - Инициализация строковой ячейки со списком значений

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_groupcolumn.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initstringcell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitStringComboCell( long NRow, long NCol, BSTR Value, VARIANT OptionsList );

Синтаксис COM:

HRESULT InitStringComboCell( long NRow, long NCol, BSTR Value, VARIANT OptionsList, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
Value | \- обозначение,  
OptionsList | \- список значений.  
  
Подразделы:

(отсутствуют)
