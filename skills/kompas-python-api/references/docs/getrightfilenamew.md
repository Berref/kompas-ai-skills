# GetRightFileNameW - Получить действительное имя файла (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksselectd3model.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](getrightfilename.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

unsigned int LIB_FUNC GetRightFileNameW (LPWSTR fileName, unsigned int sizeBuf);

Входные параметры:

fileName | \- буфер для имени файла,  
---|---  
sizeBuf | \- размер буфера для имени файла.  
  
Возвращаемое значение:

длина имени файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [GetRightFileName](getrightfilename.html).

Подразделы:

(отсутствуют)
