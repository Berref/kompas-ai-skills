# InitColumnIcon - Инициализация колонки с иконкой

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initcolorcell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initcolumn.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitColumnIcon( long Index, long Icon, BSTR IconFont );

Синтаксис COM:

HRESULT InitColumnIcon( long Index, long Icon, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс колонки,  
---|---  
Icon | \- идентификатор иконки из шрифта,  
IconFont | \- шрифт.  
  
Подразделы:

(отсутствуют)
