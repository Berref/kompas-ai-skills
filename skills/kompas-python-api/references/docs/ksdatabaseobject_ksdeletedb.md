# ksDeleteDB - Удалить блок заголовка базы данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksdisconnectdb.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_kscreatedb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [DeleteDB](deletedb.html).

Синтаксис Automation:

long ksDeleteDB(long db);

Входной параметр:

db | \- указатель на объект БД.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Происходит автоматическое отсоединение базы данных и удаление всех созданных ранее запросов.

Подразделы:

(отсутствуют)
