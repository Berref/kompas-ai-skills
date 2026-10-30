# Add - Добавить таблицу в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Тексты ](bc3335025.html) > [Интерфейс IModelTables ](imodeltables.html) > [IModelTables - методы ](imodeltables_methods.html) |  Scroll [ [ [ ](imodeltables_load.html "К следующему разделу")](imodeltables_methods.html "На уровень выше")](imodeltables_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodeltables.html)

Синтаксис Automation:

LPDISPATCH Add( long RowsCount, long ColumnsCount, double RowHeigh, double ColumnsWidth, ksTableTileLayoutEnum TitlePos );

Синтаксис COM:

HRESULT Add( long RowsCount, long ColumnsCount, double RowHeigh, double ColumnsWidth, ksTableTileLayoutEnum TitlePos, IModelTable * * Result );

Возвращаемое значение:

| Указатель на интерфейс [IModelTable](imodeltable.html).  
---|---  
  
Входные параметры:

RowsCount | \- количество строк,  
---|---  
ColumnsCount | \- количество колонок,  
RowHeigh | \- высота ячеек,  
ColumnsWidth | \- ширина ячеек,  
TitlePos | \- положение заголовка таблицы из перечисления [ksTableTileLayoutEnum](kstabletilelayoutenum.html).  
  
Подразделы:

(отсутствуют)
