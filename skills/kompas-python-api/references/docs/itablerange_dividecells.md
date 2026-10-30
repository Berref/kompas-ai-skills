# DivideCells - Разбить ячейки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITableRange ](itablerange.html) > [ITableRange - методы ](itablerange_methods.html) |  Scroll [ [ [ ](icellformat.html "К следующему разделу")](itablerange_methods.html "На уровень выше")](itablerange_combinecells.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itablerange.html)

Синтаксис Automation:

BOOL DivideCells( long ColumnCount,

long RowCount,

BOOL PrepareCombine );

Синтаксис COM:

HRESULT DivideCells( long ColumnCount,

long RowCount,

BOOL PrepareCombine,

BOOL * PVal );

Входные параметры:

ColumnCount | \- число столбцов,  
---|---  
RowCount | \- число строк,  
PrepareCombine | \- объединить ячейки перед разбиением.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет разбить ячейки таблицы.

Подразделы:

(отсутствуют)
