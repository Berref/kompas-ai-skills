# ApplyVars - Применить параметры строки к компоненту

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - методы ](ivariabletable_methods.html) |  Scroll [ [ [ ](ivariabletable_clear.html "К следующему разделу")](ivariabletable_methods.html "На уровень выше")](ivariabletable_addrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Синтаксис Automation:

BOOL ApplyVars (VARIANT index);

Синтаксис COM:

HRESULT ApplyVars (VARIANT index, VARIANT_BOOL * result);

Входные параметры:

index | \- индекс строки типа long или комментарий к строке типа BSTR.  
---|---  
  
Возвращаемое значение:

TRUE | \- значения параметров из заданной строки успешно применены к компоненту,  
---|---  
FALSE | \- значения параметров из заданной строки не применены к компоненту.  
  
Примечание:

Метод доступен только для верхнего компонента.

Подразделы:

(отсутствуют)
