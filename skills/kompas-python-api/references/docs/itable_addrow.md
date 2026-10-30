# AddRow - Добавить строку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITable ](itable.html) > [ITable - методы ](itable_methods.html) |  Scroll [ [ [ ](itable_clear.html "К следующему разделу")](itable_methods.html "На уровень выше")](itable_addcolumn.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itable.html)

Синтаксис Automation:

BOOL AddRow( long RowN, BOOL down );

Синтаксис COM:

HRESULT AddRow( long RowN, BOOL down, BOOL * PVal );

Входные параметры:

RowN | \- номер строки, относительно которой нужно вставить новую строку,  
---|---  
down | \- снизу (TRUE) или сверху (FALSE) от указанной.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
