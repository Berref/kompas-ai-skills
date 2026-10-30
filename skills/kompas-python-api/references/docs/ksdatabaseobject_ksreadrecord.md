# ksReadRecord - Получить запись базы данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksreadstrfrfile.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksrdouble.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [ReadRecord](readrecord.html).

Синтаксис Automation:

long ksReadRecord (long db,

long r,

LPDISPATCH userPars);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
r | \- указатель на отношение,  
userPars | \- указатель на интерфейс [ksUserParam](ksuserparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Количество и типы полей в структуре userPars должны соответствовать отношению r.

Подразделы:

(отсутствуют)
