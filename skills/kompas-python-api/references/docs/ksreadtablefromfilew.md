# ksReadTableFromFileW - Создать таблицу, используя файл таблицы *.tbl (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksrebuildtablevirtualgrid.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksreadtablefromfile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksReadTableFromFile](ksdocument2d_ksreadtablefromfile.html).

Синтаксис:

reference LIB_FUNC ksReadTableFromFile (LPWSTR tblFileName);

Выходной параметр:

tblFileName | \- полное имя файла таблицы.  
---|---  
  
Возвращаемое значение:

указатель на таблицу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksReadTableFromFile](ksreadtablefromfile.html).

Подразделы:

(отсутствуют)
