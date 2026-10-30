# GetColumnName - Считать имя колонки таблицы из базы данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](getcolumnnamew.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](freestatement.html "К предыдущему разделу")  
---|---  
  
[Пример...](gettablecolumnname_example.html)

Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksGetColumnName](ksdatabaseobject_ksgetcolumnname.html).

Синтаксис:

int GetColumnName (reference db,

char * tableName,

char * columnName,

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
  
Примечание.

При использовании Unicode следует использовать функцию [GetColumnNameW](getcolumnnamew.html).

Подразделы:

(отсутствуют)
