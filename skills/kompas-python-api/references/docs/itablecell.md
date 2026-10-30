# Интерфейс ITableCell

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) |  Scroll [ [ [ ](itablecell_props.html "К следующему разделу")](bb3106514.html "На уровень выше")](icellboundaries_linevisible.html "К предыдущему разделу")  
---|---  
  
Интерфейс для работы c таблицами.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[ITableCell](itablecell.html)

[ICellFormat](icellformat.html)

[ICellBoundaries](icellboundaries.html)

Описание:

1\. Интерфейс можно получить с помощью метода интерфейса сетки таблицы [ITable::Cell](itable_cell.html) или свойства [ITable::CellById](itable_cellbyid.html).

2\. Для ячейки таблицы 2D документа посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить следующие дополнительные интерфейсы:

•[ICellFormat](icellformat.html) \- формат ячейки,

•[ICellBoundaries](icellboundaries.html) \- границы ячейки.

3\. Для ячейки таблицы допуска формы интерфейсы ICellFormat и ICellBoundaries не поддерживаются.

Подразделы:

[ITableCell - свойства ](itablecell_props.html)
