# CellById - Значение в ячейке таблицы, заданное по идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITable ](itable.html) > [ITable - свойства ](itable_props.html) |  Scroll [ [ [ ](itable_columnscount.html "К следующему разделу")](itable_props.html "На уровень выше")](itable_cell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itable.html)

Тип данных: указатель на интерфейс [ITableCell](itablecell.html)

Синтаксис Automation:

CellById = Object.CellById( CellID ) | Получить свойство([* ](1.html))  
---|---  
CellById = Object.GetCellById( CellID ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CellById( CellID, &CellById ) | Получить свойство  
---|---  
  
Входные параметры:

CellID | \- Идентификатор ячейки.  
---|---  
  
Примечание:

1\. Свойство позволяет получить интерфейс ячейки таблицы.

2\. Свойство доступно только для чтения.

3\. Идентификаторы ячеек задаются, начиная с 1.

Подразделы:

(отсутствуют)
