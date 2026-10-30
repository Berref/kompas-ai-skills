# InitStringCell - Инициализация строковой ячейки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initstringcombocell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initrealcombocell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitStringCell( long NRow, long NCol, BSTR Text );

Синтаксис COM:

HRESULT InitStringCell( long NRow, long NCol, BSTR Text, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер колонки,  
Text | \- текст.  
  
Подразделы:

(отсутствуют)
