# ksRChar - Определить в отношении строковое поле

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksrcharw.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksopentextfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [RChar](rchar.html).

Синтаксис Automation:

long ksRChar (BSTR name,

long size,

long type);

Входные параметры:

name | \- имя колонки таблицы,  
---|---  
size | \- размер буфера,  
type | \- тип данных, хранящихся в БД (действительно для ODBC-баз).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Параметр name действителен при работе с текстовой базой данных.

Параметр type имеет смысл только для баз данных, связанных через ODBC, и описывает действительный тип колонки базы данных, с которой будет связано поле при выполнении операции [ksDataBaseObject::ksDoStatement](ksdatabaseobject_ksdostatement.html). Это позволяет получать строковое представление записи произвольного типа. Описания типов для ODBC хранятся в файле SQL.h, который поставляется вместе с модулями ODBC.

Подразделы:

(отсутствуют)
