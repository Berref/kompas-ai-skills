# GetTableName - Считать имя таблицы из базы данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](gettablenamew.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](getcolumnnamew.html "К предыдущему разделу")  
---|---  
  
[Пример...](gettablecolumnname_example.html)

Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksGetTableName](ksdatabaseobject_ksgettablename.html).

Синтаксис:

int GetTableName (reference db,

char * tableName,

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

При использовании Unicode следует использовать функцию [GetTableNameW](gettablenamew.html).

Подразделы:

(отсутствуют)
