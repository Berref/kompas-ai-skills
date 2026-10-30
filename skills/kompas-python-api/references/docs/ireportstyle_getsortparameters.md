# GetSortParameters - Параметры сортировки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Таблицы отчетов ](ba1858294.html) > [Интерфейс IReportStyle ](ireportstyle.html) > [IReportStyle - методы ](ireportstyle_methods.html) |  Scroll [ [ [ ](ireportstyle_init.html "К следующему разделу")](ireportstyle_methods.html "На уровень выше")](ireportstyle_deletecolumn.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ireportstyle.html)

Синтаксис Automation:

BOOL GetSortParameters( long Level, long * ColumnNumber, ksSortTypeEnum * SortType );

Синтаксис COM:

HRESULT GetSortParameters( long Level, long * ColumnNumber, ksSortTypeEnum * SortType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Level | \- уровень сортировки.  
---|---  
  
Выходные параметры:

ColumnNumber | \- номер колонки,  
---|---  
SortType | \- тип сортировки.  
  
Подразделы:

(отсутствуют)
