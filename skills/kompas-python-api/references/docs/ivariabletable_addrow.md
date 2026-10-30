# AddRow - Добавить строку в таблицу переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](ivariabletable_applyvars.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_addcolumn.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

long AddRow (LPCTSTR Comment);

Синтаксис COM:

HRESULT AddRow (BSTR Comment, long * index);

Входные параметры:

Comment | \- комментарий к добавляемой строке.  
---|---  
  
Возвращаемое значение:

index - индекс добавленной строки в таблице переменных | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

1\. Метод доступен только для верхнего компонента.

2\. Если компонент не имел таблицы переменных, она создается.

Подразделы:

(отсутствуют)
