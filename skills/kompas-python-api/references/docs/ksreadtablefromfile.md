# ksReadTableFromFile - Создать таблицу, используя файл таблицы *.tbl

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksreadtablefromfilew.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksopentolerance.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksreadtablefromfile_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksReadTableFromFile](ksdocument2d_ksreadtablefromfile.html).

Синтаксис:

reference ksReadTableFromFile (char * tblFileName);

Выходной параметр:

tblFileName | \- полное имя файла таблицы.  
---|---  
  
Возвращаемое значение:

указатель на таблицу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksReadTableFromFileW](ksreadtablefromfilew.html).

Подразделы:

(отсутствуют)
