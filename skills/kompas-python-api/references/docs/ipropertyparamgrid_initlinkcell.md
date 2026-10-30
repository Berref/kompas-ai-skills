# InitLinkCell - Инициализация ячейки со ссылкой

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initmarkingcell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initintcombocell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitLinkCell( long NRow, long NCol, BSTR Value );

Синтаксис COM:

HRESULT InitLinkCell( long NRow, long NCol, BSTR Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
Value | \- значение.  
  
Подразделы:

(отсутствуют)
