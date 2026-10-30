# ReadStrFromTextFileW - Считать строку из текстового файла запросов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с базами данных ](db_obj_fncts_common.html) |  Scroll [ [ [ ](dyn_massive_fncts_common.html "К следующему разделу")](db_obj_fncts_common.html "На уровень выше")](readstrfromtextfile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDataBaseObject::ksReadStrFrFile](ksdatabaseobject_ksreadstrfrfile.html).

Синтаксис:

int LODBC_FUNC ReadStrFromTextFileW (reference f, LPWSTR buff, int numb);

Входные параметры:

f | \- указатель на текстовый файл,  
---|---  
numb | \- номер строки.  
  
Выходной параметр:

buff | \- результат работы метода.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Строка обращения к базе данных начинается с номера, далее после двоеточия идет текст обращения, например:

3:select d,f from Table1 where d=10 and f>d

2\. При использовании ANSI следует использовать функцию [ReadStrFromTextFile](readstrfromtextfile.html).

Подразделы:

(отсутствуют)
