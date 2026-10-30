# ksFreeStatement - Освободить отношения

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksgetcolumnname.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksendrelation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Аналог данного метода при использовании API экспортных функций - [FreeStatement](freestatement.html).

Синтаксис Automation:

long ksFreeStatement (long db, long r, long fOption);

Входные параметры:

db | \- указатель на объект БД,  
---|---  
r | \- указатель на отношение,  
fOption | \- тип освобождения.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Происходит освобождение памяти, отведенной для буфера записи функцией [ksDataBaseObject::ksRelation](ksdatabaseobject_ksrelation.html).

Параметр fOption имеет значение при работе через ODBC-интерфейс и означает тип освобождения (описан в помощи модуля ODBC).

Подразделы:

(отсутствуют)
