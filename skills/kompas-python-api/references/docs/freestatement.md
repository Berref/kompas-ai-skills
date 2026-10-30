# FreeStatement - Освободить запрос базы данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](getcolumnname.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](endrelation.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_bases_example.html)

Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksFreeStatement](ksdatabaseobject_ksfreestatement.html).

Синтаксис:

int FreeStatement (reference bd, reference rel, unsigned short int fOption);

Входные параметры:

bd | \- указатель на объект БД,  
---|---  
rel | \- указатель на отношение,  
fOption | \- тип освобождения.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Происходит освобождение памяти, отведенной для буфера записи функцией [Relation](relation.html). Параметр fOption имеет значение при работе через ODBC-интерфейс и означает тип освобождения (описан в помощи модуля ODBC).

Подразделы:

(отсутствуют)
