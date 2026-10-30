# Cell - Значение в ячейке таблицы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITable ](itable.html) > [ITable - свойства ](itable_props.html) |  Scroll [ [ [ ](itable_cellbyid.html "К следующему разделу")](itable_props.html "На уровень выше")](itable_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itable.html)

Тип данных: указатель на интерфейс [ITableCell](itablecell.html)

Синтаксис Automation:

Cell = Object.Cell (RowN, ColN)  | Получить свойство([* ](1.html))  
---|---  
Cell = Object.GetCell (RowN, ColN) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Cell (RowN, ColN, &Cell ) | Получить свойство  
---|---  
  
Входные параметры:

RowN | \- номер строки,  
---|---  
ColN | \- номер колонки.   
  
Примечание:

1\. Свойство позволяет получить интерфейс ячейки таблицы.

2\. Свойство доступно только для чтения.

3\. Для допуска формы возвращается интерфейс [ITextLine](itextline.html).

Подразделы:

(отсутствуют)
