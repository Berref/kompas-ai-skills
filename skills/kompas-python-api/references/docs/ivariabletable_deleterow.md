# DeleteRow - Удалить строку из таблицы переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](ivariabletable_findcolumnindex.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_deletecolumn.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

BOOL DeleteRow (VARIANT Row);

Синтаксис COM:

HRESULT DeleteRow (VARIANT Row, VARIANT_BOOL * result);

Входные параметры:

Row | \- индекс строки типа long или комментарий типа BSTR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод доступен только для верхнего компонента.

Подразделы:

(отсутствуют)
