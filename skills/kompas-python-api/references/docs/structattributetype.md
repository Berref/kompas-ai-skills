# AttributeType - Структура параметров типа табличного атрибута

[Структуры параметров и константы](3d_define.html) > [Структуры параметров атрибутов ](bk1733500.html) |  Scroll [ [ [ ](structksattributetype.html "К следующему разделу")](bk1733500.html "На уровень выше")](structksattributew.html "К предыдущему разделу")  
---|---  
  
char | header [80] | заголовoк-комментарий типа,  
---|---|---  
unsigned int | rowsCount | количество строк в таблице,  
unsigned char | flagVisible | флаг видимости атрибута в таблице: (0 - невидимый, 1 - видимый),  
char | password[10] | пароль, если не пустая строка - защищает от несанкционированного изменения типа,  
reference | columns | массив неопределенной длины информации о столбцах.  
  
Примечания:

1\. Эта структура и использующая ее функция [CreateAttrType](createattrtype.html) устарели. Рекомендуется вместо них использовать структуру [ksAttributeType](structksattributetype.html) и функцию [ksCreateAttrType](kscreateattrtype.html).

2\. Массив columns содержит структуры параметров столбцов [ColumnInfo.](structcolumninfo.html)

Подразделы:

(отсутствуют)
