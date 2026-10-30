# InitIconsComboCell - Инициализация ячейки со списком значений c иконками

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initintcombocell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initintcell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitIconsComboCell( long NRow, long NCol, long CurrentValueIndex, VARIANT OptionsList, VARIANT OptionsIcons, VARIANT OptionsIconFonts );

Синтаксис COM:

HRESULT InitIconsComboCell( long NRow, long NCol, long CurrentValueIndex, VARIANT OptionsList, VARIANT OptionsIcons, VARIANT OptionsIconFonts, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
CurrentValueIndex | \- индекс текущего значения,  
OptionsList | \- список значений,  
OptionsIcons | \- список иконок,  
OptionsIconFonts | \- список шрифтов.  
  
Подразделы:

(отсутствуют)
