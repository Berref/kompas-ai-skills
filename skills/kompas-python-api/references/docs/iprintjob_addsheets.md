# AddSheets - Добавить листы указанного документа

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_clear.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL AddSheets( BSTR FileName,

VARIANT Sheets,

long Range );

Синтаксис COM:

HRESULT AddSheets( BSTR FileName,

VARIANT Sheets,

ksSheetsRangeEnum Range,

BOOL * Result );

Входные параметры:

FileName | \- имя файла, из которого надо добавить листы,  
---|---  
Sheets | \- массив VT_ARRAY | VT_DISPATCH листов документа,  
Range | \- тип диапазона страниц из перечисления [ksSheetsRangeEnum](kssheetsrangeenum.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет добавить в задание на печать листы указанного документа.

2\. Если вместо имени файла передается пустая строка, то добавляются листы активного документа.

Подразделы:

(отсутствуют)
