# FindColumnIndex - Найти индекс колонки по имени переменной

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](iintervalvariable.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_deleterow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

long FindColumnIndex (LPCTSTR val);

Синтаксис COM:

HRESULT FindColumnIndex ([in] BSTR Val, [out, retval] long * PVal);

Входные параметры:

val | \- имя переменной.  
---|---  
  
Возвращаемое значение:

Индекс колонки | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
