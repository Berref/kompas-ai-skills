# DeleteColumn - Удалить колонку из таблицы переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](ivariabletable_deleterow.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

BOOL DeleteColumn (VARIANT Column);

Синтаксис COM:

HRESULT DeleteColumn (VARIANT Column, VARIANT_BOOL * result);

Входные параметры:

Column | \- индекс колонки типа long или имя переменной типа BSTR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод доступен только для верхнего компонента.

Подразделы:

(отсутствуют)
