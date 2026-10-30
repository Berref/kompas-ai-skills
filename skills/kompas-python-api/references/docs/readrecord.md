# ReadRecord - Получить запись базы данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](readstrfromtextfile.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](rlongw.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_bases_example.html)

Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksReadRecord](ksdatabaseobject_ksreadrecord.html).

Синтаксис:

int ReadRecord (reference bd, reference rel, void *v);

Входные параметры:

bd | \- указатель на объект БД,  
---|---  
rel | \- указатель на отношение,  
v | \- объем памяти для хранения одной записи.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Количество и типы полей в структуре v должны соответствовать отношению rel.

Подразделы:

(отсутствуют)
