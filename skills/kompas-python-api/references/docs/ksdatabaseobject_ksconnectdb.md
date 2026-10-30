# ksConnectDB - Связать объект БД с конкретной базой данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_kscreatedb.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_kscondition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [ConnectDB](connectdb.html).

Синтаксис Automation:

long ksConnectDB (long db,

BSTR DBName);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
DBName | \- имя БД (для ODBC - имя БД в администраторе ODBC, для текстового файла - имя файла).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
