# DisconnectDB - Отсоединить блок заголовка от базы данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](dostatement.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](deletedb.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_rab_s_bases_example.html)

Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksDisconnectDB](ksdatabaseobject_ksdisconnectdb.html).

Синтаксис:

int DisconnectDB(reference bd);

Входной параметр:

bd | \- указатель на блок заголовка, созданный при помощи функции [CreateDB](createdb.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

При удалении блока заголовка (функция [DeleteDB](deletedb.html)) отсоединение выполняется автоматически, поэтому использовать ее рекомендуется только при переопределении базы данных.

Подразделы:

(отсутствуют)
