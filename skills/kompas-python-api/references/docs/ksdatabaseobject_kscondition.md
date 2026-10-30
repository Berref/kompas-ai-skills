# ksCondition - Задать или изменить условие запроса

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksconnectdb.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksclosetextfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [Condition](condition.html).

Синтаксис Automation:

long ksCondition (long db,

long r,

BSTR stSQL);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
r | \- указатель на отношение,  
stSQL | \- запрос.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

При работе с базой данных через ODBC-интерфейс происходит переопределение составляющей SQL-запроса, начинающейся с ключевого слова WHERE. Состав обрабатываемых полей записи, определенный в отношении, не изменяется.

При работе с текстовыми файлами использование функции [ksDataBaseObject::ksCondition](ksdatabaseobject_kscondition.html) является единственной возможностью определения условия запроса, так как в функции [ksDataBaseObject::ksDoStatement](ksdatabaseobject_ksdostatement.html) определяется только список обрабатываемых полей записи.

Следует отметить, что при работе с текстовыми базами данных не обрабатывается вложенность условий (например, "where d > 10 and d < 14").

Подразделы:

(отсутствуют)
