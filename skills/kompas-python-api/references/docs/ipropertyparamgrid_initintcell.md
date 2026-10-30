# InitIntCell - Инициализация целочисленной ячейки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initiconscombocell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initcolorcell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitIntCell( long NRow, long NCol, long Value, long SpinValue, long MinValue, long MaxValue );

Синтаксис COM:

HRESULT InitIntCell( long NRow, long NCol, long Value, long SpinValue, long MinValue, long MaxValue, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
Value | \- значение,  
SpinValue | \- шаг изменения значения,  
MinValue | \- минимальное значение,  
MaxValue | \- максимальное значение.  
  
Подразделы:

(отсутствуют)
