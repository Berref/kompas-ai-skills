# AddColumn - Добавить колонку в таблицу переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](ivariabletable_addrow.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

long AddColumn (LPCTSTR VarName);

Синтаксис COM:

HRESULT AddColumn (BSTR VarName, long * ColumnIndex);

Входные параметры:

VarName | \- имя добавляемой переменной.  
---|---  
  
Возвращаемое значение:

ColumnIndex - индекс добавленной колонки в таблице переменных | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

1\. Метод доступен только для верхнего компонента.

2\. Если компонент не имел таблицы переменных, она создается.

Подразделы:

(отсутствуют)
