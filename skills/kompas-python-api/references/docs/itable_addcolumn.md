# AddColumn - Добавить колонку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITable ](itable.html) > [ITable - методы ](itable_methods.html) |  Scroll [ [ [ ](itable_addrow.html "К следующему разделу")](itable_methods.html "На уровень выше")](itable_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itable.html)

Синтаксис Automation:

BOOL AddColumn( long ColN,

BOOL right );

Синтаксис COM:

HRESULT AddColumn( long ColN,

BOOL right,

BOOL * PVal );

Входные параметры:

ColN | \- номер столбца, относительно которого нужно вставить новый столбец,  
---|---  
right | \- справа (TRUE) или слева (FALSE) от указанного.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет добавить в таблицу столбец справа или слева от указанного.

Подразделы:

(отсутствуют)
