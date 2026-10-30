# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTables ](idrawingtables.html) > [IDrawingTables - методы ](idrawingtables_methods.html) |  Scroll [ [ [ ](idrawingtables_load.html "К следующему разделу")](idrawingtables_methods.html "На уровень выше")](idrawingtables_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingtables.html)

Синтаксис Automation:

LPDISPATCH Add( long RowsCount,

long ColumnsCount,

double RowHeigh,

double ColumnsWidth,

long titlePos);

Синтаксис COM:

HRESULT Add( long RowsCount,

long ColumnsCount,

double RowHeigh,

double ColumnsWidth,

ksTableTileLayoutEnum titlePos,

IDrawingTable ** Result);

Входные параметры:

RowsCount | \- количество строк таблицы,  
---|---  
ColumnsCount | \- количество столбцов таблицы,  
RowHeigh | \- высота строк,  
ColumnsWidth | \- ширина столбцов,  
titlePos | \- расположение заголовка таблицы.  
  
Возвращаемое значение:

| \- Указатель на интерфейс таблицы на чертеже [IDrawingTable](idrawingtable.html).  
---|---  
  
Подразделы:

(отсутствуют)
