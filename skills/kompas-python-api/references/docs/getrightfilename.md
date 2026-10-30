# GetRightFileName - Получить действительное имя файла

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](getrightfilenamew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](fullfilenamew.html "К предыдущему разделу")  
---|---  
  
[Пример...](fullfilename_getrightfilename_example.html)

Синтаксис:

unsigned int GetRightFileName (char *fileName, unsigned int sizeBuf);

Входные параметры:

fileName | \- буфер для имени файла,  
---|---  
sizeBuf | \- размер буфера для имени файла.  
  
Возвращаемое значение:

длина имени файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [GetRightFileNameW](getrightfilenamew.html).

Подразделы:

(отсутствуют)
