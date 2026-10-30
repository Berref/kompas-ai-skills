# ksDisconnectDB - Отключиться от базы данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksdostatement.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksdeletedb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [DisconnectDB](disconnectdb.html).

Синтаксис Automation:

long ksDisconnectDB (long db);

Входной параметр:

db | \- указатель на объект БД.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция отсоединяет блок заголовка с указателем bd от базы данных.

Следует отметить, что при удалении блока заголовка (функция [ksDataBaseObject::ksDeleteDB)](ksdatabaseobject_ksdeletedb.html) отсоединение выполняется автоматически, поэтому использовать ее рекомендуется только при переопределении базы данных.

Подразделы:

(отсутствуют)
