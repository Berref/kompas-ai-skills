# InitIntComboCell - Инициализация целочисленной ячейки со списком значений

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initlinkcell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initiconscombocell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitIntComboCell( long NRow, long NCol, long Value, VARIANT OptionsList, BOOL Sorted );

Синтаксис COM:

HRESULT InitIntComboCell( long NRow, long NCol, long Value, VARIANT OptionsList, BOOL Sorted, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
Value | \- значение,  
OptionsList | \- список значений,  
Sorted | \- сортировать.  
  
Подразделы:

(отсутствуют)
