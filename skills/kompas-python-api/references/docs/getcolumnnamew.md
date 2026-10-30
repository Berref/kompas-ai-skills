# GetColumnNameW - Считать имя колонки таблицы из базы данных (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](gettablename.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](getcolumnname.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksGetColumnName](ksdatabaseobject_ksgetcolumnname.html).

Синтаксис:

int LODBC_FUNC GetColumnName (reference db,

LPWSTR tableName,

LPWSTR columnName,

int size,

unsigned char firstOrNext);

Входные параметры:

db | \- указатель на базу данных,  
---|---  
tableName | \- ODBC - имя таблицы, текстовая БД - имя файла,  
size | \- размер буфера,  
firstOrNext | \- признак колонки: F - первая колонка, N - следующая колонка.  
  
Выходной параметр:

columnName | \- имя колонки.  
---|---  
  
Возвращаемое значение:

1 | \- если в указанной базе еще существуют несчитанные имена колонок таблиц,  
---|---  
0 | \- если все имена колонок таблиц считаны.  
  
Примечание:

При использовании ANSI следует использовать функцию [GetColumnName](getcolumnname.html).

Подразделы:

(отсутствуют)
