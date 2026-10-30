# InitColumn - Инициализация параметров колонки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initcolumnicon.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initcheckboxcell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitColumn( long Index, BSTR Caption, BSTR Tips, BOOL ReadOnly );

Синтаксис COM:

HRESULT InitColumn( long Index, BSTR Caption, BSTR Tips, BOOL ReadOnly, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс колонки,  
---|---  
Caption | \- заголовок,  
Tips | \- всплывающая строка,  
ReadOnly | \- признак - только чтение для ячеек в колонке.  
  
Подразделы:

(отсутствуют)
