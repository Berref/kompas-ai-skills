# GetTableNameW - Считать имя таблицы из базы данных (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](isodbcokey.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](gettablename.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksGetTableName](ksdatabaseobject_ksgettablename.html).

Синтаксис:

int LODBC_FUNC GetTableName (reference db,

LPWSTR tableName,

int size,

unsigned char firstOrNext);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
firstOrNext | \- признак таблицы: F - первая таблица, N - следующая таблица,  
size | \- размер буфера.  
  
Выходной параметр:

tableName | \- имя таблицы.  
---|---  
  
Возвращаемое значение:

1 | \- если в указанной базе еще существуют несчитанные имена таблиц,  
---|---  
0 | \- если все имена таблиц считаны.  
  
Примечание.

При использовании ANSI следует использовать функцию [GetTableName](gettablename.html).

Подразделы:

(отсутствуют)
