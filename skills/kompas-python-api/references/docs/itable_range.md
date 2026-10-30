# Range - Интерфейс для групповых операций над колонками

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITable ](itable.html) > [ITable - свойства ](itable_props.html) |  Scroll [ [ [ ](itable_rowscount.html "К следующему разделу")](itable_props.html "На уровень выше")](itable_columnscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itable.html)

Тип данных: указатель на интерфейс [ITableRange](itablerange.html)

Синтаксис Automation:

Cell = Object.Range( BeginRow, BeginColumn EndRow, EndColumn ) | Получить свойство([* ](1.html))  
---|---  
Cell = Object.Range( BeginRow, BeginColumn EndRow, EndColumn ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Range( BeginRow, BeginColumn, EndRow, EndColumn, &Range ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить интерфейс для групповых операций над ячейками таблицы.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
