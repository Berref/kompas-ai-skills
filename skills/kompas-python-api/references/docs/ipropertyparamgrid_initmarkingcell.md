# InitMarkingCell - Инициализация ячейки "обозначение"

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyParamGrid](ipropertyparamgrid.html) > [IPropertyParamGrid - методы](ipropertyparamgrid_methods.html) |  Scroll [ [ [ ](ipropertyparamgrid_initrealcell.html "К следующему разделу")](ipropertyparamgrid_methods.html "На уровень выше")](ipropertyparamgrid_initlinkcell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyparamgrid.html)

Синтаксис Automation:

BOOL InitMarkingCell( long NRow, long NCol, BSTR Marking, BOOL AdditionalNumberVisibility, BOOL DocCodeVisibility );

Синтаксис COM:

RESULT InitMarkingCell( long NRow, long NCol, BSTR Marking, BOOL AdditionalNumberVisibility, BOOL DocCodeVisibility, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NRow | \- номер строки,  
---|---  
NCol | \- номер столбца,  
Marking | \- обозначение,  
AdditionalNumberVisibility | \- видимость дополнительного номера,  
DocCodeVisibility | \- видимость кода документа.  
  
Подразделы:

(отсутствуют)
