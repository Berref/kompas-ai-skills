# ksGetColumnName - Считать имя колонки таблицы из базы данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksgettablename.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksfreestatement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [GetColumnName](getcolumnname.html).

Синтаксис Automation:

BSTR ksGetColumnName (long db,

BSTR tableName,

long* res,

BSTR firstOrNext);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
tableName | \- ODBC - имя таблицы, текстовая БД - имя файла,  
firstOrNext | \- признак колонки: F - первая колонка, N - следующая колонка.  
  
Выходной параметр:

res | \- результат работы: 1 - если в указанной таблице или базе еще существуют несчитанные имена колонок, 0 - если все имена колонок считаны.  
---|---  
  
Возвращаемое значение:

| имя колонки.  
---|---  
  
Примечание:

Для текстовых БД возвращаются номера колонок.

Подразделы:

(отсутствуют)
