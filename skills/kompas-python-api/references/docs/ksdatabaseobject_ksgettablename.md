# ksGetTableName - Считать имя таблицы

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksisodbcokey.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksgetcolumnname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [GetTableName](gettablename.html).

Синтаксис Automation:

BSTR ksGetTableName (long db,

long* res,

BSTR firstOrNext);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
firstOrNext | \- признак таблицы: F - первая таблица, N - следующая таблица.  
  
Выходной параметр:

res | \- результат работы: 1- если в указанной базе еще существуют несчитанные имена таблиц, 0 - если все имена таблиц считаны.  
---|---  
  
Возвращаемое значение:

| имя таблицы.  
---|---  
  
Подразделы:

(отсутствуют)
